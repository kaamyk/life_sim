#ifndef NEURAL_HPP
#define NEURAL_HPP

# include <iostream>
# include <vector>
# include <ctime>
# include <cstdlib>

#include "Level.hpp"

# define NBLEVEL    2
# define NBINPUTS   3
# define NBOUTPUTS  4

class Level
{
private:
    const uint8_t   _nbInputs;
    const uint8_t   _nbOutputs;
    std::vector<float>  _inputs;
    // std::vector<float>  _outputs;
    std::vector<float>  _biases;
    std::vector< std::vector<float> >  _weights;

public:
    Level( void );
    ~Level( void );

    std::vector<float>&  getOutputs( void );
    std::vector<float>   feedForward( std::vector<float> );
};

class NeuralNetwork
{
private:
    std::vector<float> _sensorInputs;
    std::vector<Level> levels;

public:
    NeuralNetwork( void );
    ~NeuralNetwork();

    void    copyOutput( void );
    void    feedForward( void );
};

#endif