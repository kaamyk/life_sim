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
    std::vector<float>  _inputs;
    std::vector<float>  _outputs;
    std::vector<float>  _biases;
    std::vector< std::vector<float> >  _weights;

public:
    Level( unsigned int nbInputs, unsigned int nbOutputs );
    Level( Level const& source);
    ~Level( void ){}

    Level&  operator=( Level const& source );

    class WrongCopySource: std::exception{
        public:
            const char* what( void ) const throw(){
                return ("Error: Level operator=: members not compatible.");
            }
    };

    std::vector<float>&  getInputs( void );
    std::vector<float>&  getOutputs( void );
    std::vector<float>&  getBiases( void );

    void   feedForward( std::vector<float> inputs );
    void    mutate( float amount );
};

#endif