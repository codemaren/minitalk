/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:06:51 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/14 23:16:35 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	format_specifier(const char **s, va_list args, int *count)
{
	if ((*(*s + 1)) == 'c')
		ft_print_char(s, va_arg(args, int), count);
	else if ((*(*s + 1)) == 's')
		ft_print_str(s, va_arg(args, char *), count);
	else if ((*(*s + 1)) == 'd' || ((*(*s + 1))) == 'i')
		ft_print_digit(s, va_arg(args, int), count);
	else if ((*(*s + 1)) == 'u')
		ft_print_udigit(s, va_arg(args, unsigned int), count);
	else if (*(*s + 1) == 'x')
		ft_print_hexa(s, va_arg(args, unsigned int), count);
	else if (*(*s + 1) == 'X')
		ft_print_hexa_cap(s, va_arg(args, unsigned int), count);
	else if ((*(*s + 1)) == 'p')
		ft_print_ptr(s, va_arg(args, void *), count);
	else if ((*(*s + 1)) == '%')
		ft_print_char(s, '%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{	
		if (*s == '%')
			format_specifier(&s, args, &count);
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
			s++;
		}
	}
	va_end(args);
	return (count);
}
