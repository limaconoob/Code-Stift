/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stift_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:38:19 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/16 08:23:09 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include "libft.h"

void		stift_warning(int type, char *prob)
{ ft_putstr_fd("Warnung: ", 2);
  ft_putstr_fd(prob, 2);
	if (type == MissingFile)
  { ft_putstr_fd(": Kein Datei oder Ordner", 2); }
  else if (type == Access)
  { ft_putstr_fd(": Zugang ist verboten", 2); }
  else if (type == TooMuchWindows)
  { ft_putstr_fd(": Können nicht mehr als 8 Fenster öffnen", 2); }
  else if (type == TermEdit)
  { ft_putstr_fd(": Können nicht das Terminal bearbeiten", 2); }
  else if (type == EmptyName)
  { ft_putstr_fd("Können nicht bearbeiten ein Datei mit leere Name", 2); }
  ft_putchar_fd('\n', 2);}
