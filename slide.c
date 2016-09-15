/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:24:15 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/12 11:31:14 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

#include <fcntl.h>

void slide(t_term *coucou)
{ int i;
  i = -1;
  while (++i < SLID[2])
  { BZE(MATR[SLID[1]][WIND[4] + SLID[0] + i].attr[2], 8); }
  if (WIND[4] + WIND[2] < coucou->mat_size)
  { WIND[4] += WIND[2];
    SLID[0] += 1; }
  else if (WIND[4] != coucou->mat_size - WIND[2])
  { WIND[4] = coucou->mat_size - WIND[2];
    SLID[0] += 1; }}
