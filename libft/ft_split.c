/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:55:55 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/02 16:40:14 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!(s[i]))
			break ;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static char	**free_memory(char **ptrptr, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		free(ptrptr[i]);
		ptrptr[i] = NULL;
		i++;
	}
	free(ptrptr);
	ptrptr = NULL;
	return (NULL);
}

static char	**substring(char const *s, char c, char **ptrptr)
{
	size_t	i;
	size_t	start;
	size_t	word_count;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ptrptr[word_count] = ft_substr(s, start, i - start);
		if (ptrptr[word_count] == NULL)
			return (free_memory(ptrptr, word_count));
		word_count++;
	}
	ptrptr[word_count] = NULL;
	return (ptrptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptrptr;
	size_t	word_count;

	if (!s || !*s)
		return (NULL);
	word_count = count_splits(s, c);
	ptrptr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (ptrptr == NULL)
		return (NULL);
	return (substring(s, c, ptrptr));
}
