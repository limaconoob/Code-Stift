/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 06:07:48 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 12:29:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include "libft.h"
#include <stdlib.h>

t_tab **matrix_init(int *size)
{ int i;
  int j;
  int k;
  t_tab **matrix;
  if (!((matrix = (t_tab**)malloc(sizeof(t_tab*) * (size[1] + 1)))))
  { stift_error(Malloc, "matrix in matrix init"); }
  i = 0;
  while (i < size[1])
  { if (!((matrix[i] = (t_tab*)malloc(sizeof(t_tab) * (size[0] + 1)))))
    { stift_error(Malloc, "matrix in matrix init"); }
    j = 0;
    while (j < size[0])
    { k = 0;
      while (++k < 10)
      { BZE(matrix[i][j].attr[k], 8); }
      CPY(*(matrix[i][j].attr), "\033[0m");
      matrix[i][j].c = ' ';
      j += 1; }
    i += 1; }
  return (matrix); }
