/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wind_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 01:38:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/10 11:13:24 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void wind_clear(int *wind, t_tab **matrix)
{ static char attr[10][8] = {"\033[0m", "", "", "", "", "", "", "", "", ""};
  int i;
  int j;
  i = wind[1] - 2;
  while (++i < wind[3])
  { j = wind[4] - 1;
    while (++j < wind[2] + wind[4])
    { init_char(' ', &matrix[i][j], attr); }}}
