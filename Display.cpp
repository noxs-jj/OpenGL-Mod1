/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:14:52 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/02 11:48:33 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Map.class.hpp"
#include "Scenar1.class.hpp"
#include "Scenar3.class.hpp"
#include "Scenar4.class.hpp"
#include "Scenar7.class.hpp"
#include "Scenar8.class.hpp"

void  display( void ) {
	t_data *	d = getData();
	if ( false == d->pause ) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glScalef(SCALE_GL, SCALE_GL, SCALE_GL);
		if ( d->Scenar == 1 ) {
			d->scenar1->upWater(d->upZ);
			d->scenar1->go();
		}
		else if ( d->Scenar == 3 ) {
			d->scenar3->initWater();
			d->scenar3->upWater();
			d->scenar3->go();
		}
		else if ( d->Scenar == 4 ) {
			d->scenar4->initWater();
			d->scenar4->downWater();
			d->scenar4->go();
		}
		else if ( d->Scenar == 7 ) {
			d->scenar7->InitWater();
			d->scenar7->upWater();
			d->scenar7->go();
		}
		else if ( d->Scenar == 8 ) {
			d->scenar8->initWater();
			d->scenar8->upWater();
			d->scenar8->go();
		}
		if ( d->upZ < TAB_SIZE )
			(d->upZ) += 1;
		glFlush();
		glutSwapBuffers();
		glLoadIdentity();
	}
	else
		usleep(50000);
}
