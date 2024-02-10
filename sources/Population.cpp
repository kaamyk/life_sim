#include "../includes/Population.hpp"

Population::Population( void ){
	for(unsigned int i = 0; i < s_data.nbCreature; i++){
		_population.push_back(new Creature());
	}
}

Population::~Population( void ){
	for (std::vector<Creature *>::iterator i = _population.begin(); i < _population.end(); i++){
		delete (*i);
	}
	_population.clear();
}


/********************************************************/
/*						CHECKERS 						*/
/********************************************************/

void	Population::checkLifeTimes( void ){
	if (_population.size() == 0)
		return;
	for(std::vector<Creature *>::iterator i = _population.begin();  !_population.empty() && i != _population.end(); ++i){
		if ((*i)->checkTime(s_data.timeToDie)){
			delete *i;
			this->_population.erase(i);
			i = _population.begin();
		}
	}
}

bool	Population::checkNbCreature( void ){
	return (_population.size() != 0);
}


/********************************************************/
/*						DRAWING 						*/
/********************************************************/

void	Population::drawPopulation( sf::RenderWindow& win ){
	for (std::vector<Creature *>::iterator i = _population.begin(); i < _population.end(); i++){
		(*i)->drawCreature(win);
	}
}

/****************************************************/
/*					NEW CREATURE					*/
/****************************************************/

void	Population::createNewCreature( void ){
	try{
		_population.push_back(new Creature());
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}

void	Population::createMutatedCreature( NeuralNetwork* brain ){
	NeuralNetwork* n_brain = new NeuralNetwork(brain);
	Creature* n_creature = new Creature(n_brain);
	
	_population.push_back(n_creature);
}


/********************************************************/
/*						MOVEMENTS 						*/
/********************************************************/

bool	Population::creatureMove( Creature* Cr, __uint8_t i, Food& food ){
	std::vector<float>	outputs = Cr->feedForward(Cr->getSensor()->getState());

	(void) i;
	// std::vector<float>	outputs;
	// switch (i){
	// 	case 0:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 1:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 2:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 3:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 4:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 5:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 6:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	case 7:
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(1.0f);
	// 		outputs.push_back(0.0f);
	// 		outputs.push_back(0.0f);
	// 		break;
	// 	default:
	// 		outputs = Cr->feedForward(Cr->getSensor()->getState());
	// 		break;
	// }


	for (__uint8_t j = 0; j < 4; ++j){
		if (outputs[j]){
			Cr->move(j);
		}
	}
	Cr->updateSensors( food );
	Cr->updatePosition();
	return (Cr->checkLastPositions());
}





void	Population::updatePopulation( Food& food ){
	checkLifeTimes();
	for (std::vector<Creature *>::iterator i = _population.begin(); i < _population.end(); i++){
		if( creatureMove(*i, std::distance(_population.begin(), i), food ) ){
			std::cout << "Creature erased" << std::endl;
			delete (*i);
			_population.erase(i);
			if (i != _population.begin()){
				--i;
			} 
		}
		else{
			Creature* nCr = (*i)->eat(food);
			if (nCr){
				_population.push_back(nCr);
			}
		}
	}
}