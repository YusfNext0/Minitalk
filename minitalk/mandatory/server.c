/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:33:24 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/10 12:12:29 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_pid(int *nb_bi, siginfo_t *info, t_variable *v)
{
	if (v->pid != info->si_pid)
	{
		v->byte = 0;
		v->cnt = 0;
		*nb_bi = 1;
		v->pid = info->si_pid;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static t_variable	v;
	static int			nb_bi = 1;

	(void)context;
	check_pid(&nb_bi, info, &v);
	if (v.cnt < 8)
	{
		if (signum == SIGUSR1)
			v.byte += 0;
		else if (signum == SIGUSR2)
			v.byte += nb_bi;
		nb_bi *= 2;
		v.cnt++;
	}
	if (v.cnt == 8)
	{
		write(1, &v.byte, 1);
		v.cnt = 0;
		v.byte = 0;
		nb_bi = 1;
	}
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	x;

	x = 0;
	if (n >= 0)
	{
		x = n;
	}
	else
	{
		ft_putchar('-');
		x = n * -1;
	}
	if (x <= 9)
	{
		ft_putchar(x + 48);
	}
	else
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac == 1)
	{
		(void)av[1];
		sa.sa_sigaction = sig_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		write (1, "this is the pid of Server : ", 29);
		pid = getpid();
		ft_putnbr(pid);
		write (1, "\n", 1);
		while (1)
			pause();
	}
	else
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (0);
}
