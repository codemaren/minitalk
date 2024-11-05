/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:22 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/17 18:09:05 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hexanbr(unsigned long hexa, int fd, int *count)
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

static void	print_hexa(const char **s, unsigned long hexa, int *count)
{
	(*count)++;
	put_hexanbr(hexa, 1, count);
	(*s) += 2;
}

void	ft_print_ptr(const char **s, void *ptr, int *count)
{
	unsigned long	memory_add;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		*count += ft_strlen("(nil)");
		(*s) += 2;
		return ;
	}	
	if (ptr != 0)
	{
		ft_putstr_fd("0x", 1);
		*count += 2;
	}
	memory_add = (unsigned long)ptr;
	print_hexa(s, memory_add, count);
}
