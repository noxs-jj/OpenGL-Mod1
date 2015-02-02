// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   fts.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/31 16:09:57 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/31 16:09:58 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "main.hpp"
#include "Map.class.hpp"

void  		keyboard(unsigned char touche, int x, int y)
{
	(void)x;
	(void)y;
	t_data *	d = getData();
	while (42)
	{
		if ( touche == 'q' || touche == 27 ) {
			d->map->delData(d);
			if ( true == DEBUGG) {
				d->debug << "\t!!!! Exit Success !!!! from 'ECHAP' 'Q'" << std::endl;
			}
			d->debug.close();
			std::free( d );
			exit(0);
		}
		else if ( touche == 32 ) {
			if ( true == DEBUGG) {
				d->debug << "\t!!!! Keyboard Pause == " << d->pause << std::endl;
			}
			if ( false == d->pause )
				d->pause = true;
			else
				d->pause = false;
			glutPostRedisplay();
			return;

		}
		else if ( touche == 's' ) {
			if ( true == DEBUGG) {
				d->debug << "\t!!!! Keyboard 'S' == START" << std::endl;
			}
			d->pause = false;
			glutPostRedisplay();
			return;
		}
		else {
			d->map->delData( d );
			if (  true == DEBUGG ) {
				d->debug << "\t!!!! ELSE Exit Success !!!! from keyboard" << std::endl;
			}
			d->debug.close();
			std::free( d );
			exit(0);
		}
	}
}

void		timer(int extra) {
	glutPostRedisplay();
	glutTimerFunc(0, timer, 0);
}

t_data * 	getData( void ) {
	static t_data *   d = NULL;

	if ( d == NULL ) {
		d = new t_data;
		if ( d == NULL)
			return NULL;
		return d;
	}

	return d;
}
