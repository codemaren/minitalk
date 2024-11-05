/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:00:31 by kilangov          #+#    #+#             */
/*   Updated: 2024/05/22 20:22:43 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int main(void) 
{
    char buffer[10] = "123456789";
    int buffer2 = 123456789;

    printf("Before ft_bzero: %s\n", buffer);
    ft_bzero(buffer, 10);
    printf("After ft_bzero: %s\n", buffer);  // Should print an empty string
    
    printf("Before ft_bzero: %d\n", buffer2);
    ft_bzero(&buffer2, 4);
    printf("After ft_bzero: %d\n", buffer2);  // Should print an empty string
    
 // Using bzero from <strings.h>
    char buffer3[10] = "123456789";
    int buffer4 = 123456789;

    printf("Before bzero (buffer3): %s\n", buffer3);
    bzero(buffer3, sizeof(buffer3));
    printf("After bzero (buffer3): %s\n", buffer3);  

    printf("Before bzero (buffer4): %d\n", buffer4);
    bzero(&buffer4, sizeof(buffer4)); 
    printf("After bzero (buffer4): %d\n", buffer4);

    return (0);
}
*/
/*When int is cast into char, it is to allow bit wise manipulation only. 
The data type of the variable held at the memory address does not change. 
int is 4bytes. casting it to char, allows us to ZERO each byte. But the Pointer 
pointing to int buffer2, which is the memory address, does not change to char. 
it remains as int.*/
