/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:10:57 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 20:34:34 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (p1[i] != '\0' && p2[i] != '\0' && i < n -1)
	{
		if (p1[i] == p2[i])
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (p1[i] - p2[i]);
}
/*
int	main(void)
{
	char	*str1 = "abcdef";
 	char	*str2 = "abcdefghijklmnop";

	int rv_ft_strncmp = ft_strncmp(str1, str2, 6);
	int rv_strncmp = strncmp(str1, str2, 6);

	printf("ft_strncmp returns %d\n", rv_ft_strncmp);
	printf("strncmp returns %d\n", rv_strncmp);
	return (0);
}
*/
/* When either string is NULL, there is nothing to compare. 
   Same as when n=0. Hence, return is (0).*/
