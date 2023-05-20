/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:04:12 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/05/19 18:04:15 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	mn_atoi(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	count;
	int	i;

	if (ac != 3)
		return (1);
	pid = mn_atoi(av[1]);
	if (pid <= 0)
		return (1);
	i = 0;
	while (av[2][i])
	{
		count = 7;
		while (count >= 0)
		{
			if (av[2][i] & 1 << count)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			count--;
			usleep(200);
		}
		i++;
	}
	return (0);
}
