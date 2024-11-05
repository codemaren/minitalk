/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:41:52 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/05 15:36:46 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

//char	wrapped_ft_toupper(unsigned int i, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_string;

	if ((!s) || (!f))
		return (NULL);
	new_string = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*
int	main(void)
{
	char *s1 = "Hel134World";
	char *s2 = ft_strmapi(s1, &wrapped_ft_toupper);
	
	printf("Edited String is:%s\n", s2);
	return (0);
}

char	wrapped_ft_toupper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}
*/
