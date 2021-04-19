/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:47:05 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/18 20:47:07 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_ptr;

	if (lst && f)
	{
		while (lst)
		{
			lst_ptr = lst->next;
			f(lst->content);
			lst = lst_ptr;
		}
	}
}
