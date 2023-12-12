#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <iostream>
# include <array>
# include <ctime>
# include <cstdlib>
# include <math.h>

#include "Simulation.hpp"

class Level
{
private:
    unsigned int _nbInputs;
    unsigned int _nbOutputs;
    std::vector<float>     _inputs;
    std::vector<float>     _outputs;
    std::vector<float>    _biases;
    std::vector< std::vector<float> >  _weights;

public:
    Level( unsigned int nbInputs, unsigned int nbOutputs ):
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
            _biases.push_back(remainder((float)(rand()) / (float)(rand()), (2.0f)) - 1.0f);
        }
        return ;
    }
    Level( Level const& source){*this = source;}
    ~Level( void ){}

    Level&  operator=( Level const& source){
        _nbInputs = source._nbInputs;
        _nbOutputs = source._nbOutputs;
        _inputs = source._inputs;
        _outputs = source._outputs;
        _biases = source._biases;
        _weights = source._weights;
        return (*this);
    }

    std::vector<float>&  getInputs( void ){return (_inputs);}
    std::vector<float>&  getOutputs( void ){return (_outputs);}

    void   feedForward( std::vector<float> inputs );
    void    mutate( unsigned int amount );
};

#endif