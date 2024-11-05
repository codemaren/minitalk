/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:58:08 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 13:02:20 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= -1 && c <= 255)
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
		else
			return (c);
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_tolower(67));
}
First check is for Unsigned char and EOF*/
