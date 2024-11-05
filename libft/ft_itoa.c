/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:37:54 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/02 21:58:14 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

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

static char	*convert(int n, char *string, int bytes)
{
	string[bytes--] = '\0';
	if (n == INT_MIN)
	{
		string[bytes--] = '8';
		n /= 10;
	}
	if (n < 0)
		n = -n;
	while (bytes >= 0)
	{
		string[bytes--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		bytes;
	char	*string;

	bytes = count_digits(n);
	if (n < 0)
		bytes += 1;
	string = (char *)malloc(sizeof(char) * (bytes + 1));
	if (string == NULL)
		return (NULL);
	if (n < 0)
		string[0] = '-';
	else if (n == 0)
	{
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	convert (n, string, bytes);
	return (string);
}
