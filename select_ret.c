/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_ret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 07:28:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/09 08:42:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void select_ret(t_term *coucou, int flag)
{ int coord[2];
  if (flag == 0) //space
  { get_coords(coord, CURS, coucou); }
  else if (flag == 1) //MONO CLICK
  { get_coords(coord, MOUS, coucou); }
  if (*coord == -1 || coord[0] < 0 || coord[1] < 0)
  { return ; }
  if ((flag == 0 || flag == 1) && coucou->mapper[coord[1]] && coucou->mapper[coord[1]][coord[0]])
  { if (!*(MAPP[coord[1]][coord[0]]->attr[2]))
    { CPY(MAPP[coord[1]][coord[0]]->attr[2], "\033[31m");
      CPY(MAPP[coord[1]][coord[0]]->attr[3], "\033[47m");
      coucou->tab_tri[coucou->mapper[coord[1]][coord[0]]->index] = coucou->mapper[coord[1]][coord[0]]->name; }
    else
    { BZE(MAPP[coord[1]][coord[0]]->attr[2], 8);
      BZE(MAPP[coord[1]][coord[0]]->attr[3], 8);
      coucou->tab_tri[MAPP[coord[1]][coord[0]]->index] = NULL; }}}
