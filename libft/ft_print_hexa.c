/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:07:03 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/17 13:28:08 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	put_hexanbr(unsigned int hexa, int fd, int *count)
{
	if (hexa > 15)
	{
		put_hexanbr((hexa / 16), fd, count);
		(*count)++;
	}
	if ((hexa % 16) < 10)
		ft_putchar_fd((hexa % 16 + '0'), fd);
	else
		ft_putchar_fd((hexa % 16 + 'a' - 10), fd);
}

void	ft_print_hexa(const char **s, unsigned int hexa, int *count)
{
	(*count)++;
	put_hexanbr(hexa, 1, count);
	(*s) += 2;
}
/*
static void	put_hexanbr(unsigned int hexa, int fd, int *count)
{
	char	digit;
	
	if (hexa > 15)
	{
		count++;
		put_hexanbr((hexa / 16), fd, count);
	}
	else
	{
		if ((hexa % 16) < 10)
			digit = (hexa % 16) + '0';
		else
			digit = (hexa % 16) + 'a' -10;
		write (fd, &digit, 1);
	}
}
*/
