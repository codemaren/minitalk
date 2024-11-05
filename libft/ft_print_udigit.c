/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 05:52:26 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/17 06:02:20 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_digits(unsigned int n)
{
	unsigned int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

void	ft_print_udigit(const char **s, unsigned int number, int *count)
{
	putunbr_fd(number, 1);
	(*count) += count_digits(number);
	(*s) += 2;
}
