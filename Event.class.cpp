// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Event.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/28 15:57:39 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/28 15:57:40 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Event.class.hpp"
#include "Map.class.hpp"
#include "Parseur.class.hpp"
#include "Scenar1.class.hpp"
#include "Scenar3.class.hpp"
#include "Scenar4.class.hpp"
#include "Scenar7.class.hpp"
#include "Scenar8.class.hpp"

int		Event::initEvent( char ** av) {
	if ( DEBUGG == true ) {
		try {
			d->debug.open("debugg.txt", std::fstream::app); // open debugg file
			if (d->debug == NULL)
				throw std::exception();
			d->debug << "##############################################################" <<std::endl;
			d->debug << "##############################################################" <<std::endl;
			d->debug << "##############################################################" <<std::endl;
			d->debug << std::endl;
			d->debug << std::endl;
		}
		catch (std::exception & e) {
			std::cerr << "Event::initEvent: Debugg file open error..." << std::endl;
			throw std::exception();
		}
	}

	this->d->Scenar = atoi(av[2]);
	if ( 1 != this->d->Scenar && 3 != this->d->Scenar && 4 != this->d->Scenar
		&& 7 != this->d->Scenar && 8 != this->d->Scenar ) {
		std::cerr << "Event::initEvent: Scenar don't exist, try again..." << std::endl;
		std::cerr << "\t1 -> MAIN Water up from all map" << std::endl;
		std::cerr << "\t3 -> MAIN Double buffer - Water up from beach (better fonm OL)" << std::endl;
		std::cerr << "\t8 -> MAIN MAIN --- it's raining" << std::endl;
		std::cerr << "\t4 -> BONUS evaporation all map" << std::endl;
		std::cerr << "\t7 -> BONUS simple buffer - Water up from beach" << std::endl;
		throw std::exception();
	}

	this->d->map2d 			= ft42::allocMap2D();
	this->d->originMAp 		= ft42::allocMap2D();
	this->d->buffer1 		= ft42::allocMap2D();
	this->d->buffer2	 	= ft42::allocMap2D();
	this->d->upZ 			= 0;
	this->d->pause			= true;
	this->d->map 			= new Map();
	this->d->scenar1 		= new Scenar1();
	this->d->scenar3 		= new Scenar3();
	this->d->scenar4 		= new Scenar4();
	this->d->scenar7 		= new Scenar7();
	this->d->scenar8 		= new Scenar8();
	this->d->parseur 		= new Parseur(av[1]);
	if ( d->scenar1 == NULL || d->parseur == NULL || d->map == NULL || d == NULL
		|| d->scenar1 == NULL || d->scenar3 == NULL || d->scenar4 == NULL
		|| d->scenar7 == NULL || d->scenar8 == NULL) {
		std::cerr << "Event::initEvent: Allocation Error !" << std::endl;
		throw std::exception();
	}

	return 0;
}

void	Event::initMap( void ) {
	d->parseur->resizeValue(); 					// Scale map
	d->parseur->sortByZ_minToMax();				// Sort by height
	d->map->putRandomTo2dMap();					// put points to map2d array
	d->map->doMapHill();						// generate Hill on map2d
}

void	Event::initRender( int ac, char ** av ) {
	glutInit(&ac, av);							// init glut
	glutInitDisplayMode(GLUT_RGB				// set color to RGB
				| GLUT_DOUBLE					// set double buffered windows
				| GLUT_DEPTH);					// Bit mask to select a window with a depth buffer.
	glutInitWindowSize(WINX, WINY);				// Size of windows
	glutInitWindowPosition(STARTX, STARTY);   	// where the windos in create on Xserver/Desktop
	glutCreateWindow(TITLE);					// Create windows with title in param char *
	glClearColor(0.5f, 0.5f, 0.5f, 1); //purple			//set background/void color
	glEnable(GL_DEPTH_TEST);
	glPointSize(3.0f);
	glLineWidth(2.0f);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->print_str("S to Start", 0, -0.050f);
	this->print_str("SPACE = pause", -0.05f, -0.050);
	this->print_str("Q ECHAP & others = exit", -0.1f, -0.050);
	glFlush();
	glutSwapBuffers();
	glLoadIdentity();
}

void	Event::renderScene(void ) {
	glutKeyboardFunc(keyboard);					// function for keyboard event
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}

Event::Event() {
	this->d = getData();
}

Event::Event( Event const & rSource ) {
	*this = rSource;
}

Event & Event::operator=( Event const & rSource ) {
	return *this;
}

Event::~Event() {}
