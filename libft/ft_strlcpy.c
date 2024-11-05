/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:14:29 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/19 21:21:35 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <bsd/string.h>
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
		j++;
	if (size <= 0)
		return (j);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*
int	main(void)
{
	char dst[20];
	char *src = "BBBB";
	
	memset(dst,'A', 20);
	size_t rv_ft = ft_strlcpy(dst, src, 20);
	printf("Return value of ft_strlcpy:%zu\n", rv_ft);
	printf("Copied destination string = %s\n", dst);

	char dst_sys[20];
	memset(dst_sys,'A', 20);
	size_t rv_sys = strlcpy(dst_sys, src, 20);
	printf("Return value of strlcpy:%zu\n", rv_sys);
	printf("Copied destination string = %s\n", dst_sys);
	return (0);
}
*/
