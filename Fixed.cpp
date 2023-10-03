/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:39:16 by anvincen          #+#    #+#             */
/*   Updated: 2023/09/19 23:15:59 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

//		CONSTRUCTOR

Fixed::Fixed( void ) : _raw(0)
{
	return ;
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
	return ;
}

Fixed::Fixed( float const &f ) : _raw(roundf(f * (1 << _fractionalBits)))
{
	return ;
}

Fixed::Fixed( int const &n ) : _raw(n << _fractionalBits)
{
	return ;
}

//		DESTRUCTOR

Fixed::~Fixed( void )
{
	return ;
}

//		OPERATOR OVERLOAD

	std::ostream&	operator<<( std::ostream& o, const Fixed& n )
{
	o << n.toFloat();
	return (o);
}

Fixed& Fixed::operator=( const Fixed& a )
{
	this->_raw = a.getRawBits();
	return (*this);
}

bool	Fixed::operator>( Fixed const& a) const
{
	if (this->_raw > a.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator<( Fixed const& a) const
{
	if (this->_raw < a.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator>=( const Fixed& a)
{
	if (this->_raw >= a.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator<=( const Fixed& a)
{
	if (this->_raw <= a.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator==( const Fixed& a)
{
	if (this->_raw == a.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator!=( const Fixed& a )
{
	if (this->_raw != a.getRawBits())
		return (1);
	return (0);
}

Fixed	Fixed::operator+( const Fixed& a)
{
	return ( this->toFloat() + a.toFloat() );
}

Fixed	Fixed::operator-( const Fixed& a)
{
	return ( this->toFloat() - a.toFloat() );
}

Fixed	Fixed::operator*( const Fixed& a)
{
	return ( Fixed(this->toFloat() * a.toFloat()) );
}

Fixed	Fixed::operator/( const Fixed& a)
{
	return ( this->toFloat() / a.toFloat() );
}

Fixed &	Fixed::operator++( void )
{
	this->_raw += 1;
	return ( *this );
}

Fixed	Fixed::operator++( int )	
{
	Fixed	tmp( *this );

	this->_raw += 1;
	return ( tmp );
}

Fixed &	Fixed::operator--( void )
{
	this->_raw -= 1;
	return ( *this );
}

Fixed	Fixed::operator--( int )	
{
	Fixed	tmp( *this );

	this->_raw -= 1;
	return ( tmp );
}

//		PUBLIC FUNCTIONS

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a > b)
		return ( a );
	return ( b );
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return ( a );
	return ( b );
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return ( a );
	return ( b );
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return ( a );
	return ( b );
}

int		Fixed::getRawBits( void ) const
{
	return ( this->_raw );
}

void	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_raw / (1 << this->_fractionalBits) );
}

int		Fixed::toInt( void ) const
{
	return ( this->_raw >> Fixed::_fractionalBits );
}
