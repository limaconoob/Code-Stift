/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:10:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/13 10:16:45 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

void command_line(t_term *coucou)
{ char buf[12];
  int k;
  int i;
  int j;
  int coord[2];
  static int flag = 0;
  BZE(buf, 12);
  while (read(0, buf, 12))
  { wind_clear(WIND, MATR);
    k = idle(buf, coucou);
    get_coords(coord, CURS, coucou);

    if (*buf == 'i')
    {
      ft_putchar('\n');
      ft_putstr("SIZE::");
      ft_putnbr(SIZE);
      ft_putstr(", mat_size::");
      ft_putnbr(coucou->mat_size);
      ft_putchar('\n');
      do_exit(coucou);
    }

    if (buf[2] == UNT && CURS[1] < WIND[1] + WIND[3] - 4 && CURS[0] + coucou->size_max < WIND[0] + WIND[2] && MAPP[coord[1]][coord[0] + 1])
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      CURS[1]++; }

    else if (buf[2] == TOP && CURS[1] > WIND[1] + 3 && CURS[0] - ((coucou->size_max + 3) > WIND[0] || CURS[0] < (coucou->size_max + 3)) && (CURS[0] > WIND[0] + 2 || CURS[1] > WIND[1] + 3))
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      CURS[1]--; }

//------------------------------------------------------------------------------
    else if (buf[2] == REC || (buf[2] == UNT && (CURS[1] == WIND[1] + WIND[3] - 4 || !MAPP[coord[1]][coord[0] + 1])))
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      if (buf[2] == UNT)
      { CURS[1] = WIND[1] + 3; }
      if (CURS[0] + (2 * coucou->size_max) + 3 < WIND[0] + WIND[2] && coord[1] != coucou->nb_col - 2)
      { CURS[0] += coucou->size_max + 3; }
      else if (CURS[0] + WIND[4] + (2 * coucou->size_max) + 5 < SIZE)
      { WIND[4] += coucou->size_max + 3; }
      else if (buf[2] == UNT && (coord[1] == coucou->nb_col - 2 || MAPP[coord[1]][coord[0] + 1]))
      { CURS[0] = WIND[0] + WIND[2] - coucou->size_max - 2;
        WIND[4] = SIZE - WIND[2]; }
      else if (buf[2] == REC && coord[1] == coucou->nb_col - 2 && MAPP[coord[1] + 1][coord[0]])
      { CURS[0] = WIND[0] + WIND[2] - coucou->size_max - 2;
        WIND[4] = SIZE - WIND[2]; }
      else if (buf[2] == REC && coord[1] == coucou->nb_col - 2)
      { int i = 0;
        while (MAPP[coucou->nb_col - 1][i])
        { i += 1; }
        CURS[1] = i + WIND[1] + 2;
        CURS[0] = WIND[0] + WIND[2] - (coucou->size_max + 2);
        WIND[4] = SIZE - WIND[2]; }
      else
      { WIND[4] = 0;
        CURS[0] = 2; }}
    else if (buf[2] == LIN || (buf[2] == TOP && CURS[1] == WIND[1] + 3))
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      if (buf[2] == TOP)
      { CURS[1] = WIND[1] + WIND[3] - 4; }
      if (CURS[0] - (coucou->size_max + 3) > WIND[0])
      { CURS[0] -= coucou->size_max + 3; }
      else if (WIND[4] - (coucou->size_max + 3) > 0)
      { WIND[4] -= coucou->size_max + 3; }
      else if (WIND[4] > 0)
      { WIND[4] = 0;
        CURS[0] = 2; }
      else
      { CURS[0] = WIND[0] + WIND[2] - (coucou->size_max + 2);
        WIND[4] = SIZE - WIND[2];
        if (buf[2] == TOP || (!MAPP[coucou->nb_col - 1][coord[0]]))
        { int i = 0;
          while (MAPP[coucou->nb_col - 1][i])
          { i += 1; }
          CURS[1] = i + WIND[1] + 2; }}}

//------------------------------------------------------------------------------

