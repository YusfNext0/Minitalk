/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:15:01 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/09 03:34:05 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct variables
{
	int				cnt;
	int				byte;
	pid_t			pid;
	int				i;
	int				k;
	unsigned char	saver[4];
	int				x;
}	t_variable;

int		ft_atoi_bonus(const char *str);
void	ft_putchar_bonus(int c);
void	ft_putnbr_bonus(int n);

#endif
