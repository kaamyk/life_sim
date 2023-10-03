/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:39:16 by anvincen          #+#    #+#             */
/*   Updated: 2023/10/03 22:35:21 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private :
		int					_raw;
		static const int	_fractionalBits = 8;

	public :
		Fixed( void );
		Fixed( const Fixed &source );
		Fixed( float const &n);
		Fixed( int const &n );
		~Fixed( void );

		Fixed&	operator=( const Fixed& a );
		bool	operator>( const Fixed& a ) const;
		bool	operator<( const Fixed& a ) const;
		bool	operator>=( const Fixed& a );
		bool	operator<=( const Fixed& a );
		bool	operator==( const Fixed& a );
		bool	operator!=( const Fixed& a );
		Fixed	operator+( const Fixed& a );
		Fixed	operator-( const Fixed& a );
		Fixed	operator*( const Fixed& a );
		Fixed	operator/( const Fixed& a );
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		Fixed const&	min(Fixed const& a, Fixed const& b);
		Fixed const&	max(Fixed const& a, Fixed const& b);
		Fixed&	min(Fixed& a, Fixed& b);
		Fixed&	max(Fixed& a, Fixed& b);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

 std::ostream&  operator<<( std::ostream &o, const Fixed& n );

#endif
