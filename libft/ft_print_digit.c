/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:28:22 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/17 03:37:39 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count += 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_print_digit(const char **s, int number, int *count)
{
	ft_putnbr_fd(number, 1);
	(*count) += count_digits(number);
	(*s) += 2;
}
