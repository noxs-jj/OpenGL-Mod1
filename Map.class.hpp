// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/22 15:27:42 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/22 15:27:42 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Map : public ft42 {
public:
	t_data *	_d;

	Map();
	~Map();

	void	putRandomTo2dMap( void );
	void	print2Dmap( void );
	void    doMapHill( void );
	void	doHillPic(t_data * d, int z, int y, int x );

private:
	Map( Map const & rSource );
	Map & operator=( Map const & rSource );

	void 	doCircle( t_data * d, int z, int startY, int startX );
};

#endif
