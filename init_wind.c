/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 05:52:25 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/12 11:34:29 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

#include <fcntl.h>

void init_char(char c, t_tab *ceil, char attr[10][8])
{ int k;
  k = -1;
  while (++k < 10)
  { ft_strcpy(ceil->attr[k], attr[k]); }
  ceil->c = c; }

static void the_char(int i, int j, char c, t_tab *matrix)
{ static char attr[10][8] = {"\033[0m", "", "", "", "", "", "", "", "", ""};
  init_char(c, &(matrix[i]), attr) ;
  init_char(c, &(matrix[j]), attr) ; }

static void put_slide(t_term *coucou)
{ int i;
  i = -1;
  while (++i < SLID[2])
  { CPY(MATR[SLID[1]][WIND[4] + SLID[0] + i].attr[2], "\033[47m"); }}

static void put_cursor(t_term *coucou)
{ int coord[2];
  get_coords(coord, CURS, coucou);
  CPY(MAPP[coord[1]][coord[0]]->attr[1], "\033[4m");
  MATR[MAPP[coord[1]][coord[0]]->coord[1]][MAPP[coord[1]][coord[0]]->coord[0] - 1].c = '{';
  MATR[MAPP[coord[1]][coord[0]]->coord[1]][MAPP[coord[1]][coord[0]]->coord[0] + coucou->size_max].c = '}'; }

static void put_files(t_term *coucou)
{ int p;
  int q;
  int m;
  p = -1;
  while (MAPP[++p])
  { q = -1;
    while (MAPP[p][++q])
    { m = -1;
      while (MAPP[p][q]->name[++m])
      { init_char(MAPP[p][q]->name[m], &(MATR[MAPP[p][q]->coord[1]][MAPP[p][q]->coord[0] + m]), MAPP[p][q]->attr); }
      while (m < coucou->size_max)
      { if (MATR[MAPP[p][q]->coord[1]][MAPP[p][q]->coord[0] + m].c != '}')
        { init_char(' ', &(MATR[MAPP[p][q]->coord[1]][MAPP[p][q]->coord[0] + m]), MAPP[p][q]->attr); }
        m += 1; }}}}

void init_wind(int *wind, t_tab **matrix, t_term *coucou)
{ int i;
  int j;
  put_cursor(coucou);
  put_files(coucou);
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
  matrix[wind[3] / 2][WIND[4]].c = '[';
  matrix[wind[3] / 2][j].c = ']';
  the_char(wind[4], j, '|', matrix[i]);
  j = wind[4] + 1;
  while (j < wind[2] + wind[4] - 1)
  { matrix[i][j++].c = '_'; }
  put_slide(coucou);
  the_char(wind[4], j, '|', matrix[++i]);
  the_char(wind[4], j, '+', matrix[++i]);
  j = wind[4] + 1;
  while (j < (wind[2] / 2) - 1 + wind[4])
  { matrix[i][j++].c = '-'; }
  wind_line((wind[2] + wind[0]) % 2 == 0 ? "''" : "'''", i, &j, matrix);
  while (j < wind[2] + wind[4] - 1)
  { matrix[i][j++].c = '-'; }}
