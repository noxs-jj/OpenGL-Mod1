// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parseur.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/20 11:11:33 by jmoiroux          #+#    #+#             //
//   Updated: 2015/01/20 11:11:33 by jmoiroux         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSEUR_CLASS_HPP
# define PARSEUR_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Parseur : public ft42 {
public:
	Parseur( char * path );
	~Parseur();

	t_pts	fileToTab( void );
	void	printMap( void );
	void	sortByZ_minToMax( void );
	void	resizeValue( void );

	class ErrorParse : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	char *			_pathToSource;
	t_data *		_d;
	Parseur(Parseur const & rSource);
	Parseur & operator=(Parseur const & rSource);
	Parseur();
};

#endif
