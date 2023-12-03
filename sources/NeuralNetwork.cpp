#include "../includes/NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork( std::vector<uint8_t> neuronsVal )
{
    for (uint8_t i = 0; i < neuronsVal.size() - 1){
        levels.emplace_back(new Level(neuronsVal[i], neuronsVal[i + 1]));
    }
    return ;
}

NeuralNetwork::~NeuralNetwork( void )
{
    return ;
}

std::array&    NeuralNetwork::feedForward( void )
{
    // Level.feedForward();
    std::vector<float>    outputs = Level::feedForward(_sensorInputs);
    
    for(unsigned int i = 0; i < NBLEVEL; ++i)
        outputs = levels[i].feedForward(outputs);
    return (outputs);
}