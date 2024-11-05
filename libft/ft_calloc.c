/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:21:33 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/26 17:45:54 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_memory;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_memory = nmemb * size;
	if (size != 0 && total_memory / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(total_memory);
	if (ptr != NULL)
		ft_memset(ptr, 0, (nmemb * size));
	return (ptr);
}
/*	
total_memory/size checks to see if there was truncation due 
to integer overflow
*/
