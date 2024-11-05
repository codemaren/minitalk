/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:47:51 by kilangov          #+#    #+#             */
/*   Updated: 2024/07/07 17:47:55 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_static(char **temp)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen_gnl(*temp))
	{
		*temp[i] = '\0';
		i++;
	}
	return (*temp);
}

static char	*extract_line(char *temp, int type)
{
	size_t	i;
	char	*line;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (type == 1)
	{
		line = ft_substr_gnl(temp, 0, i + 1);
		if (line == NULL)
			return (NULL);
		return (line);
	}
	if (type == 2)
	{
		line = ft_substr_gnl(temp, i + 1, ft_strlen_gnl(temp) - i -1);
		if (line == NULL)
			return (NULL);
		return (line);
	}
	return (NULL);
}

static char	*fill_buffer(char *temp, int fd)
{
	ssize_t	read_size;
	char	*buffer;
	char	*new_temp;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_size = 1;
	while (!(ft_strchr_gnl(temp, '\n')) && !(read_size <= 0))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			zero_static(&temp);
			break ;
		}
		buffer[read_size] = '\0';
		new_temp = ft_strjoin_gnl(temp, buffer);
		if (new_temp == NULL)
			return (free(temp), free(buffer), NULL);
		free(temp);
		temp = new_temp;
	}
	return (free(buffer), buffer = NULL, temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*new_temp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = fill_buffer(temp, fd);
	if ((temp) && ft_strchr_gnl(temp, '\n'))
	{
		line = extract_line(temp, 1);
		new_temp = extract_line(temp, 2);
		if (!new_temp)
			return (free(line), NULL);
		free(temp);
		temp = new_temp;
		return (line);
	}
	if (temp && *temp)
		return (line = temp, temp = NULL, line);
	return (free(temp), temp = NULL, line);
}
