/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 09:24:33 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/12 03:16:07 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"
#include <stdlib.h>

void free_matrix(t_tab **matrix)
{ int i;
  i = -1;
  while (matrix[++i])
  { free(matrix[i]); }
  free(matrix[i]);
  free(matrix); }
