#include "../includes/bsp.hpp"

void	ft_abs( float &N )
{
	if (N < 0)
		N = N * (-1);
	return ;
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

bool	bsp( Point const A, Point const B, Point const C, Point const P )
{
	Fixed	ABC;
	Fixed	partArea;

	partArea = getArea(A, B, P);
	partArea = partArea + getArea(A, C, P);
	partArea = partArea + getArea(B, C, P);

	ABC = getArea(A, B, C);f
	return (ABC == partArea);
}
