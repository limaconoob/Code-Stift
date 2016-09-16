/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jy_pui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:33:09 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 10:02:47 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		jy_pui(int n, int pui)
{
	if (pui < 0 && n != 0)
		return (1 / (n * jy_pui(n, pui++)));
	if (pui == 0)
		return (1);
	if (pui == 1)
		return (n);
	if (pui > 0)
		return (n * jy_pui(n, pui--));
	return (0);
}
