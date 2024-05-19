/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:42:47 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/09 03:34:00 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr_bonus(int n)
{
	unsigned int	x;

	x = 0;
	if (n >= 0)
	{
		x = n;
	}
	else
	{
		ft_putchar_bonus('-');
		x = n * -1;
	}
	if (x <= 9)
	{
		ft_putchar_bonus(x + 48);
	}
	else
	{
		ft_putnbr_bonus(x / 10);
		ft_putnbr_bonus(x % 10);
	}
}
