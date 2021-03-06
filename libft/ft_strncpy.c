/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:43:12 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/11 20:52:20 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *d;

	d = dst;
	while (*src && n > 0)
	{
		*d = *src;
		src++;
		d++;
		n--;
	}
	while (n > 0)
	{
		*d = '\0';
		d++;
		n--;
	}
	return (dst);
}
