/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenar8.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:45:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/01/30 17:09:33 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "main.hpp"
#include "Scenar8.class.hpp"

void	Scenar8::WaterUp( t_data *d, t_pts ** buffer ) {
	int x, y = 0;

	while (y < TAB_SIZE) {
		x = 0;
		while (x < TAB_SIZE) {

			if (buffer[y][x].type != HILL && buffer[y][x].z < d->z + 1) {
				buffer[y][x].type = WATER;
				buffer[y][x].z = d->z;
			} 
			x++;
		}
		y++;
	}
}

void	Scenar8::Rain( t_data * d, bool buffer ) {
	int x = 0, y = 0, i = 0;

	while ( i < RAINFLUX ) {
		x = rand() % TAB_SIZE;
		y = rand() % TAB_SIZE;
		if (buffer == false) {// && d->buffer1[y][x].z != 0) {	// buffer 1
			if (d->buffer1[y][x].type != WATER) {
				d->buffer1[y][x].type = RAIN;
				d->buffer1[y][x].z++;
			}
			i++;
		}
		else if (buffer == true) {//&& d->buffer2[y][x].z != 0){	// buffer 2
			if (d->buffer2[y][x].type != WATER) {
				d->buffer2[y][x].type = RAIN;
				d->buffer2[y][x].z++;
			}
			i++;
		}
	}
}

void	Scenar8::upWater( void ) {
	int 		y = 0;
	int 		x;
	static int 	UpWater = 0;

	this->d->toShow = this->d->buffer2;
	UpWater++;
	if (UpWater >= RAINUP) {
		UpWater = 0;
		this->d->z = (this->d->z == -1) ? 2 : this->d->z + 1;
		if ( this->d->z > TAB_SIZE )
			this->d->z = TAB_SIZE;
	}
	if ( scenar8Draw == '2' ) { // buffer2 in memory/screen
		hillCopy_2to1( d );
			Rain(d, true); // add rain in buffer 2
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				if ( this->d->buffer2[y][x].type == RAIN ){
					rUpWater1(d, this->d->buffer2[y][x].z, y, x);
				}
				x++;
			}
			y++;
		}
		this->d->toShow = this->d->buffer1;
		this->scenar8Draw = '1';
		WaterUp(this->d, this->d->toShow);
		this->clearBuffer2();
	}
	else if ( scenar8Draw == '1' ) {
		hillCopy_1to2( d );
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				if ( this->d->buffer1[y][x].type == RAIN ){
					rUpWater2(d, this->d->buffer1[y][x].z, y, x);
				}
				x++;
			}
			y++;
		}
		this->d->toShow = this->d->buffer2;
		this->scenar8Draw = '2';
		WaterUp(this->d, this->d->toShow);
		this->clearBuffer1();
	}
}

int 	Scenar8::ChoosePath( t_pts ** oldBuff, t_pts ** newBuff, int z, int y, int x ) {
	int tmp = z;
	int path = -1;

	if (x + 1 < TAB_SIZE && ((newBuff[y][x + 1].checked == false && tmp > oldBuff[y][x + 1].z && tmp - 1 != oldBuff[y][x + 1].z)
		|| (newBuff[y][x + 1].checked == true && tmp > newBuff[y][x + 1].z && tmp - 1 != newBuff[y][x + 1].z))) {
		path = 1;
		tmp = (newBuff[y][x + 1].checked == true) ? newBuff[y][x + 1].z : oldBuff[y][x + 1].z;
	}
	if (x - 1 >= 0 && ((newBuff[y][x - 1].checked == false && tmp > oldBuff[y][x - 1].z && tmp - 1 != oldBuff[y][x - 1].z)
		|| (newBuff[y][x - 1].checked == true && tmp > newBuff[y][x - 1].z && tmp - 1 != newBuff[y][x - 1].z))) {
		path = 2;
		tmp = (newBuff[y][x - 1].checked == true) ? newBuff[y][x - 1].z : oldBuff[y][x - 1].z;
	}
	if (y + 1 < TAB_SIZE && ((newBuff[y + 1][x].checked == false && tmp > oldBuff[y + 1][x].z && tmp - 1 != oldBuff[y + 1][x].z)
		|| (newBuff[y + 1][x].checked == true && tmp > newBuff[y + 1][x].z && tmp - 1 != newBuff[y + 1][x].z))) {
		path = 3;
		tmp = (newBuff[y + 1][x].checked == true) ? newBuff[y + 1][x].z : oldBuff[y + 1][x].z;
	}
	if (y - 1 >= 0 && ((newBuff[y - 1][x].checked == false && tmp > oldBuff[y - 1][x].z && tmp - 1 != oldBuff[y - 1][x].z)
		|| (newBuff[y - 1][x].checked == true && tmp > newBuff[y - 1][x].z && tmp - 1 != newBuff[y - 1][x].z))) {
		path = 4;
		tmp = (newBuff[y - 1][x].checked == true) ? newBuff[y - 1][x].z : oldBuff[y - 1][x].z;
	}
	return (path);
}

