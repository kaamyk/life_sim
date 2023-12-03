#include "../includes/NeuralNetwork.hpp"

Level::Level( uint8_t nbInputs, uint8_t nbOutputs ): _nbInputs(nbInputs). _nbOutputs(nbOutputs)
{
    for (unsigned int i = 0; i < _nbInputs; ++i){
        std::vector<float> tmp;
        for (unsigned int j = 0; j < _nbOutputs; ++j)
            tmp.push_back((rand() % 2) - 1);
        _weights.push_back(tmp);
    }
    for (unsigned int i = 0; i < _biases.size(); ++i)
        _biases[i].push_back( (((float)rand() / (float)rand()) % 2.0f) - 1.0f );
    return ;
}

Level::~Level( void )
{
    return ;
}

std::vector<float>&  Level::getOutputs( void )
{
    return (_outputs);
}

std::vector<float>&  Level::getInputs( void )
{
    return (_inputs);
}

void    Level::feedForward( std::vector<float> inputs )
{
    int sum;

    for (unsigned int i = 0; i < _outputs.size(); ++i){
        sum = 0;
        for (unsigned int j = 0; j < _inputs.size(); ++j)
            sum += _inputs[j] * _weights[i][j];
        _outputs[i] = (1 & (sum > _biases[i]));
    }
    return ;
}