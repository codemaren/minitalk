/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:03:39 by kilangov          #+#    #+#             */
/*   Updated: 2024/11/05 19:03:41 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	setup_signals_serv(void)
{
	struct sigaction	sigproc;

	sigemptyset(&sigproc.sa_mask);
	sigaddset(&sigproc.sa_mask, SIGUSR1);
	sigaddset(&sigproc.sa_mask, SIGUSR2);
	sigproc.sa_flags = SA_SIGINFO;
	sigproc.sa_sigaction = process_signal_server;
	if (sigaction(SIGUSR1, &sigproc, NULL) == -1
		|| sigaction(SIGUSR2, &sigproc, NULL) == -1)
		return (print_error(errno, 'A'), 0);
	return (1);
}

static void	print_reset(unsigned char *message, int *byte_count, pid_t c_pid)
{
	ft_printf("%s\n", message);
	if (kill(c_pid, SIGUSR2) == -1)
		print_error(errno, 'S');
	*byte_count = 0;
	ft_bzero(message, MAX_MESSAGE_LENGTH);
}

void	process_signal_server(int signum, siginfo_t *info, void *context)
{
	static unsigned char	message[MAX_MESSAGE_LENGTH];
	static int				bit;
	static int				byte_count;

	(void)context;
	if (signum == SIGUSR1)
		message[byte_count] = message[byte_count] | (1 << (7 - bit));
	else if (signum == SIGUSR2)
		message[byte_count] = message[byte_count] & ~(1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (message[byte_count] == '\0')
			print_reset(message, &byte_count, info->si_pid);
		else
			byte_count++;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		print_error(errno, 'S');
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
		return (ft_printf("Error: Failed to get PID\n"), 1);
	ft_printf("Server PID: %d\n", pid);
	if (!setup_signals_serv())
		return (1);
	while (1)
		pause();
	return (0);
}
