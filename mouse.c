/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:55:04 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/05 22:45:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

int mouse(char *buf, t_term *coucou)
{ int i;
  i = 3;
  coucou->mous[0] = 0;
  coucou->mous[1] = 0;
  coucou->mous[2] = 0;
  if (buf[1] == '[' && buf[2] == '<')
  { while (ft_isdigit(buf[i]))
    { coucou->mous[2] = (coucou->mous[2] * 10) + buf[i++] - '0'; }
    i++;
    while (ft_isdigit(buf[i]))
    { coucou->mous[0] = (coucou->mous[0] * 10) + buf[i++] - '0'; }
    i++;
    while (ft_isdigit(buf[i]))
    { coucou->mous[1] = (coucou->mous[1] * 10) + buf[i++] - '0'; }
    if (buf[i] == 'm')
    { coucou->mous[2] |= 0x8000; }
    return (1); }
  return (0); }
