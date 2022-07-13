/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:22:09 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/13 20:31:45 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_lstclear(t_list **lst)
{
	t_list	*head;

	while (*lst)
	{
		head = (*lst)->next;
		free(*lst);
		*lst = head;
	}
	*lst = NULL;
}

static t_ps	*ps_lstlast(t_ps *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ps_addfront(t_ps **lst, t_ps *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}	
}

void	ps_addback(t_ps **lst, t_ps *new)
{
	t_ps	*temp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ps_lstlast(*lst);
			temp->next = new;
		}
	}
}
