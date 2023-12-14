#include "../includes/NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork( std::vector<unsigned int> neuronCount ){
    for (unsigned int i = 0; i + 1 < neuronCount.size(); ++i)
        _levels.emplace_back(new Level(neuronCount[i], neuronCount[i + 1]));
}
NeuralNetwork::NeuralNetwork( NeuralNetwork const& brain ){
    *this = brain;
}
NeuralNetwork::~NeuralNetwork( void ){
    for (std::vector<Level*>::iterator it = _levels.begin(); it != _levels.end(); ++it){
        _levels.erase(it);
    }
}

NeuralNetwork&  NeuralNetwork::operator=( NeuralNetwork const& source){
    _levels = source._levels;
    try{
        for (size_t i = 0; i < this->_levels.size() && source._levels.size() ; ++i){
            *(this->_levels[i]) = *(source._levels[i]);
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return (*this);
}

std::vector<float>&    NeuralNetwork::feedForward( std::vector<float> sensorInputs ){
    unsigned int i;
    
    this->_levels[0]->feedForward(sensorInputs);
    for(i = 1; i < _levels.size(); ++i){
        this->_levels[i]->feedForward(_levels[i - 1]->getOutputs());
    }
    return (_levels[i - 1]->getOutputs());
}

void    NeuralNetwork::mutate( float amount ){
    for(std::vector<Level *>::iterator i = _levels.begin(); i != _levels.end(); ++i){
        (*i)->mutate(amount);
    }
}