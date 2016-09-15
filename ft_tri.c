/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 06:00:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/08/31 10:15:37 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_tri(char **tab)
{ int i;
  char *tmp;
  if (!tab || !tab[0] || !tab[1])
  { return ; }
  i = 0;
  while (tab[i + 1])
  { if (ft_strcmp(tab[i], tab[i + 1]) > 0)
    { tmp = tab[i];
      tab[i] = tab[i + 1];
      tab[i + 1] = tmp; 
      i = i ? i - 1 : 0; }
    else
    { i++; }}}
