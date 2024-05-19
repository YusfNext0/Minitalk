/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:13:48 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/10 19:23:51 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_pid(int *nb_bi, siginfo_t *info, t_variable *v)
{
	if (v->pid != info->si_pid)
	{
		v->byte = 0;
		v->cnt = 0;
		*nb_bi = 1;
		v->i = 0;
		v->k = 0;
		v->x = 1;
		v->pid = info->si_pid;
	}
}

void	check_write(t_variable *v)
{
	if (v->x == 1)
	{
		if (v->byte >= 240)
			v->k = 4;
		else if (v->byte >= 224)
			v->k = 3;
		else if (v->byte >= 192)
			v->k = 2;
		v->x = 0;
	}
	if (v->i < v->k)
		v->saver[v->i++] = v->byte;
	if (!v->k)
	{
		write(1, &v->byte, 1);
		v->x = 1;
	}
	else if (v->i == v->k)
	{
		write (1, &v->saver, v->k);
		v->x = 1;
		v->i = 0;
		v->k = 0;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static t_variable	v;
	static int			nb_bi = 1;

	v.x = 1;
	check_pid(&nb_bi, info, &v);
	(void)context;
	if (v.cnt < 8)
	{
		if (signum == SIGUSR1)
			v.byte += 0;
		else if (signum == SIGUSR2)
			v.byte += nb_bi;
		nb_bi *= 2;
		v.cnt++;
	}
	if (!v.byte && v.cnt == 8)
		kill(v.pid, SIGUSR1);
	else if (v.cnt == 8)
	{
		check_write(&v);
		v.cnt = 0;
		v.byte = 0;
		nb_bi = 1;
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	if (ac == 1)
	{
		(void)av[1];
		sa.sa_sigaction = sig_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		write (1, "this is the pid of Server : ", 29);
		ft_putnbr_bonus(getpid());
		write (1, "\n", 1);
		while (1)
			pause();
	}
	else
		exit(write(STDERR_FILENO, "Error\n", 7));
	return (0);
}
