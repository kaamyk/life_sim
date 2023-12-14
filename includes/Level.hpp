#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <iostream>
# include <array>
# include <ctime>
# include <cstdlib>
# include <cmath>

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
            _biases.push_back(remainder( static_cast<float>(rand()) / static_cast<float>(rand()), 2.0f) - 1.0f);
        }
        return ;
    }
    Level( Level const& source){*this = source;}
    ~Level( void ){}

    Level&  operator=( Level const& source ){
        if (this->_nbInputs != source._nbInputs || this->_nbOutputs != source._nbOutputs){
            throw WrongCopySource();
        }
        _nbInputs = source._nbInputs;
        _nbOutputs = source._nbOutputs;
        _inputs = source._inputs;
        for (size_t i = 0; i < source._inputs.size() && i < this->_inputs.size() ; ++i){
            this->_inputs[i] = source._inputs[i];
        }
        _outputs = source._outputs;
        for (size_t i = 0; i < source._outputs.size() && i < this->_outputs.size() ; ++i){
            this->_outputs[i] = source._outputs[i];
        }
        _biases = source._biases;
        for (size_t i = 0; i < source._biases.size() && i < this->_biases.size() ; ++i){
            this->_biases[i] = source._biases[i];
        }
        _weights = source._weights;
        for (size_t i = 0; i < source._weights.size() && i < this->_weights.size() ; ++i){
            for (size_t j = 0; j < source._weights[i].size() && j < this->_weights[i].size(); ++j){
                this->_weights[i][j] = source._weights[i][j];
            }
        }
        return (*this);
    }

    class WrongCopySource: std::exception{
        public:
            const char* what( void ) const throw(){
                return ("Error: Level operator=: members not compatible.");
            }
    };

    std::vector<float>&  getInputs( void ){return (_inputs);}
    std::vector<float>&  getOutputs( void ){return (_outputs);}
    std::vector<float>&  getBiases( void ){return (_outputs);}

    void   feedForward( std::vector<float> inputs );
    void    mutate( float amount );
};

#endif