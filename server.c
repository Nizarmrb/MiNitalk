/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:52:01 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/05/20 16:12:35 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count = 7;

void	signal_hundler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	newpid;
	static int	old_pid;

	newpid = info->si_pid;
	(void)context;
	if (newpid != old_pid)
	{
		newpid = info->si_pid;
		old_pid = newpid;
		c = 0;
		g_count = 7;
	}
	if (sig == SIGUSR2)
		c = c | (1 << g_count--);
	else
		g_count--;
	if (g_count == -1)
	{
		write(1, &c, 1);
		c = 0;
		g_count = 7;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	info;

	pid = getpid();
	ft_printf("Pid: %d\n", pid);
	info.sa_sigaction = signal_hundler;
	info.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1) ;
}