/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 07:56:58 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 12:14:07 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"

void get_coords(int *coord, int *test, t_term *coucou)
{ int i;
  if (test[0] < WIND[0] + 2 || test[0] > WIND[0] + WIND[2] - 1 || test[1] < WIND[1] + 3 || test[1] == WIND[1] + WIND[3] - 3 || test[1] == WIND[1] + WIND[3] - 1)
  { *coord = -1;
    return ; }
  coord[0] = WIND[4] + (test[0] - WIND[0]);
  coord[1] = test[1];
  i = (coord[0] - 2) / (coucou->size_max + 3);
  coord[0] = coord[1] - 4;
  coord[1] = i; }