void	Scenar8::rUpWater1(t_data * d, int z, int y, int x) {
	int dir = ChoosePath(d->buffer2, d->buffer1, z, y, x);
	// std::cout << "1path:" << dir << " z:"<< z << std::endl;
	if (dir == -1) {
		// if ()
		if (d->buffer1[y][x].type != WATER) {
			d->buffer1[y][x].z = d->buffer2[y][x].z;
			d->buffer1[y][x].checked = true;
			d->buffer1[y][x].type = RAIN;
		}
		return ;
	}
	if (d->buffer2[y][x].z - d->buffer2[y][x].HillHeight > 0)
			d->buffer2[y][x].z--;
	if (d->buffer2[y][x].z == 0)
		d->buffer2[y][x].type = EMPTY;
	else if (d->buffer2[y][x].z - d->buffer2[y][x].HillHeight == 0)
		d->buffer2[y][x].type = HILL;
	else
		d->buffer2[y][x].type = RAIN;
	if (dir == 1 && d->buffer1[y][x + 1].type != WATER) {	// x + 1
		d->buffer1[y][x + 1].type = RAIN;
		d->buffer1[y][x + 1].z = d->buffer2[y][x + 1].z + 1;
		d->buffer1[y][x + 1].checked = true;
	}
	else if (dir == 2 && d->buffer1[y][x - 1].type != WATER) { // x - 1
		d->buffer1[y][x - 1].type = RAIN;
		d->buffer1[y][x - 1].z = d->buffer2[y][x - 1].z + 1;
		d->buffer1[y][x - 1].checked = true;
	}
	else if (dir == 3 && d->buffer1[y + 1][x].type != WATER) { // y + 1
		d->buffer1[y + 1][x].type = RAIN;
		d->buffer1[y + 1][x].z = d->buffer2[y + 1][x].z + 1;
		d->buffer1[y + 1][x].checked = true;
	}
	else if (dir == 4 && d->buffer1[y - 1][x].type != WATER) { // y - 1
		d->buffer1[y - 1][x].type = RAIN;
		d->buffer1[y - 1][x].z = d->buffer2[y - 1][x].z + 1;
		d->buffer1[y - 1][x].checked = true;
	}
}

void	Scenar8::rUpWater2(t_data * d, int z, int y, int x) {
	int dir = ChoosePath(d->buffer1, d->buffer2, z, y, x);

	if (dir == -1) {
		if (d->buffer1[y][x].type != WATER) {
			d->buffer2[y][x].z = d->buffer1[y][x].z;
			d->buffer2[y][x].type = RAIN;
			d->buffer2[y][x].checked = true;
		}
		return ;
	}
	if (d->buffer1[y][x].z - d->buffer1[y][x].HillHeight > 0)
			d->buffer1[y][x].z--;
	if (d->buffer1[y][x].z == 0)
		d->buffer1[y][x].type = EMPTY;
	else if (d->buffer1[y][x].z - d->buffer1[y][x].HillHeight == 0)
		d->buffer1[y][x].type = HILL;
	else
		d->buffer1[y][x].type = RAIN;
	if (dir == 1 && d->buffer2[y][x + 1].type != WATER) {	// x + 1
		d->buffer2[y][x + 1].type = RAIN;
		d->buffer2[y][x + 1].checked = true;
		d->buffer2[y][x + 1].z = d->buffer1[y][x + 1].z + 1;
	}
	else if (dir == 2 && d->buffer2[y][x - 1].type != WATER) { // x - 1
		d->buffer2[y][x - 1].type = RAIN;
		d->buffer2[y][x - 1].checked = true;
		d->buffer2[y][x - 1].z = d->buffer1[y][x - 1].z + 1;
	}
	else if (dir == 3 && d->buffer2[y + 1][x].type != WATER) { // y + 1
		d->buffer2[y + 1][x].type = RAIN;
		d->buffer2[y + 1][x].checked = true;
		d->buffer2[y + 1][x].z = d->buffer1[y + 1][x].z + 1;
	}
	else if (dir == 4 && d->buffer2[y - 1][x].type != WATER) { // y - 1
		d->buffer2[y - 1][x].type = RAIN;
		d->buffer2[y - 1][x].checked = true;
		d->buffer2[y - 1][x].z = d->buffer1[y - 1][x].z + 1;
	}
}

