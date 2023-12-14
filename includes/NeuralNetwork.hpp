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
    std::vector<Level*> _levels;

public:
    NeuralNetwork( std::vector<unsigned int> neuronCount );
    NeuralNetwork( NeuralNetwork const& brain );
    ~NeuralNetwork( void );

    NeuralNetwork&  operator=( NeuralNetwork const& source);

    std::vector<float>&    feedForward( std::vector<float> _sensorInputs );
    std::vector<Level *>& getLevels( void ){ return (_levels); }
    void    mutate( float amount );
};

#endif