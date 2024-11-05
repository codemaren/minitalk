/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:50:23 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/31 16:57:15 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s2));
	if (!*s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = (char *)malloc(len + 1);
	if (joinstr == NULL)
		return (NULL);
	ft_strlcpy(joinstr, s1, len + 1);
	ft_strlcat(joinstr, s2, len + 1);
	return (joinstr);
}