void	Scenar8::hillCopy_1to2( t_data * d ) { // Copy NO WATER buffer 2 to buffer 1
	int y = 0;
	int x;

	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			if ( this->d->map2d[y][x].type != RAIN ) {
				this->d->buffer2[y][x].type 	= this->d->map2d[y][x].type;
				this->d->buffer2[y][x].z 		= this->d->map2d[y][x].z;
				this->d->buffer2[y][x].HillHeight 		= this->d->map2d[y][x].HillHeight;
				this->d->buffer2[y][x].checked 		= false;
				if (this->d->map2d[y][x].z < d->z) {
					this->d->buffer2[y][x].type = WATER;
					this->d->buffer2[y][x].z = d->z;
				}
			}
			x++;
		}
		y++;
	}
}

void	Scenar8::hillCopy_2to1( t_data * d ) { // Copy NO WATER buffer 1 to buffer 2
	int y = 0;
	int x;

	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			if ( this->d->map2d[y][x].type != RAIN ) {
				this->d->buffer1[y][x].type 	= this->d->map2d[y][x].type;
				this->d->buffer1[y][x].z 		= this->d->map2d[y][x].z;
				this->d->buffer2[y][x].HillHeight 		= this->d->map2d[y][x].HillHeight;
				this->d->buffer1[y][x].checked 		= false;
				if (this->d->map2d[y][x].z < d->z) {
					this->d->buffer1[y][x].type = WATER;
					this->d->buffer1[y][x].z = d->z;
				}
			}
			x++;
		}
		y++;
	}
}
void	Scenar8::resetChecked( void ) {
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

void	Scenar8::initWater( void ) {
	if ( this->Scenar8FirstCall == true ) {
		if ( DEBUGG == true ) {
			this->d->debug << "Scenar8::UpWater initWater ONLY ONE" << std::endl;
		}
		this->clearBuffer1();
		this->clearBuffer2();
		this->d->toShow = d->buffer2;
		this->Scenar8FirstCall = false;
		int y = 0;
		int x;
		while ( y < TAB_SIZE ) { // copy map[2d] to buffer2
			x = 0;
			while ( x < TAB_SIZE ) {

				this->d->buffer2[y][x].type 	= this->d->map2d[y][x].type;
				this->d->buffer2[y][x].z 		= this->d->map2d[y][x].z;
				this->d->buffer2[y][x].HillHeight 		= this->d->map2d[y][x].HillHeight;

				x++;
			}
			y++;
		}
	}
}

void	Scenar8::clearBuffer1( void ) {
	int y = 0;
	int x;
	if ( DEBUGG == true ){
		this->d->debug << "Scenar8::UpWater clearBuffer1" << std::endl;
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
			d->buffer1[y][x].HillHeight 	= 0;
			x++;
		}
		y++;
	}
}

void	Scenar8::clearBuffer2( void ) {
	int y = 0;
	int x;
	if ( DEBUGG == true ) {
		this->d->debug << "Scenar8::UpWater clearBuffer2" << std::endl;
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
			this->d->buffer2[y][x].HillHeight 	= 0;
			x++;
		}
		y++;
	}
}

void	Scenar8::go( void ) {
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

void	Scenar8::print2Dmap( void ) { // print Z from 2dmap used for debugg only
	if ( DEBUGG == true ) {
		int	y = 0;
		while( y < TAB_SIZE ) {
			this->d->debug << "Scenar8::print2Dmap [ type z ] [ " << this->d->toShow[y][0].type;
			this->d->debug << " - " << this->d->toShow[y][0].z << " ]" << std::endl;
			y++;
		}
	}
}

Scenar8::Scenar8() : Scenar8FirstCall(true), scenar8Draw('2') {
	this->d = getData();
	this->d->z = -1;
	srand(time(NULL));
}

Scenar8::Scenar8( Scenar8 const & rSource ) {
	*this = rSource;
}

Scenar8 & Scenar8::operator=( Scenar8 const & rSource ) {
	if ( this != &rSource ) {
		this->d = rSource.d;
	}

	return *this;
}

Scenar8::~Scenar8() {}
