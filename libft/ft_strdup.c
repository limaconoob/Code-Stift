/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 03:17:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 12:24:25 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../stift.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (s1 && (!(s2 = (char*)malloc(ft_strlen(s1) + 1))))
		stift_error(Malloc, "s2 in ft_strdup");
	else if (!s1 && (!(s2 = (char*)malloc(1))))
		stift_error(Malloc, "s2 in ft_strdup");
	if (s1)
	{
		i = 0;
		while (s1[i])
		{
			s2[i] = (char)s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		*s2 = 0;
	return (s2);
}
