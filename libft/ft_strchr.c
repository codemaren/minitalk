/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:08:00 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/18 20:59:11 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*returns  a  pointer to the first occurrence 
of the character c in the string s.*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* 
s != NULL checks if the pointer s has been referenced/initialized. 
See if it is a empty pointer
c is passed as an integer. So type casting it back to a char, 
makes sure the comparison is accurate. Making it unsigned char, wraps
the int around the max ASCII (0 - 256). eg. int c = 300 -> ASCII 44
*/
