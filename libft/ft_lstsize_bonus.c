/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilangov <kilangov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:50:35 by kilangov          #+#    #+#             */
/*   Updated: 2024/06/08 16:12:34 by kilangov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
/* Alternative
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;
	
	if (lst == NULL)
		return(0);
	i = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
*/
