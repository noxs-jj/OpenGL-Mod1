// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scenar1.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/25 18:35:02 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/25 18:35:03 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCENAR1_CLASS_HPP
# define SCENAR1_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Scenar1 : public ft42 {
public:
	t_data *	d;

	Scenar1();
	~Scenar1();
	
	void	upWater( int z );
	void	go( void );

private:
	Scenar1( Scenar1 const & rSource );
	Scenar1 & operator=( Scenar1 const & rSource );

	void	rUpWater(t_data * d, int z, int y, int x);
};

#endif
