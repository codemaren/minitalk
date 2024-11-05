/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:03:51 by kilangov          #+#    #+#             */
/*   Updated: 2024/11/05 19:03:53 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <errno.h>

void	print_error(int error_code, char flag)
{
	char	*str;

	if (flag == 'C')
		str = "Client";
	else if (flag == 'S')
		str = "Server";
	else if (flag == 'A')
		str = "Sigaction";
	if (error_code == EINVAL)
		ft_printf("%s Error: Invalid argument\n", str);
	else if (error_code == EPERM)
		ft_printf("%s Error: Bad address\n", str);
	else if (error_code == ESRCH)
		ft_printf("%s Error: No such process\n", str);
	else
		ft_printf("Error: Unknown error occurred\n");
}
