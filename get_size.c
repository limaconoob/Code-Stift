/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 05:32:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/16 10:09:42 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include <stdlib.h>

void get_size(int x, int y, t_term *term)
{ static int sx;
  static int sy;
  static t_term *connard = NULL;
  if (x == -1)
  { term->term[0] = sx;
    term->term[1] = sy;
    connard = term; }
  else if (y == -1)
  { term = connard; }
  else
  { sx = x;
    sy = y;
   /* if (!connard)
    { return ; }
    connard->term[0] = sx;
    connard->term[1] = sx;
    if (sx < connard->wind[0] + connard->wind[2])
    { if (sx - connard->wind[0] >= 15)
      { connard->wind[2] = sx - connard->wind[0]; }
      else
      { connard->wind[2] = 15;
        connard->wind[0] = sx - 15; }}
    init_wind(connard->wind, connard->matrix);
    windower(connard->wind, connard->matrix); */}}
