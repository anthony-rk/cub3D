/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:04:24 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/17 19:04:39 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*temp;

	if (!(temp = (void *)malloc(sizeof(t_list))))
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
