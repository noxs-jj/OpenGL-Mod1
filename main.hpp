// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/20 10:30:41 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/20 10:30:42 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAIN_HPP
# define MAIN_HPP

// 1 MAIN --- Water up from all map (berk)
// 3 MAIN --- Double buffer - Water up from beach ( OL style )
// 8 MAIN --- it's raining
// 4 BONUS Evaporation all
// 7 BONUS simple buffer

# define TITLE "Mod1 by Jean-Jacques & Vincent - 42"
# define WINX 1200 			// 1200 default
# define WINY 1200 			// 1200 default
# define STARTX 620 		// 620 default
# define STARTY 100 		// 100 default

# define TAB_SIZE 500 		// 500 dfault
# define MAX_HEIGHT 150 	// 150 default MUST be less 255 for rgb

# define SCALE_MAP 1.1f 	// 1.1f default
# define SCALE_HILL 1.115f 	// 1.115f default
# define SCALE_GL 0.001f 	// 0.001f default
# define CTE1 0.99f 		// 0.99f default
# define CTE2 0.99f 		// 0.99f default

# define SLOPE 1 			// + 1x, - SLOPE Z
# define RADIUS 25			// 25 default radius hill default
# define WATERFLUX_6 40		// 40 default scenar 6
# define WATERFLUX_3 15 	// 15 default scenar 3
# define PURGE_START 50 	// default 100 set water start: hill + water height

# define RAINFLUX 1000		// 1000 default add X rain per frame
# define RAINUP ((TAB_SIZE * TAB_SIZE) / RAINFLUX)

# define EMPTY 'e'
# define WATER 'w'
# define HILL 'h'
# define RAIN 'r'

// Option logs debugs in file 
# define DEBUGG false		//default false

# include <fstream>
# include <iostream>
# include <cstdlib>
# include <list>
# include <stdexcept>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <sstream>
# include <time.h>
# include <unistd.h>
# include <vector>

//OpenGL
# ifdef linux //sudo apt-get install freeglut3 freeglut3-dev
#	include <GL/gl.h>
#	include <GL/glu.h>
#	include <GL/glut.h>
# endif
# ifdef __APPLE__
#	include <openGL/gl.h>
#	include <openGL/glu.h>
#	include <glut/glut.h>
# endif
# ifdef __WIN32__
#	include <GL/gl.h>
#	include <GL/glu.h>
#	include <windows.h>
# endif

class 						Scenar1;
class 						Scenar3;
class 						Scenar4;
class 						Scenar7;
class 						Scenar8;
class 						Parseur;
class 						Map;

typedef struct s_pts {
	char					type;
	bool					checked;
	float					x;
	float					y;
	float					z;
	float					upWater;
	int 					HillHeight;
}t_pts;

typedef struct s_data {
	std::ofstream			debug; 		// file where debugg're print
	std::list<t_pts *>		randomPts; 	// random pts from file .mod
	t_pts **				map2d; 		// tab 2D pts im memory
	t_pts **				originMAp;	// original 2D map without WATER
	t_pts **				buffer1;
	t_pts **				buffer2;
	t_pts **				toShow;
	Scenar1	*				scenar1;
	Scenar3	*				scenar3;
	Scenar4	*				scenar4;
	Scenar7	*				scenar7;
	Scenar8	*				scenar8;
	Parseur *				parseur;
	Map *					map;
	bool					pause;
	int 					upZ;
	float					XMapMax;
	float					XMapMin;
	float					YMapMax;
	float					YMapMin;
	float					ZMapMax;
	float					ZMapMin;
	int 					z;			// water level
	int 					Water;		// Water level up
	int						NeedUp;		// true if water need up, else false
	int 					Scenar;
}t_data;

t_data *	getData( void );
void  		display( void );
void		keyboard(unsigned char touche, int x, int y);
void		timer(int extra);

#endif
