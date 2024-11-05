/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:04:11 by kilangov          #+#    #+#             */
/*   Updated: 2024/11/05 19:04:13 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"

# define MAX_MESSAGE_LENGTH 1000

void	print_error(int error_code, char flag);
void	process_signal_server(int signum, siginfo_t *info, void *context);
void	process_signal_client(int signum);
#endif
