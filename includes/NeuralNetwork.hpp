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
    NeuralNetwork( std::vector<unsigned int> neuronsVal );
    ~NeuralNetwork( void ){}

    NeuralNetwork&  operator=( NeuralNetwork const& source);

    std::vector<float>&    feedForward( std::vector<float> _sensorInputs );
};

#endif