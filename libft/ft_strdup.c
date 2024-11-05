/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:58:55 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/26 21:27:16 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupstr;
	size_t	strlen;
	size_t	i;

	strlen = ft_strlen(s) + 1;
	dupstr = (char *)malloc(sizeof(char) * strlen);
	if (dupstr != NULL)
	{
		i = 0;
		while (s[i])
		{
			dupstr[i] = s[i];
			i++;
		}
		dupstr[i] = '\0';
		return (dupstr);
	}
	return (NULL);
}
