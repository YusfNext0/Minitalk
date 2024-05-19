/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:33:05 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/10 12:19:24 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	encrypte(unsigned char c, int pid)
{
	int				i;
	unsigned char	bit;
	int				mask;
	int				kill1;
	int				kill2;

	i = 8;
	bit = 0;
	mask = 0;
	kill1 = 0;
	kill2 = 0;
	while (i--)
	{
		bit = c & (1 << mask);
		if (bit == 0)
			kill1 = kill(pid, SIGUSR1);
		else
			kill2 = kill(pid, SIGUSR2);
		if (kill1 == -1 || kill2 == -1)
			(write(2, "invalid pid!!!\n", 16), exit(1));
		mask++;
		usleep(500);
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			encrypte((unsigned char )av[2][i], pid);
			i++;
		}
		encrypte('\n', pid);
		encrypte('\0', pid);
	}
	else
		exit(write(STDERR_FILENO, "Error\n", 7));
	return (0);
}