/*        
    else if (buf[2] == LIN && WIND[4] - WIND[2] + 2 >= 0)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] -= (WIND[2] / coucou->nb_col) * coucou->size_max - 2; }
    else if (buf[2] == REC && WIND[4] + (2 * WIND[2]) - 2 <= SIZE)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] += (WIND[2] / coucou->nb_col) * coucou->size_max - 2; }

    else if (buf[2] == LIN)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] = 0; }
    else if (buf[2] == REC)
    { BZE(MAPP[coord[1]][coord[0]]->attr[1], 8);
      WIND[4] = SIZE - WIND[2]; }
*/
  
    // REDIMENSIONNEMENT
    //WIND[0]++
    else if (*buf == 'a')
    { SLID[0] += 1;
      CURS[0] += 1;
      j = WIND[1] - 2;
      while (++j < WIND[1] + WIND[3] - 1)
      { go_to(WIND[0], j);
        i = -1;
        while (++i < 10)
        { ft_putstr_fd(MATR[j][WIND[4]].attr[i], 2); }
        ft_putchar_fd(MATR[j][WIND[4]].c, 2); }
      WIND[0] += 1;
      WIND[4] += 1;
      WIND[2] -= 1; }

    //WIND[1]++
    else if (*buf == 'z')
    { CURS[1] += 1;
      go_to(WIND[0], WIND[1] - 1);
      j = WIND[4] - 1;
      while (++j < WIND[2] + WIND[4])
      { i = -1;
        while (++i < 10)
        { ft_putstr_fd(MATR[WIND[1] - 1][j].attr[i], 2); }
        ft_putchar_fd(MATR[WIND[1] - 1][j].c, 2); }
      WIND[1] += 1; }

    //WIND[2]--
    else if (*buf == 'e')
    { j = WIND[1] - 2;
      while (++j < WIND[1] + WIND[3] - 1)
      { go_to(WIND[0] + WIND[2] - 1, j);
        ft_putstr_fd("\033[0m ", 2); }
      WIND[2] -= 1; }

    //WIND[3]--
    else if (*buf == 'r')
    { if (WIND[3] > 7)
      { SLID[1] -= 1;
        go_to(WIND[0], WIND[1] + WIND[3] - 2);
        j = WIND[4] - 1;
        while (++j < WIND[2] + WIND[4])
        { i = -1;
          while (++i < 10)
          { ft_putstr_fd(MATR[WIND[1] + WIND[3] - 2][j].attr[i], 2); }
          ft_putchar_fd(MATR[WIND[1] + WIND[3] - 2][j].c, 2); }
        WIND[3] -= 1; }}

    // SLIDE
    else if (k == 4 && ((MOUS[2] & 0x7FFF) == LCK || (MOUS[2] & 0x7FFF) == DDL) && MOUS[1] == WIND[1] + WIND[3] - 2 && MOUS[0] > SLID[0] && MOUS[0] <= SLID[0] + SLID[2])
    { ; }
//    { slide(coucou); }

    // MOUSE (select)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK /*|| (MOUS[2] & 0x7FFF) == DDL)*/ && !(MOUS[2] & 0x8000) && MOUS[1] > WIND[1] + 2 && MOUS[1] < WIND[1] + WIND[3] - 1)
    { select_ret(coucou, 1); }

    // SPACE (select)
    else if (*buf == ' ')
    { select_ret(coucou, 0); }

    // MOUSE (quit)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && !(MOUS[2] & 0x8000) && MOUS[1] == WIND[1] + 1 && MOUS[0] > WIND[0] + 1 && MOUS[0] <= WIND[0] + 4)
    { flag ^= 0x0001; }

    // MOUSE (quit)
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && MOUS[1] == WIND[1] + 1 && MOUS[0] > WIND[0] + 1 && MOUS[0] <= WIND[0] + 4 && (flag & 0x0001))
    { go_to(WIND[0], WIND[1] - 1);
      windower(WIND, MATR);
      break ; }

    // REMOVE (select)
    else if (k == 3)
    { remove_file(coucou, coord[0], coord[1]); }

    // UNQUIT
    else if (k == 4 && (MOUS[2] & 0x7FFF) == LCK && (flag & 0x0001))
    { flag &= 0xFFFE; }

    // ESCAPE (quit)
    else if (k == 8 || *buf == '\n')
    { go_to(WIND[0], WIND[1] - 1);
      windower(WIND, MATR);
      break ; }

    get_coords(coord, CURS, coucou);
    if (MAPP[coord[1]][coord[0]]->coord[0] < WIND[4])
    { CURS[0] += coucou->size_max; }
    else if (MAPP[coord[1]][coord[0]]->coord[0] > WIND[4] + WIND[2])
    { CURS[0] -= coucou->size_max; }

    if (WIND[4] + WIND[2] > SIZE)
    { if (WIND[4] + WIND[2] > TERM[0])
     { WIND[4] = SIZE - WIND[2]; }
      else
      { windower(WIND, MATR);
        WIND[4] = 0;
        WIND[2] = SIZE; }}

    init_wind(WIND, MATR, coucou);

    if (*buf == 'y')
    { int v;
      int w;
      go_to(WIND[2] - 1, WIND[3] - 1);
      ft_putchar_fd('\n', 2);
      v = -1;
      while (MATR[++v])
      { w = -1;
        while (++w < coucou->mat_size)
        { ft_putchar_fd(MATR[v][w].c, 2); }
        ft_putchar_fd('$', 2);
        ft_putchar_fd('\n', 2); }
      do_exit(coucou); }

    if (*buf == 'u')
    { int v;
      int w;
      go_to(WIND[2] - 1, WIND[3] - 1);
      ft_putchar_fd('\n', 2);
      v = -1;
      while (MAPP[++v])
      { w = -1;
        while (MAPP[v][++w])
        { ft_putstr_fd("map[", 2);
          ft_putnbr_fd(MAPP[v][w]->coord[0], 2);
          ft_putstr_fd("][", 2);
          ft_putnbr_fd(MAPP[v][w]->coord[1], 2);
          ft_putstr_fd("]::", 2);
          ft_putendl_fd(MAPP[v][w]->name, 2); }
        ft_putchar_fd('$', 2);
        ft_putchar_fd('\n', 2); }
      do_exit(coucou); }

    go_to(WIND[0], WIND[1] - 1);
    windower(WIND, MATR);
    BZE(buf, 12); }}
