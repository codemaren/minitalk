/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:27:37 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/19 19:12:07 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (*big && len >= ft_strlen(little))
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0'
			&& big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *haystack = "hello world how are you";
	const char *needle = "";
	
	size_t len = 5;
	char *result_sys = strnstr(haystack, needle, len);
	char *result_fnc = ft_strnstr(haystack, needle, len);

	printf("strnstr returns:%s\n", result_sys);
	printf("ft_strnstr returns:%s\n", result_fnc);
	return (0);
}
*/
/*How the system strnstr behaves:
returns null if needle is not null terminated.
return null if needle is not found
returns haystack if needle is empty
returns null if len is 0
segmentation fault if NULL Pointer */
