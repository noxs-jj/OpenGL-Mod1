/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenar3.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:45:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/01/27 16:55:11 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Scenar3.class.hpp"

void	Scenar3::upWater( void ) {
	int y = 0;
	int x;

	this->resetChecked();
	this->move = 0;
	this->d->toShow = this->d->buffer2;
	if ( scenar3Draw == '2' ) { // buffer2 in memory/screen
		hillCopy_2to1( d );
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				if ( this->d->buffer2[y][x].type == WATER ){
						rUpWater1(d, this->upZ3, y, x);
				}
				x++;
			}
			y++;
		}
		d->toShow = this->d->buffer1;
		this->scenar3Draw = '1';
	}
	else if ( scenar3Draw == '1' ) { // buffer1 in memory/screen
		hillCopy_1to2( d );
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				if ( this->d->buffer1[y][x].type == WATER ){
						rUpWater2(d, this->upZ3, y, x);
				}
				x++;
			}
			y++;
		}
		this->d->toShow = this->d->buffer2;
		this->scenar3Draw = '2';
	}
	if ( move < WATERFLUX_3 && this->upZ3 < TAB_SIZE )
		(this->upZ3)++;
}

void	Scenar3::rUpWater1(t_data * d, int z, int y, int x) {
	// move WATER from buffer2 to buffer1 with +1 pixel/case move
	if ( x + 1 < TAB_SIZE
		&& this->d->buffer2[y][x + 1].type != WATER
		&& this->d->buffer2[y][x + 1].z == 0
		&& this->d->buffer2[y][x + 1].checked == false
		) {
		this->d->buffer1[y][x + 1].type 	= WATER;
		this->d->buffer1[y][x + 1].checked 	= true;
		this->move++;
	}
	else if ( x + 1 < TAB_SIZE
		&& this->d->buffer2[y][x + 1].type != WATER
		&& this->d->buffer1[y][x].z == this->d->buffer2[y][x + 1].z
		&& this->d->buffer2[y][x + 1].checked == false
		) {
		this->d->buffer1[y][x + 1].type 	= WATER;
		this->d->buffer1[y][x + 1].checked 	= true;
		this->move++;
	}
	if ( x - 1 >= 0
		&& this->d->buffer2[y][x - 1].type != WATER
		&& this->d->buffer2[y][x - 1].z == 0
		&& this->d->buffer2[y][x - 1].checked == false
		) {
		this->d->buffer1[y][x - 1].type 	= WATER;
		this->d->buffer1[y][x - 1].checked 	= true;
		this->move++;
	}
	else if ( x - 1 >= 0
		&& this->d->buffer2[y][x - 1].type != WATER
		&& this->d->buffer1[y][x].z == this->d->buffer2[y][x - 1].z
		&& this->d->buffer2[y][x - 1].checked == false
		) {
		this->d->buffer1[y][x - 1].type 	= WATER;
		this->d->buffer1[y][x - 1].checked 	= true;
		this->move++;
	}
	if ( y + 1 < TAB_SIZE
		&& this->d->buffer2[y + 1][x].type != WATER
		&& this->d->buffer2[y + 1][x].z == 0
		&& this->d->buffer2[y + 1][x].checked == false
		) {
		this->d->buffer1[y + 1][x].type 	= WATER;
		this->d->buffer1[y + 1][x].checked 	= true;
		this->move++;
	}
	else if ( y + 1 < TAB_SIZE
		&& this->d->buffer2[y + 1][x].type != WATER
		&& this->d->buffer1[y][x].z == this->d->buffer2[y + 1][x].z
		&& this->d->buffer2[y + 1][x].checked == false
		) {
		this->d->buffer1[y + 1][x].type 	= WATER;
		this->d->buffer1[y + 1][x].checked 	= true;
		this->move++;
	}
	if ( y - 1 >= 0
		&& this->d->buffer2[y - 1][x].type != WATER
		&& this->d->buffer2[y - 1][x].z == 0
		&& this->d->buffer2[y - 1][x].checked == false
		) {
		this->d->buffer1[y - 1][x].type 	= WATER;
		this->d->buffer1[y - 1][x].checked 	= true;
		this->move++;
	}
	else if ( y - 1 >= 0
		&& this->d->buffer2[y - 1][x].type != WATER
		&& this->d->buffer1[y][x].z == this->d->buffer2[y - 1][x].z
		&& this->d->buffer2[y - 1][x].checked == false
		) {
		this->d->buffer1[y - 1][x].type 	= WATER;
		this->d->buffer1[y - 1][x].checked 	= true;
		this->move++;
	}
	if ( this->d->buffer1[y][x].z < z )
		this->d->buffer1[y][x].z++;
}

