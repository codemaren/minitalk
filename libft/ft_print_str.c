/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:37:55 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/16 22:50:16 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str(const char **s, char *str, int *count)
{
	int	len;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*count += ft_strlen("(null)");
		(*s) += 2;
		return ;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	(*count) += len;
	(*s) += 2;
}
