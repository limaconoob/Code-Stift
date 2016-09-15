/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 02:31:10 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/12 01:49:27 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int fleche(char *buf, t_term *coucou)
{ (void)buf;
  (void)coucou;
  return (1); }
 /*   int fd = open("/dev/ttys007", O_WRONLY);
    ft_putstr_fd("WIND[4]::", fd);
    ft_putnbr_fd(WIND[4], fd);
    ft_putstr_fd(", WIND[2]::", fd);
    ft_putnbr_fd(WIND[2], fd);
    ft_putstr_fd(", size::", fd);
    ft_putnbr_fd(coucou->mat_size, fd);
    ft_putstr_fd(", nb_col::", fd);
    ft_putnbr_fd(coucou->nb_col, fd);
    ft_putstr_fd(", nb_files::", fd);
    ft_putnbr_fd(coucou->nb_files, fd);
    ft_putchar_fd('\n', fd);
    close(fd); */
