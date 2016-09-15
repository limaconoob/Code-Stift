/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:22:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/13 09:21:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void free_mapper(t_term *coucou)
{ int i;
  int j;
  i = -1;
  while (++i < coucou->nb_col)
  { j = -1;
    while (MAPP[i][++j])
    { free(MAPP[i][j]); }
    free(MAPP[i][j]);
    free(MAPP[i]); }
  free(MAPP[i]);
  free(MAPP); }
