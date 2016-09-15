/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stift_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:38:19 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 08:42:50 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include "libft.h"

void		stift_warning(int type, char *prob)
{
	ft_putstr_fd("\nWarnung: ", 2);
	if (type == 0)
    ft_putstr_fd(prob, 2);
}
