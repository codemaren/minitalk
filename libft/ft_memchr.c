/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:10:56 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/25 22:42:57 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*src;
	unsigned char		needle;

	needle = (unsigned char)c;
	src = (unsigned const char *)s;
	while (n-- > 0)
	{
		if (*src == needle)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
