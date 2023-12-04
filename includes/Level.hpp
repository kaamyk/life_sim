#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <iostream>
# include <array>
# include <ctime>
# include <cstdlib>

# include "Simulation.hpp"

class Level
{
private:
    unsigned int _nbInputs;
    unsigned int _nbOutputs;
    std::vector<float>     _inputs;
    std::vector<float>    _outputs;
    std::vector<float>    _biases;
    std::vector< std::vector<float> >  _weights;

public:
    Level::Level( unsigned int nbInputs, unsigned int nbOutputs ):
                                _nbInputs(nbInputs), _nbOutputs(nbOutputs)
    {
        for (unsigned int i = 0; i < _nbInputs; ++i){
            std::vector<float> tmp;
            for (unsigned int j = 0; j < _nbOutputs; ++j)
                tmp.push_back((rand() % 2) - 1);
            _weights.push_back(tmp);
            tmp.clear();
        }
        for (unsigned int i = 0; i < _nbOutputs; ++i)
            _biases.push_back((static_cast<float>(rand()) / static_cast<float>(rand()) % 2.0f) - 1.0f);
        return ;
    }
    ~Level( void ){}

    const std::vector<float>&  getInputs( void ){return (_inputs);}
    const std::vector<float>&  getOutputs( void ){return (_outputs);}

    void    Level::feedForward( std::vector<float> inputs ){
        int sum;

        for (unsigned int i = 0; i < _nbOutputs; ++i){
            sum = 0;
            for (unsigned int j = 0; j < _nbInputs; ++j)
                sum += _inputs[j] * _weights[i][j];
            _outputs[i].push_back(static_cast<float>(sum > _biases[i]));
        }
        return ;
    }
};

#endif