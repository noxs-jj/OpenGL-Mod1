/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenar8.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:45:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/01/30 17:01:51 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR8_CLASS_HPP
# define SCENAR8_CLASS_HPP

# include "main.hpp"
# include "ft42.class.hpp"

class Scenar8 : public ft42 {
public:
	t_data *	d;
	char		scenar8Draw;
	bool		Scenar8FirstCall;

	Scenar8( void );
	~Scenar8( void );

	void		initWater( void );
	void		clearBuffer1( void );
	void		clearBuffer2( void );
	void		upWater( void );
	void		rUpWater1(t_data * d, int z, int y, int x);
	void		rUpWater2(t_data * d, int z, int y, int x);
	void		go( void );
	void		hillCopy_1to2( t_data * d );
	void		hillCopy_2to1( t_data * d );
	void		resetChecked( void );
	void		print2Dmap( void );
	void		Rain( t_data * d, bool buffer );
	int			ChoosePath( t_pts ** oldBuff, t_pts ** newBuff, int z, int y, int x );
	void 		WaterUp( t_data *d, t_pts ** buffer );

private:
	Scenar8( Scenar8 const & src );
	Scenar8 & operator=( Scenar8 const & rhs );
};

#endif