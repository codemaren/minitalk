/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:35:52 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 21:36:38 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main() {
    // Test case 1: Fill int buffer using ft_memset and memset
    int int_buffer1[10];
    int int_buffer2[10];

    ft_memset(int_buffer1, 42, sizeof(int_buffer1));
    memset(int_buffer2, 42, sizeof(int_buffer2));

    printf("Using ft_memset with integer value 42:\n");
    for (size_t i = 0; i < sizeof(int_buffer1)/sizeof(int_buffer1[0]); i++) {
        printf("%c ", int_buffer1[i]);
    }
    printf("\n");

    printf("Using memset with integer value 42:\n");
    for (size_t i = 0; i < sizeof(int_buffer2)/sizeof(int_buffer2[0]); i++) {
        printf("%c ", int_buffer2[i]);
    }
    printf("\n\n");

    // Test case 2: Fill char buffer using ft_memset and memset
    char char_buffer1[10];
    char char_buffer2[10];

    ft_memset(char_buffer1, 'A', sizeof(char_buffer1));
    memset(char_buffer2, 'A', sizeof(char_buffer2));

    printf("Using ft_memset with 'A':\n");
    for (size_t i = 0; i < sizeof(char_buffer1)/sizeof(char_buffer1[0]); i++) {
        printf("%c ", char_buffer1[i]);
    }
    printf("\n");

    printf("Using memset with 'A':\n");
    for (size_t i = 0; i < sizeof(char_buffer2)/sizeof(char_buffer2[0]); i++) {
        printf("%c ", char_buffer2[i]);
    }
    printf("\n");

    return 0;
}
*/
