/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenar3.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:45:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/01/27 16:56:43 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR3_CLASS_HPP
# define SCENAR3_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Scenar3 : public ft42 {
public:
	t_data *	d;
	char		scenar3Draw;
	bool		Scenar3FirstCall;
	int			move;
	int 		upZ3;

	Scenar3( void );
	~Scenar3( void );

	void	initWater( void );
	void	clearBuffer1( void );
	void	clearBuffer2( void );
	void	upWater( void );
	void	rUpWater1(t_data * d, int z, int y, int x);
	void	rUpWater2(t_data * d, int z, int y, int x);
	void	go( void );
	void	hillCopy_1to2( t_data * d );
	void	hillCopy_2to1( t_data * d );
	void	resetChecked( void );
	void	print2Dmap( void );

private:
	Scenar3( Scenar3 const & src );
	Scenar3 & operator=( Scenar3 const & rhs );
};

#endif