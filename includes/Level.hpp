#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <iostream>
# include <array>
# include <ctime>
# include <cstdlib>

class Level
{
private:
    std::array<float, NBINPUTS>     _inputs;
    std::array<float, NBOUTPUTS>    _outputs;
    std::array<float, NBOUTPUTS>    _biases;
    std::array<std::array<float, NBOUTPUTS>, NBINPUTS>  _weights;

public:
    Level( void );
    ~Level( void );

    const std::array<float, NBINPUTS>&  getOutputs( void );
}

#endif