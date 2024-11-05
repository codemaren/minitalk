/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:37:02 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 23:05:18 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (char unsigned *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*
int main()
{
    // Test 1: Empty source string
    char src1[] = "";
    char dest1[20];
    ft_memcpy(dest1, src1, 0);
    printf("Test 1: Empty source string\n");
    printf("dest1: \"%s\"\n\n", dest1);

    // Test 2: Empty destination string
    char src2[] = "Hello, world!";
    char dest2[20] = "";
    ft_memcpy(dest2, src2, strlen(src2) + 1);
    printf("Test 2: Empty destination string\n");
    printf("dest2: \"%s\"\n\n", dest2);

    // Test 3: Overlapping memory regions
    char data[] = "Hello, world!";
    char dest3[20];
    ft_memcpy(dest3 + 5, data, 7);
    printf("Test 3: Overlapping memory regions\n");
    printf("dest3: \"%s\"\n\n", dest3);

    // Test 4: Copying from a larger source
    char src4[] = "This is a longer string than the destination";
    char dest4[20];
    ft_memcpy(dest4, src4, 20);
    printf("Test 4: Copying from a larger source\n");
    printf("dest4: \"%s\"\n\n", dest4);

    // Test 5: Copying to a smaller destination
    char src5[] = "Short";
    char dest5[4];
    ft_memcpy(dest5, src5, strlen(src5) + 1);
    printf("Test 5: Copying to a smaller destination\n");
    printf("dest5: \"%s\"\n\n", dest5);

    // Test 6: Copying null-terminated strings
    char src6[] = "Hello, world!";
    char dest6[20];
    ft_memcpy(dest6, src6, strlen(src6) + 1);
    printf("Test 6: Copying null-terminated strings\n");
    printf("dest6: \"%s\"\n\n", dest6);

    // Now let's compare with system's memcpy
    char dest_sys[20];

    // Using system's memcpy
    memcpy(dest_sys, src1, 0);
    printf("System memcpy (empty source): \"%s\"\n", dest_sys);

    memcpy(dest_sys, src2, strlen(src2) + 1);
    printf("System memcpy (empty destination): \"%s\"\n", dest_sys);

    memcpy(dest_sys + 5, data, 7);
    printf("System memcpy (overlapping regions): \"%s\"\n", dest_sys);

    memcpy(dest_sys, src4, 20);
    printf("System memcpy (larger source): \"%s\"\n", dest_sys);

    memcpy(dest_sys, src5, strlen(src5) + 1);
    printf("System memcpy (smaller destination): \"%s\"\n", dest_sys);

    memcpy(dest_sys, src6, strlen(src6) + 1);
    printf("System memcpy (null-terminated strings): \"%s\"\n", dest_sys);

    return 0;
}
*/
