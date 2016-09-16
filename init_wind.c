/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 05:52:25 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/16 09:51:40 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

#include <fcntl.h>

void init_char(char c, t_tab *ceil, char attr[10][8])
{ int k;
  k = -1;
  while (++k < 10)
  { CPY(ceil->attr[k], attr[k]); }
  ceil->c = c; }

static void the_char(int i, int j, char c, t_tab *matrix)
{ static char attr[10][8] = {"\033[0m", "", "", "", "", "", "", "", "", ""};
  init_char(c, &(matrix[i]), attr) ;
  init_char(c, &(matrix[j]), attr) ; }

static void put_slide(int *wind, t_tab **matrix, int *slide)
{ int i;
  i = -1;
  while (++i < slide[2])
  { CPY(matrix[slide[1]][wind[4] + slide[0] + i].attr[2], "\033[47m"); }}

void init_wind(int *wind, t_tab **matrix, int *slide)
{ int i;
  int j;
  i = wind[1] - 1;
  j = wind[4];
  wind_line("+---,", i, &j, matrix);
  while (j < (wind[2] / 2) - 1 + wind[4])
  { matrix[i][j++].c = '-'; }
  wind_line((wind[2] + wind[0]) % 2 == 0 ? ",," : ",,,", i, &j, matrix);
  while (j < wind[2] + wind[4] - 1)
  { matrix[i][j++].c = '-'; }
  matrix[i][j].c = '+';
  j = wind[4] + 5;
  while (j < wind[2] + wind[4] - 1)
  { matrix[i + 1][j].c = ' ';
    matrix[i + 2][j++].c = ' '; }
  j = wind[4];
  wind_line("| X |", ++i, &j, matrix);
  matrix[i][wind[2] + wind[4] - 1].c = '|';
  j = wind[4];
  wind_line("|---'", ++i, &j, matrix);
  matrix[i][wind[2] + wind[4] - 1].c = '|';
  j = wind[2] + wind[4] - 1;
  while (i < wind[3] - 3)
  { the_char(wind[4], j, '|', matrix[++i]); }
  matrix[wind[3] / 2][wind[4]].c = '[';
  matrix[wind[3] / 2][j].c = ']';
  the_char(wind[4], j, '|', matrix[i]);
  j = wind[4] + 1;
  while (j < wind[2] + wind[4] - 1)
  { matrix[i][j++].c = '_'; }
  put_slide(slide);
  the_char(wind[4], j, '|', matrix[++i]);
  the_char(wind[4], j, '+', matrix[++i]);
  j = wind[4] + 1;
  while (j < (wind[2] / 2) - 1 + wind[4])
  { matrix[i][j++].c = '-'; }
  wind_line((wind[2] + wind[0]) % 2 == 0 ? "''" : "'''", i, &j, matrix);
  while (j < wind[2] + wind[4] - 1)
  { matrix[i][j++].c = '-'; }}
