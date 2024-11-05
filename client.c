/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:03:28 by kilangov          #+#    #+#             */
/*   Updated: 2024/11/05 19:03:32 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_rcv_flag;

static int	setup_signals_client(void)
{
	struct sigaction	sigproc;

	sigemptyset(&sigproc.sa_mask);
	sigaddset(&sigproc.sa_mask, SIGUSR1);
	sigaddset(&sigproc.sa_mask, SIGUSR2);
	sigproc.sa_flags = 0;
	sigproc.sa_handler = process_signal_client;
	if (sigaction(SIGUSR1, &sigproc, NULL) == -1
		|| sigaction(SIGUSR2, &sigproc, NULL) == -1)
		return (print_error(errno, 'A'), 0);
	return (1);
}

void	process_signal_client(int signum)
{
	if (signum == SIGUSR1)
		g_rcv_flag = 1;
	if (signum == SIGUSR2)
		ft_printf("Server received message\n");
}

static int	send_message(int server_pid, char c, int bit)
{
	if ((c & (1 << bit)) != 0)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			return (print_error(errno, 'C'), 0);
	}
	else if (kill(server_pid, SIGUSR2) == -1)
		return (print_error(errno, 'C'), 0);
	return (1);
}

static int	process_message(int server_pid, char *message)
{
	int	bit;

	if (!message)
		return (0);
	while (1)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (!send_message(server_pid, *message, bit))
				return (0);
			while (!g_rcv_flag)
				pause();
			g_rcv_flag = 0;
			bit--;
		}
		if (*message == '\0')
			break ;
		message++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3 || !*argv[1] || !*argv[2])
		return (ft_printf("Client Error: Invalid arguments\n"), 1);
	if (ft_strlen(argv[2]) >= MAX_MESSAGE_LENGTH)
		return (ft_printf("Message exceeds MAX LENGTH\n"), 1);
	server_pid = ft_atol(argv[1]);
	if (server_pid <= 0 || server_pid > 2147483647)
		return (ft_printf("Client Error: Invalid server PID\n"), 1);
	if (kill(server_pid, 0) == -1)
		return (print_error(errno, 'C'), 1);
	if (!setup_signals_client())
		return (1);
	if (!process_message(server_pid, argv[2]))
		return (ft_printf("Client Error: Failed to send message\n"), 1);
	return (0);
}
