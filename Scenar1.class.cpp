// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scenar1.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/25 18:34:56 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/25 18:34:58 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Scenar1.class.hpp"

void	Scenar1::go( void ) {
	int y = 0;
	int x;

	glBegin(GL_POINTS);
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				ft42::hillColor_toShow( d, y, x );
				x++;
			}
			y++;
		}
	glEnd();
	ft42::oceanBorder();
	usleep(100000);
}

void	Scenar1::rUpWater(t_data * d, int z, int y, int x) {
	if ( d->map2d[y][x].type == WATER ) // if already WATER up one more Z
		d->map2d[y][x].z = z;

	if (  z >= d->map2d[y][x].z ) {
		d->map2d[y][x].type = WATER;
		d->map2d[y][x].z = z;
	}

}

void	Scenar1::upWater( int z ) {
	int y = 0;
	int x = 0;
	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			rUpWater(this->d, z, y, x);
			x++;
		}
		y++;
	}
}

Scenar1::Scenar1() {
	this->d = getData();
	this->d->toShow = this->d->map2d;
}

Scenar1::Scenar1( Scenar1 const & rSource ) {
	*this = rSource;
}

Scenar1 & Scenar1::operator=( Scenar1 const & rSource ) {
	if ( this != &rSource ) {
		this->d = rSource.d;
	}

	return *this;
}

Scenar1::~Scenar1() {}
