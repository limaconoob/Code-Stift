/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 01:36:31 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/16 10:07:47 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include "libft.h"

int main(int argc, char **argv)
{ t_term *coucou;
  if (argc == 1)
  { stift_error(NoInputFile, "./stift"); }
  ft_signal();
  term_init();
  coucou = coucou_init(argv);
  wind_init(&(argv[1]), coucou);
/*  int o;
  int i;
  int j;
  o = -1;
  while (coucou->wind[++o])
  { i = -1;
    while (coucou->wind[o]->matrix[++i])
    { j = -1;
      while (coucou->wind[o]->matrix[i][++j].c)
      { printf("[%c] ", coucou->wind[o]->matrix[i][j].c); }
      printf("\n"); }
    printf("\n"); }*/
  ft_putchar('\n');
  term_init();
  return (0); }
