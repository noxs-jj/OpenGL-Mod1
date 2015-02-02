// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft42.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/26 11:45:36 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/26 11:45:37 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ft42.class.hpp"

t_pts **	ft42::allocMap2D( void ) {
	int 		y = 0;
	int 		x = 0;
	t_pts **	tab = NULL;

	tab =  static_cast<t_pts**>(std::malloc(sizeof(t_pts *) * TAB_SIZE));
	if ( tab == NULL )
		return NULL;
	while ( y < TAB_SIZE ) {
		tab[y] = static_cast<t_pts*>(std::malloc(sizeof(t_pts) * TAB_SIZE));
		if ( tab[y] == NULL )
			return NULL;
		y++;
	}

	return tab;
}

void		ft42::print_str(char const * word, float y, float x) {
	int len = static_cast<int>( strlen(word) );
	int i;
	
	glColor3ub(0, 0, 0);
	glRasterPos2f(x, y);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
	}
}

void		ft42::hillColor_toShow( t_data *d, int y, int x ) {
	float	xResult;
	float	yResult;
	int		colorw;

	xResult = ( CTE1 * x ) - ( CTE2 * y );
	yResult = d->toShow[y][x].z + ( (CTE1 / 2 ) * x) + ( (CTE2 / 2 ) * y);
	if ( d->toShow[y][x].type == HILL ) { 
		glColor3ub(255 - d->toShow[y][x].z, 204, 102);
		glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
	}
	else if ( d->toShow[y][x].type == WATER ){
		if ( d->Scenar != 8 ) { // diff from scenar raining
			colorw = 255 - d->toShow[y][x].z - d->map2d[y][x].z;
			if ( colorw < 71 )
				colorw = 71;
			else if ( colorw > 255 )
				colorw = 255;
		}
		else
			colorw = 71;
		glColor3ub(71, colorw, 255); // Blue
		glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
	}
	else if ( d->toShow[y][x].type == RAIN ){
		glColor3ub(71, 71, 255); // Blue
		glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
	}
	else {
		glColor3ub(255, 204, 102); // jaune plage
		glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
	}
}

void		ft42::oceanBorder( void ) {
	t_data *	d = getData();
	float		xResult;
	float		yResult;
	int			y = 0;
	int			x = 0;

	glBegin(GL_LINE_STRIP);
	while ( y < TAB_SIZE ) {
			if ( d->toShow[y][0].type == WATER )
				glColor3ub(71, 71, 255); // bleu
			else
				glColor3ub(255 - d->toShow[y][0].z, 204, 102);
			xResult = ( CTE1 * 0 ) - ( CTE2 * y );
			yResult = 0 + ( (CTE1 / 2 ) * 0) + ( (CTE2 / 2 ) * y);
			glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
			xResult = ( CTE1 * 0 ) - ( CTE2 * y );
			yResult = d->toShow[y][0].z + ( (CTE1 / 2 ) * 0) + ( (CTE2 / 2 ) * y);
			glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
		
		y++;
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	while ( x < TAB_SIZE ) {
			if ( d->toShow[0][x].type == WATER )
				glColor3ub(71, 71, 255); // bleu
			else
				glColor3ub(255 - d->toShow[0][x].z, 204, 102);

			xResult = ( CTE1 * x ) - ( CTE2 * 0 );
			yResult = 0 + ( (CTE1 / 2 ) * x) + ( (CTE2 / 2 ) * 0);
			glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
			xResult = ( CTE1 * x ) - ( CTE2 * 0 );
			yResult = d->toShow[0][x].z + ( (CTE1 / 2 ) * x) + ( (CTE2 / 2 ) * 0);
			glVertex2f( xResult, -(TAB_SIZE / 2) + yResult);
		
		x++;
	}
	glEnd();
}

void		ft42::freeAllTab( t_data * d ) {
	if ( d->map2d != NULL
		|| d->originMAp != NULL
		|| d->buffer1 != NULL
		|| d->buffer2 != NULL) {
		int	y = 0;

		if ( DEBUGG == true )
			d->debug << "ft42::freeAllTab" << std::endl;
		while ( y < TAB_SIZE ) {
			std::free(static_cast<void *>( d->map2d[y]) );
			std::free(static_cast<void *>( d->originMAp[y]) );
			std::free(static_cast<void *>( d->buffer1[y]) );
			std::free(static_cast<void *>( d->buffer2[y]) );
			y++;
		}
		std::free(static_cast<void *>( d->map2d) );
		std::free(static_cast<void *>( d->originMAp) );
		std::free(static_cast<void *>( d->buffer1) );
		std::free(static_cast<void *>( d->buffer2) );
		d->map2d = NULL;
		d->originMAp = NULL;
		d->buffer1 = NULL;
		d->buffer2 = NULL;
	}
	else {
		if ( DEBUGG == true )
			d->debug << " Cannot Free something, variables're allready free " << std::endl;
	}
}

void		ft42::delData( t_data * d ) {
	if ( d->randomPts.empty() == false) {
		if ( DEBUGG == true )
			d->debug << "ft42::delData clear randomlist" << std::endl;
		d->randomPts.clear();
	}
	if ( d->map2d != NULL
		&& d->originMAp != NULL
		&& d->buffer1 != NULL
		&& d->buffer2 != NULL) {
		this->freeAllTab( d );
	}
	if (d->scenar1 != NULL && d->scenar8 != NULL && d->scenar3 != NULL || d->scenar4 != NULL
		&& d->scenar7 != NULL && d->parseur != NULL && d->map != NULL ) {
		if ( DEBUGG == true )
			d->debug << "ft42::delData delete objects" << std::endl;
		delete [] d->scenar1;
		delete [] d->scenar3;
		delete [] d->scenar4;
		delete [] d->scenar7;
		delete [] d->scenar8;
		delete [] d->parseur;
		delete [] d->map;
	}
}

ft42::ft42() {}

ft42::ft42( ft42 const & rSource ) {
	*this = rSource;
}

ft42 & ft42::operator=( ft42 const & rSource ) {
	return *this;
}

ft42::~ft42() {}
