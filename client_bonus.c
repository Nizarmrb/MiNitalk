/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:35:53 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/05/20 18:04:56 by nelmrabe         ###   ########.fr       */
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

void	printmsg(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("msg received!\n");
}

void	send_char(char c, int pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if (c & 1 << count)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		count--;
		usleep(200);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	if (ac != 3)
		return (1);
	pid = mn_atoi(av[1]);
	if (pid <= 0)
		return (1);
	signal(SIGUSR1, printmsg);
	i = 0;
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
		if (av[2][i] == 0)
			send_char(av[2][i], pid);
	}
	return (0);
}
