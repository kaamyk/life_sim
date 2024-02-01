#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <chrono>

struct s_data {
	const unsigned int	windowLength = 1920;
	const unsigned int	windowHeight = 1080;
	const unsigned int	creatureSize = 20;
	const unsigned int	foodSize = 15;
	const unsigned int	nbCreature = 8;
	const unsigned int	nbFood = 60;
	const std::chrono::seconds	timeToDie = std::chrono::seconds(40);
};

#endif