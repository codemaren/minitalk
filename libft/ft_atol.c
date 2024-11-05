/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:05 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 20:20:15 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c > 8 && c < 14) || c == 32);
}

static long	ft_process_digits(const char *nptr, int *i, int sign)
{
	long	result;

	result = 0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		result = (result * 10) + (nptr[*i] - '0');
		if ((sign == 1 && result > 2147483647) || (sign == -1
				&& result > 2147483648))
			return (2147483648);
		(*i)++;
	}
	return (result * sign);
}

long	ft_atol(const char *nptr)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_process_digits(nptr, &i, sign));
}

/*
int	main(void)
{
	char	nptr[] = "-2147483647fgfsfg233";
	int	value;

	value = ft_atoi(nptr);
	printf("%d \n", value);
	printf("%d", atoi(nptr));
	return (0);
}
*/
