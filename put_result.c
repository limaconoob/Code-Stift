/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:12:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/13 07:02:51 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

static int the_len(t_term *coucou)
{ int i = 0;
  int size = 0;
  int nb = 0;
  while (i < coucou->nb_files)
  { if (coucou->tab_tri[i])
    { size += LEN(coucou->tab_tri[i]);
      nb += 1; }
    i += 1; }
  return (size + nb); }

static void the_fill(t_term *coucou)
{ int i;
  char *tmp;
  i = 0;
  tmp = coucou->retour;
  while (i < coucou->nb_files)
  { if (coucou->tab_tri[i])
    { while (*(coucou->tab_tri[i]))
      { *tmp = *(coucou->tab_tri[i]);
        tmp += 1;
        coucou->tab_tri[i] += 1; }
      *tmp = ' ';
      tmp += 1; }
    i += 1; }}

void put_result(t_term *coucou)
{ if (!((coucou->retour = (char*)malloc(the_len(coucou)))))
  { select_error(Malloc, "retour in main"); }
  the_fill(coucou);
 go_to(0, 0);
 ft_putendl(coucou->retour); }
