/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:51:40 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/17 18:56:27 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hexa_capnbr(unsigned int hexa, int fd, int *count)
{
	if (hexa > 15)
	{
		put_hexa_capnbr((hexa / 16), fd, count);
		(*count)++;
	}
	if ((hexa % 16) < 10)
		ft_putchar_fd((hexa % 16 + '0'), fd);
	else
		ft_putchar_fd((hexa % 16 + 'A' - 10), fd);
}

void	ft_print_hexa_cap(const char **s, unsigned int hexa, int *count)
{
	(*count)++;
	put_hexa_capnbr(hexa, 1, count);
	(*s) += 2;
}
