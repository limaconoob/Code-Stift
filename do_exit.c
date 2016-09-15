/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 03:50:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/13 10:06:51 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void do_exit(t_term *coucou)
{ wind_clear(WIND, MATR);
  go_to(WIND[0], WIND[1] - 1);
  windower(WIND, MATR);
  term_init();
  free_coucou(coucou);
  go_to(0,  WIND[1] - 1);
  ft_putchar('\n');
  exit(0); }
