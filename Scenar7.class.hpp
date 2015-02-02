/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenar7.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:13:25 by vjacquie          #+#    #+#             */
/*   Updated: 2015/01/29 13:29:39 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR7_CLASS_HPP
# define SCENAR7_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Scenar7 : public ft42 {
private:

public:
	t_data *	d;

	Scenar7( void );
	~Scenar7( void );

	void	InitWater( void );
	void	upWater( void );
	void	go( void );
	
	

private:
	Scenar7( Scenar7 const & src );
	Scenar7 & operator=( Scenar7 const & rhs );

	void	resetChecked( t_data * d );
	int 	Clamp(int x, int min, int max);
	void	rUpWater(t_data * d, int z, int y, int x, bool line);//, bool checked);
};

#endif
