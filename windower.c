/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 02:30:54 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/11 04:07:54 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void windower(int *wind, t_tab **matrix)
{ int x;
  int y;
  int k;
  y = wind[1] - 2;
  while (++y < wind[3])
  { go_to(wind[0], y);
    x = wind[4] - 1;
    while (++x < wind[2] + wind[4])
    { k = -1;
      while (++k < 10)
      { ft_putstr_fd(matrix[y][x].attr[k], 2); }
      ft_putchar_fd(matrix[y][x].c, 2); }}}
