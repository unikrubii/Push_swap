/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:22:09 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 04:11:03 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ps_lstclear(t_ps **lst)
{
	t_ps	*head;

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

void	lst_init(t_ps **a, char *num, char **split)
{
	t_ps	*lst;
	int		i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-')
		{
			free_split(split);
			ps_error(a, 0, CONV_ERR);
		}
		i++;
	}
	if (*num == '-' && !ft_isdigit(*(num + 1)))
	{
		free_split(split);
		ps_error(a, 0, CONV_ERR);
	}
	lst = malloc(sizeof(t_ps));
	if (!lst)
		ps_error(a, 0, MALLOC_ERR);
	lst->num = ps_atoi(num, a, split, lst);
	lst->index = -1;
	lst->next = NULL;
	ps_addback(a, lst);
}
