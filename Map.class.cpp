// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/22 15:27:46 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/22 15:27:47 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.class.hpp"

Map::Map() {
	int y = 0;
	int	x;

	this->_d = getData();
	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			this->_d->map2d[y][x].type 			= EMPTY;
			this->_d->map2d[y][x].z 			= 0;
			this->_d->originMAp[y][x].type 		= EMPTY;
			this->_d->originMAp[y][x].z 		= 0;
			x++;
		}
		y++;
	}
}

Map::Map( Map const & rSource ) {
	*this = rSource;
}

Map & Map::operator=( Map const & rSource ) {
	if ( this != &rSource ) {
		this->_d = getData();
	}

	return *this;
}

void 	Map::doCircle( t_data * d, int z, int startY, int startX ) {
	int 	rayon = RADIUS;
	int 	i;
	int 	j;

	while ( z > 0) {
		i = startX - rayon;
		while ( i <= startX + rayon ) {
			j = startY - rayon;
			while ( j <= startY + rayon ) {
				if ( ((i - startX) * (i - startX)) + ((j - startY) * (j - startY))
					<= (rayon * rayon)
					&& i < TAB_SIZE && i >= 0
					&& j < TAB_SIZE && j >= 0
					&& (d->map2d[j][i].type != HILL
					|| d->map2d[j][i].z <= z)) {

					d->map2d[j][i].type = HILL;
					d->map2d[j][i].z = z;
			}
			j++;
		}
		i++;
	}
	z--;
	rayon++;
	}
}

void    Map::doMapHill( void ) {
	std::list<t_pts *>::iterator    it = this->_d->randomPts.begin();
	std::list<t_pts *>::iterator    end = this->_d->randomPts.end();

	while ( it != end ) {
		doCircle( this->_d, static_cast<int>((*it)->z), static_cast<int>((*it)->y), static_cast<int>((*it)->x) );
		it++;
	}
}

Map::~Map() {}

void	Map::putRandomTo2dMap( void ) {
	std::list<t_pts *>::iterator	it = this->_d->randomPts.begin();
	std::list<t_pts *>::iterator	end = this->_d->randomPts.end();

	while ( it != end ) {
		this->_d->map2d[static_cast<int>( (*it)->y) ]
		[static_cast<int>( (*it)->x) ].z = (*it)->z;
		it++;
	}
}

void	Map::print2Dmap( void ) { // print Z from 2dmap used for debugg only
	if ( DEBUGG == true ) {
		int	y = 0;
		int	x;

		while( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				if (this->_d->map2d[y][x].z == 0)
						std::cout << " ";
					else
						std::cout << "@";
				x++;
			}
			std::cout << std::endl;
			y++;
		}
	}
}
