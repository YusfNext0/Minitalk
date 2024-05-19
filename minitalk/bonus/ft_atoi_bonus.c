/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:25:40 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/08 21:34:27 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi_bonus(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write (2, "Invalid PID\n", 13);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - 48);
	}
	if (num == 0)
		(write (2, "Invalid PID\n", 13), exit(1));
	return (num * sign);
}
