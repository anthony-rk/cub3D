/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:37:04 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/18 19:37:06 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_ptr;

	if (lst && del)
	{
		while (*lst)
		{
			lst_ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = lst_ptr;
		}
	}
}
