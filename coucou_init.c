/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 09:26:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 12:15:25 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/ioctl.h>

static void coucou_clear(t_term *coucou)
{ BZE(CURS, 4 * sizeof(int));
  BZE(MOUS, 5 * sizeof(int));
  BZE(TERM, 2 * sizeof(int));
  BZE(INFO, 2 * sizeof(int));
  coucou->nb_wind = 0; }

t_term *coucou_init(char **argv)
{ static t_term coucou[1];
  struct winsize w;
  coucou_clear(coucou);
  if (ioctl(0, TIOCGWINSZ, &w) == -1)
  { stift_error(TermInit, "TermKappa"); }
//  get_size(w.ws_col, w.ws_row, NULL);
//  get_size(-1, 0, coucou);
  ft_tri(&(argv[1]));
  return (coucou); }
