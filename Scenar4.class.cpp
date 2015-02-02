// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scenar4.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/29 19:00:08 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/29 19:00:09 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Scenar4.class.hpp"

void	Scenar4::reDownX( int z, int y, int x) {
	if ( x + 1 < TAB_SIZE
		&& WATER != this->d->map2d[y][x + 1].type
		&& z <= this->d->map2d[y][x + 1].z
		) {

		this->purge[y][x + 1].type		= HILL;
		this->purge[y][x + 1].z 		= this->d->map2d[y][x + 1].z;
		this->purge[y][x + 1].checked 	= true;
	}
	if ( WATER == this->d->map2d[y][x].type	&& z == this->d->map2d[y][x].z) {
		this->purge[y][x].z 			= z;
		this->purge[y][x].checked 		= true;
	}
	if ( y + 1 < TAB_SIZE
		&& WATER != this->d->map2d[y + 1][x].type
		&& z <= this->d->map2d[y + 1][x].z
		) {

		this->purge[y + 1][x].type		= HILL;
		this->purge[y + 1][x].z 		= this->d->map2d[y + 1][x].z;
		this->purge[y + 1][x].checked 	= true;
	}
	if ( y - 1 >= 0
		&& WATER != this->d->map2d[y - 1][x].type
		&& z <= this->d->map2d[y - 1][x].z
		) {

		this->purge[y - 1][x].type		= HILL;
		this->purge[y - 1][x].z 		= this->d->map2d[y - 1][x].z;
		this->purge[y - 1][x].checked 	= true;
	}
	if ( x - 1 >= 0
		&& WATER != this->d->map2d[y][x - 1].type
		&& z <= this->d->map2d[y][x - 1].z
		) {

		this->purge[y][x - 1].type		= HILL;
		this->purge[y][x - 1].z 		= this->d->map2d[y][x - 1].z;
		this->purge[y][x - 1].checked 	= true;
	}
	if ( x + 1 < TAB_SIZE
		) {

		this->purge[y][x + 1].z 		= z;
		this->purge[y][x + 1].checked 	= true;
		reDownX(z, y, x + 1);
	}
}

void	Scenar4::downWater( void ) {
	if ( DEBUGG == true ) {
			this->d->debug << "Scenar4::downWater Start" << std::endl;
	}
	int y = 0;
	int x = 0;

	while ( y < TAB_SIZE ) {
		reDownX(this->downZ, y, 0);
		if ( WATER == this->purge[y][0].type )
			this->purge[y][x].z = this->downZ;
		y++;
	}
	if ( this->downZ >= 0 ) {
		this->downZ--;
	}
	this->resetChecked();
}

void	Scenar4::initWater( void) {
	if ( true == firstCall ) {
		if ( DEBUGG == true ) {
			this->d->debug << "Scenar4::initWater Start" << std::endl;
		}
		int 							y = 0;
		int x;

		firstCall						= false;
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				this->purge[y][x].type	= WATER;
				this->purge[y][x].z		= MAX_HEIGHT + PURGE_START;
				x++;
			}
			y++;
		}
		this->d->toShow = this->purge;
	}
}

void	Scenar4::resetChecked( void ) {
	int y = 0;
	int x;

	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			this->d->buffer1[y][x].checked = false;
			x++;
		}
		y++;
	}
}

void	Scenar4::go( void ) {
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
}

Scenar4::Scenar4() : firstCall(true), downZ(MAX_HEIGHT + PURGE_START) {
	this->d = getData();
	this->purge = allocMap2D();
}

Scenar4::Scenar4( Scenar4 const & rSource ) {}

Scenar4 & Scenar4::operator=( Scenar4 const & rSource ) {}

Scenar4::~Scenar4() {}
