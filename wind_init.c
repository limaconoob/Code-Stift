/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wind_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 10:18:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 12:39:10 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include "libft.h"
#include <sys/stat.h>

#define ISDIR (!(((sb.st_mode | 4095) - 4095) - S_IFDIR))

typedef struct s_catch
{ char *line;
  struct s_catch *next;
} t_catch;

static int (*(get_fds)(char **argv, t_term *coucou))[8]
{ int i;
  static int fds[8];
  int fd;
  struct stat sb;
  i = 0;
  BZE(fds, 8 * sizeof(int));
  while (argv[i])
  { if ((fd = open(argv[i], O_RDWR)) > 2)
    { if (coucou->nb_wind == 8)
      { close(fd);
        stift_warning(TooMuchWindows, "./Code-stift"); 
        break ; }
      fds[coucou->nb_wind] = fd;
      printf("name::%s, fds[%d]::%d\n", argv[i], coucou->nb_wind, fd);
      coucou->nb_wind += 1; }
    else if (lstat(argv[i], &sb) != -1)
    { if (!ISDIR)
      { stift_warning(Access, argv[i]); }
      else
      { ; /* GET_DIRECTORY AVEC FT_SELECT (USAGE DE FORK & EXECVE) */ }}
    else if (fd < 0)
    { stift_warning(MissingFile, argv[i]); }
    else
    { stift_warning(TermEdit, argv[i]); }
    argv[i] = NULL;
    i += 1; }
  if (!(coucou->nb_wind))
  { stift_error(NoInputFile, "./stift"); }
  return (&fds); }

static t_catch *new_catch(char *line)
{ t_catch *tmp;
  if (!((tmp = (t_catch*)malloc(sizeof(t_catch)))))
  { stift_error(Malloc, "tmp in new_catch"); }
  tmp->line = ft_strdup(line);
  tmp->next = NULL;
  return (tmp); }

static t_wind *new_wind(int fd, char *name)
{ t_wind *new;
  char *line;
  t_catch *stock[1];
  t_catch *tmp;
  int i;
  int j;
  if (!((new = (t_wind*)malloc(sizeof(t_wind)))))
  { stift_error(Malloc, "new in new_wind"); }
  new->name = name;
  new->fd = fd;
  BZE(new->info, 2 * sizeof(int));
  BZE(new->wind, 6 * sizeof(int));
  BZE(new->slide, 3 * sizeof(int));
  *stock = NULL;
  while (get_next_line(fd, &line))
  { if (LEN(line) > (size_t)new->info[0])
    { new->info[0] = LEN(line) + 1; }
    new->info[1] += 1;
    if (*stock)
    { tmp->next = new_catch(line);
      tmp = tmp->next; }
    else
    { tmp = new_catch(line);
      *stock = tmp; }}
  new->matrix = matrix_init(new->info);
  i = 0;
  tmp = *stock;
  while (tmp)
  { j = 0;
    while (tmp->line[j])
    { new->matrix[i][j].c = tmp->line[j];
      j += 1; }
    i += 1;
    tmp = tmp->next; }
  return (new); }

void wind_init(char **argv, t_term *coucou)
{ int i;
  static int (*fds)[8];
  fds = get_fds(argv, coucou);
  if (!((coucou->wind = (t_wind**)malloc(sizeof(t_wind*) * (coucou->nb_wind + 1)))))
  { stift_error(Malloc, "coucou->wind in wind_init"); }
  i = 0;
  while (i < coucou->nb_wind)
  { while (argv && !(*argv))
    { argv++; }
    coucou->wind[i] = new_wind((*fds)[i], *argv);
    i += 1; }}
