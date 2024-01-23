#include "../includes/Level.hpp"

Level::Level( unsigned int nbInputs, unsigned int nbOutputs ):
                                _nbInputs(nbInputs), _nbOutputs(nbOutputs)
{
    for (unsigned int i = 0; i < _nbInputs; ++i){
        std::vector<float> tmp;
        for (unsigned int j = 0; j < _nbOutputs; ++j){
            tmp.push_back((rand() % 2) - 1);
        }
        _weights.emplace_back(std::vector<float>(tmp));
        tmp.clear();
    }
    for (unsigned int i = 0; i < _nbOutputs; ++i){
        _biases.push_back(remainder( static_cast<float>(rand()) / static_cast<float>(rand()), 2.0f) - 1.0f);
    }
    return ;
}

Level::Level( Level const& source ){
    *this = source;
}

Level&  Level::operator=( Level const& source ){
    // if (this->_nbInputs != source._nbInputs || this->_nbOutputs != source._nbOutputs){
    //     throw WrongCopySource();
    // }
    _nbInputs = source._nbInputs;
    _nbOutputs = source._nbOutputs;
    _inputs = source._inputs;
    for (size_t i = 0; i < source._inputs.size(); ++i){
        this->_inputs[i] = source._inputs[i];
    }
    _outputs = source._outputs;
    for (size_t i = 0; i < source._outputs.size(); ++i){
        this->_outputs[i] = source._outputs[i];
    }
    _biases = source._biases;
    for (size_t i = 0; i < source._biases.size(); ++i){
        this->_biases[i] = source._biases[i];
    }
    _weights = source._weights;
    for (size_t i = 0; i < source._weights.size(); ++i){
        for (size_t j = 0; j < source._weights[i].size() && j < this->_weights[i].size(); ++j){
            this->_weights[i][j] = source._weights[i][j];
        }
    }
    return (*this);
}

std::vector<float>&  Level::getInputs( void ){
    return (_inputs);
}

std::vector<float>&  Level::getOutputs( void ){
    return (_outputs);
}

std::vector<float>&  Level::getBiases( void ){
    return (_biases);
}

void   Level::feedForward( std::vector<float> inputs ){
    int sum;

    _outputs.clear();
    for (unsigned int i = 0; i < _nbOutputs; ++i){
        sum = 0;
        for (unsigned int j = 0; j < inputs.size(); ++j){
            sum += inputs[j] \
            * _weights[j][i];
        }
        _outputs.push_back(static_cast<float>(sum > _biases[i]));
    }
}

void    Level::mutate( float amount ){
    //std::cout<< "Biases :" << std::endl;
    for (std::vector<float>::iterator i = _biases.begin(); i != _biases.end(); ++i){
        *i = Simulation::lerp(*i, remainder( static_cast<float>(rand()) / static_cast<float>(rand()), (2.0f) ) - 1.0f, amount);
    }
    for (std::vector< std::vector<float> >::iterator i = _weights.begin(); i != _weights.end(); ++i){
        for (std::vector<float>::iterator j = i->begin(); j != i->end(); ++j){
            *j = Simulation::lerp(*j, remainder( static_cast<float>(rand()) / static_cast<float>(rand()), 2.0f) - 1.0f, amount);
        }
    }
}