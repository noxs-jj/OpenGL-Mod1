// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scenar4.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/29 19:00:15 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/29 19:00:15 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCENAR4_CLASS_HPP
# define SCENAR4_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Scenar4 : public ft42 {
public:
	t_data *	d;
	t_pts **	purge;
	bool		firstCall;
	int 		downZ;

	Scenar4();
	~Scenar4();

	void	downWater( void );
	void	reDownX( int z, int y, int x);
	void	go( void );
	void	initWater( void);
	void	resetChecked( void );

private:
	Scenar4( Scenar4 const & rSource );
	Scenar4 & operator=( Scenar4 const & rSource );
};

#endif