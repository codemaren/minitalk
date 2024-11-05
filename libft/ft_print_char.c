/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:50:01 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/15 19:53:04 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_print_char(const char **s, char c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
	*s += 2;
}
