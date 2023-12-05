#include "../includes/NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork( std::vector<unsigned int> neuronsVal ){
    for (unsigned int i = 0; i + 1 < neuronsVal.size(); ++i)
        _levels.emplace_back(Level(neuronsVal[i], neuronsVal[i + 1]));
}

NeuralNetwork&  NeuralNetwork::operator=( NeuralNetwork const& source){
    _levels = source._levels;
    return (*this);
}

std::vector<float>&    NeuralNetwork::feedForward( std::vector<float> _sensorInputs ){
        unsigned int i;
        
        _levels[0].feedForward(_sensorInputs);
        for(i = 1; i < _levels.size(); ++i)
            _levels[i].feedForward(_levels[i - 1].getOutputs());
        return (_levels[i].getOutputs());
    }