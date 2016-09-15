/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wind_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 05:04:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/09 05:42:33 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

void wind_line(char *str, int i, int *j, t_tab **matrix)
{ int k;
  if (!str || !matrix)
  { return ; }
  k = -1;
  while (str[++k])
  { matrix[i][*j + k].c = str[k]; }
  *j += k; }
