#include "../includes/Level.hpp"

void   Level::feedForward( std::vector<float> inputs ){
    int sum;

    for (unsigned int i = 0; i < _nbOutputs; ++i){
        sum = 0;
        for (unsigned int j = 0; j < _nbInputs; ++j){
            sum += inputs[j] * _weights[j][i];
        }
        _outputs.push_back(static_cast<float>(sum > _biases[i]));
    }
}
void    Level::mutate( float amount ){
    //std::cout<< "Biases :" << std::endl;
    for (std::vector<float>::iterator i = _biases.begin(); i != _biases.end(); ++i){
        *i = Simulation::lerp(*i, remainder( static_cast<float>(rand()) / static_cast<float>(rand()), (2.0f) ) - 1.0f, amount);
        //std::cout<< "\t" << *i << std::endl;
    }
    //std::cout<< "------------" << std::endl;
    //std::cout<< "Weights :" << std::endl;
    for (std::vector< std::vector<float> >::iterator i = _weights.begin(); i != _weights.end(); ++i){
        for (std::vector<float>::iterator j = i->begin(); j != i->end(); ++j){
            *j = Simulation::lerp(*j, remainder( static_cast<float>(rand()) / static_cast<float>(rand()), 2.0f) - 1.0f, amount);
            //std::cout<< "\t" << *j << std::endl;
        }
    }
    //std::cout<< "================" << std::endl;
}