/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:03:07 by ynachat           #+#    #+#             */
/*   Updated: 2024/05/09 03:34:11 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct variables
{
	int		cnt;
	int		byte;
	pid_t	pid;
}	t_variable;

int		ft_atoi(const char *str);

#endif
