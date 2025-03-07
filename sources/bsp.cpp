#include "../includes/bsp.hpp"

void	ft_abs( float &N )
{
	if (N < 0)
		N = N * (-1);
}

float	getArea( sf::Vector2f P1, sf::Vector2f P2, sf::Vector2f P3 )
{
	float	tmp;

	tmp = P1.x * (P2.y - P3.y);
	tmp = tmp + (P2.x * (P3.y - P1.y));
	tmp = tmp + (P3.x * (P1.y - P2.y));
	tmp = tmp / 2;
	ft_abs(tmp);
	return ( tmp );
}

bool	bsp( sf::Vector2f CrSize, std::array<sf::Vector2f, 4>& vtx, sf::Vector2f const P ){
	int	squareArea = (static_cast<int>(CrSize.x) * static_cast<int>(CrSize.y)) * 1000;
	int	partArea = 0.0f;

	// partArea = getArea(A, B, P);
	// partArea = partArea + getArea(A, C, P);
	// partArea = partArea + getArea(B, C, P);

	for (__uint8_t i = 1; i < 4; i++){
		if (partArea > squareArea){
			return (0);
		}
		partArea += getArea(vtx[i - 1], vtx[i], P) * 1000;
	}
	partArea += getArea(vtx[3], vtx[0], P) * 1000;

	std::cout << "bsp: " << squareArea / 1000 << " X " << partArea / 1000 << std::endl;

	return (squareArea / 1000 == partArea / 1000);
}