void	Scenar3::rUpWater2(t_data * d, int z, int y, int x) {
	// move WATER from buffer1 to buffer2 with +1 pixel/case move
	if ( x + 1 < TAB_SIZE 
		&& this->d->buffer1[y][x + 1].type != WATER
		&& this->d->buffer1[y][x + 1].z == 0
		&& this->d->buffer1[y][x + 1].checked == false
		) {
		this->d->buffer2[y][x + 1].type 	= WATER;
		this->d->buffer2[y][x + 1].checked 	= true;
		this->move++;
	}
	else if ( x + 1 < TAB_SIZE 
		&& this->d->buffer1[y][x + 1].type != WATER
		&& this->d->buffer2[y][x].z >= this->d->buffer1[y][x + 1].z
		&& this->d->buffer1[y][x + 1].checked == false
		) {
		this->d->buffer2[y][x + 1].type 	= WATER;
		this->d->buffer2[y][x + 1].checked 	= true;
		this->move++;
	}
	if ( x - 1 >= 0
		&& this->d->buffer1[y][x - 1].type != WATER
		&& this->d->buffer1[y][x - 1].z == 0
		&& this->d->buffer1[y][x - 1].checked == false
		) {
		this->d->buffer2[y][x - 1].type 	= WATER;
		this->d->buffer2[y][x - 1].checked 	= true;
		this->move++;
	}
	else if ( x - 1 >= 0
		&& this->d->buffer1[y][x - 1].type != WATER
		&& this->d->buffer2[y][x].z >= this->d->buffer1[y][x - 1].z
		&& this->d->buffer1[y][x - 1].checked == false
		) {
		this->d->buffer2[y][x - 1].type 	= WATER;
		this->d->buffer2[y][x - 1].checked 	= true;
		this->move++;
	}
	if ( y + 1 < TAB_SIZE
		&& this->d->buffer1[y + 1][x].type != WATER
		&& this->d->buffer1[y + 1][x].z == 0
		&& this->d->buffer1[y + 1][x].checked == false
		) {
		this->d->buffer2[y + 1][x].type 	= WATER;
		this->d->buffer2[y + 1][x].checked 	= true;
		this->move++;
	}
	else if ( y + 1 < TAB_SIZE
		&& this->d->buffer1[y + 1][x].type != WATER
		&& this->d->buffer2[y][x].z >= this->d->buffer1[y + 1][x].z
		&& this->d->buffer1[y + 1][x].checked == false
		) {
		this->d->buffer2[y + 1][x].type 	= WATER;
		this->d->buffer2[y + 1][x].checked 	= true;
		this->move++;
	}
	if ( y - 1 >= 0
		&& this->d->buffer1[y - 1][x].type != WATER
		&& this->d->buffer1[y - 1][x].z == 0
		&& this->d->buffer1[y - 1][x].checked == false
		) {
		this->d->buffer2[y - 1][x].type 	= WATER;
		this->d->buffer2[y - 1][x].checked 	= true;
		this->move++;
	}
	else if ( y - 1 >= 0
		&& this->d->buffer1[y - 1][x].type != WATER
		&& this->d->buffer2[y][x].z >= this->d->buffer1[y - 1][x].z
		&& this->d->buffer1[y - 1][x].checked == false
		) {
		this->d->buffer2[y - 1][x].type 	= WATER;
		this->d->buffer2[y - 1][x].checked 	= true;
		this->move++;
	}
	if ( this->d->buffer2[y][x].z < z )
		this->d->buffer2[y][x].z++;
}

void	Scenar3::hillCopy_1to2( t_data * d ) { // Copy NO WATER buffer 2 to buffer 1
	int y = 0;
	int x;

	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			if ( this->d->buffer2[y][x].type != WATER) {
				this->d->buffer2[y][x].type 	= this->d->buffer1[y][x].type;
				this->d->buffer2[y][x].z 		= this->d->buffer1[y][x].z;
			}
			x++;
		}
		y++;
	}
}

