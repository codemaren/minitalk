/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:22:46 by kilangov          #+#    #+#             */
/*   Updated: 2024/07/02 20:22:50 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			total_memory;
	size_t			i;
	unsigned char	*p;

	total_memory = nmemb * size;
	if (size != 0 && total_memory / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(total_memory);
	if (ptr == NULL)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < total_memory)
		p[i++] = '\0';
	return (ptr);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen_gnl(s);
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = "";
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	joinstr = ft_calloc_gnl(len + 1, sizeof(char));
	if (joinstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		joinstr[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joinstr[j++] = s2[i++];
	joinstr[j] = '\0';
	return (joinstr);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (0);
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
