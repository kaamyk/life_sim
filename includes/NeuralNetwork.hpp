#ifndef NEURAL_HPP
#define NEURAL_HPP

# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>

#include "Simulation.hpp"

class   Level;

class NeuralNetwork
{
private:
    std::vector<float> _sensorInputs;
    std::vector<Level> _levels;

public:
    NeuralNetwork( std::vector<unsigned int> neuronsVal ){
        for (uint8_t i = 0; i < neuronsVal.size() - 1; ++i)
            _levels.emplace_back(new Level(neuronsVal[i], neuronsVal[i + 1]));
    }
    ~NeuralNetwork( void ){}

    NeuralNetwork&  operator=( NeuralNetwork const& source){
        _levels = source._levels;
        return (*this);
    }


    std::vector<float>&    NeuralNetwork::feedForward( std::vector<float> _sensorInputs ){
        std::vector<float>    outputs = Level::feedForward(_sensorInputs);
        
        for(unsigned int i = 0; i < NBLEVEL; ++i)
            outputs = _levels[i].feedForward(outputs);
        return (outputs);
    }
};

#endif