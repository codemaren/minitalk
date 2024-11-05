/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:23:22 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 16:01:44 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		return (size + j);
	k = 0;
	while (src[k] != '\0' && k < (size - i - 1))
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}
/*
int main(void)
{
    char custom_dest[30] = "Fourty";
    char system_dest[30] = "Fourty";
    char src[] = "Two";
    int size = 8;

    // Call the custom strlcat function
    int custom_value = ft_strlcat(custom_dest, src, size);

    // Call the system strlcat function
    int system_value = strlcat(system_dest, src, size);

    // Print results for custom strlcat
    printf("Custom strlcat (ft_strlcat):\n");
    printf("Return value: %d\n", custom_value);
    printf("Resulting string: %s\n\n", custom_dest);

    // Print results for system strlcat
    printf("System strlcat:\n");
    printf("Return value: %d\n", system_value);
    printf("Resulting string: %s\n", system_dest);

    return (0);
}
*/