void	Scenar3::hillCopy_2to1( t_data * d ) { // Copy NO WATER buffer 1 to buffer 2
	int y = 0;
	int x;

	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			if ( this->d->buffer1[y][x].type != WATER ) {
				this->d->buffer1[y][x].type 	= this->d->buffer2[y][x].type;
				this->d->buffer1[y][x].z 		= this->d->buffer2[y][x].z;
			}
			x++;
		}
		y++;
	}
}

void	Scenar3::resetChecked( void ) {
	int y = 0;
	int x;

	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			this->d->buffer1[y][x].checked = false;
			this->d->buffer2[y][x].checked = false;
			x++;
		}
		y++;
	}
}

void	Scenar3::initWater( void ) {
	if ( this->Scenar3FirstCall == true ) {
		if ( DEBUGG == true ) {
			this->d->debug << "Scenar3::UpWater initWater ONLY ONE" << std::endl;
		}
		int y = 0;
		int x;

		this->clearBuffer1();
		this->clearBuffer2();
		this->d->toShow = d->buffer2;
		this->Scenar3FirstCall = false;
		while ( y < TAB_SIZE ) { // copy map[2d] to buffer2
			x = 0;
			while ( x < TAB_SIZE ) {
				this->d->buffer2[y][x].type 	= this->d->map2d[y][x].type;
				this->d->buffer2[y][x].z 		= this->d->map2d[y][x].z;
				x++;
			}
			y++;
		}
		y = 0;
		while ( y < TAB_SIZE ) { // init buffer2 with one line of water
			if ( this->d->buffer1[y][0].type != HILL
				&& this->d->buffer2[y][0].type != HILL) {

				this->d->buffer1[y][0].type 	= WATER;
				this->d->buffer1[y][0].checked 	= false;
				this->d->buffer1[y][0].z = 0;
				this->d->buffer2[y][0].type 	= WATER;
				this->d->buffer2[y][0].checked 	= false;
				this->d->buffer2[y][0].z 		= 0;
			}
			y++;
		}
	}
}

void	Scenar3::clearBuffer1( void ) {
	int y = 0;
	int x;

	if ( DEBUGG == true ){
		this->d->debug << "Scenar3::UpWater clearBuffer1" << std::endl;
	}
	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			d->buffer1[y][x].type 		= EMPTY;
			d->buffer1[y][x].checked 	= false;
			d->buffer1[y][x].x 			= x;
			d->buffer1[y][x].y 			= y;
			d->buffer1[y][x].z 			= 0;
			d->buffer1[y][x].upWater 	= 0;
			x++;
		}
		y++;
	}
}

void	Scenar3::clearBuffer2( void ) {
	int y = 0;
	int x;

	if ( DEBUGG == true ) {
		this->d->debug << "Scenar3::UpWater clearBuffer2" << std::endl;
	}
	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			this->d->buffer2[y][x].type 	= EMPTY;
			this->d->buffer2[y][x].checked 	= false;
			this->d->buffer2[y][x].x 		= x;
			this->d->buffer2[y][x].y 		= y;
			this->d->buffer2[y][x].z 		= 0;
			this->d->buffer2[y][x].upWater 	= 0;
			x++;
		}
		y++;
	}
}

void	Scenar3::go( void ) {
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

void	Scenar3::print2Dmap( void ) { // print Z from 2dmap used for debugg only
	if ( DEBUGG == true ) {
		int	y = 0;

		while( y < TAB_SIZE ) {

			this->d->debug << "Scenar3::print2Dmap [ type z ] [ " << this->d->toShow[y][0].type;
			this->d->debug << " - " << this->d->toShow[y][0].z << " ]" << std::endl;
			y++;
		}
	}
}

Scenar3::Scenar3() : Scenar3FirstCall(true), scenar3Draw('2'), upZ3(0) {
	this->d = getData();
}

Scenar3::Scenar3( Scenar3 const & rSource ) {
	*this = rSource;
}

Scenar3 & Scenar3::operator=( Scenar3 const & rSource ) {
	if ( this != &rSource ) {
		this->d = rSource.d;
	}

	return *this;
}

Scenar3::~Scenar3() {}
