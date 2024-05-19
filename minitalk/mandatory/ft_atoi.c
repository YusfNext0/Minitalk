/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:41:32 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/09 01:01:50 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
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
