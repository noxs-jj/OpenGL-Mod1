// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Event.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/28 15:57:35 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/28 15:57:36 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EVENT_CLASS_HPP
# define EVENT_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Event : public ft42 {
public:
	t_data *d;

	Event();
	~Event();

	int		initEvent( char ** av );
	void	initMap( void );
	void	initRender( int ac, char ** av );
	void	renderScene(void );

private:
	Event( Event const & rSource );
	Event & operator=( Event const & rSource );

};

#endif
