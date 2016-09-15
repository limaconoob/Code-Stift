/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 04:49:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/15 12:25:27 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stift.h"
#include <sys/ioctl.h>
#include <signal.h>

static void mutter_sig(int sig)
{/* struct winsize w;
  if (sig == SIGWINCH)
  { ioctl(0, TIOCGWINSZ, &w);
    get_size(w.ws_col, w.ws_row, NULL); }
  else*/ if (sig == SIGTSTP || sig == SIGINT)
  { term_init(); }}

void ft_signal(void)
{ signal(SIGWINCH, mutter_sig);
  signal(SIGTSTP, mutter_sig);
  signal(SIGINT, mutter_sig);
  signal(SIGQUIT, mutter_sig);
  signal(SIGCONT, mutter_sig); }
