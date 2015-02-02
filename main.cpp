// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/20 10:30:45 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/20 10:30:46 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "main.hpp"
#include "Event.class.hpp"
#include "Parseur.class.hpp"

int      main( int ac, char** av) {
	if (ac != 3) {
		std::cerr << "Request only 2 arguments: file.mod1 Scenar" << std::endl;
		return 0;
	}
	getData();							// init BigData
	Event			event;				// Call mainEvent
	try {
		event.initEvent(av);			// Init object, alloc maps, open debugg
		event.d->parseur->fileToTab(); 	// put Source File to list of pts
	}
	catch (std::exception & e) {
		std::cerr << "Initilisation error..." << std::endl;
		return -1;
	}
	event.initMap();					// initmap with default values
	event.initRender(ac, av);			// init Opengl
	event.renderScene();				// show scenars

	return 0;
}
