/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:49:05 by sthitiku          #+#    #+#             */
/*   Updated: 2022/08/31 06:02:48 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	max_pos(t_ps **lst, int max)
{
	t_ps	*curr;
	int		pos;

	pos = 0;
	curr = *lst;
	while (curr)
	{
		if (curr->index == max)
			break ;
		pos++;
		curr = curr->next;
	}
	return (pos);
}

int	last_index(t_ps **lst)
{
	t_ps	*curr;
	int		last;

	curr = *lst;
	while(curr->next)
	{
		curr = curr->next;
	}
	last = curr->index;
	return (last);
}

int	find_highest(t_ps **lst)
{
	t_ps	*curr;
	int		max;
	int		group;

	max = (*lst)->index;
	curr = (*lst)->next;
	while (curr)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
	}
	return (max);
}

void	ps_btoa(t_ps **b, t_ps **a, int max)
{
	int		i;

	// printf("last = %d\tmax = %d\n", last_index(a), max);
	// printf("\n\n");
	// sleep(1);
	if ((*b)->index == max)
	{
		push(b, a, 'a');
		if (!ps_check_sort(a))
		{
			if ((*a)->next->index == max - 1)
				swap(a, NULL);
			if (last_index(a) == max - 2)
				r_rotate(a, NULL);
		}
	}
	else if ((*b)->index == max - 1)
	{
		push(b, a, 'a');
		if (!ps_check_sort(a) && (*a)->next->index == (*a)->index + 1)
			swap(a, NULL);
	}
	else if ((*b)->index == max - 2)
	{
		push(b, a, 'a');
		rotate(a, NULL);
	}
	else if ((*b)->next->index == max)
	{
		swap(NULL, b);
	}
	else if (max_pos(b, max) <= ps_lst_len(b) / 2)
	{
		rotate(NULL, b);
	}
	else
	{
		r_rotate(NULL, b);
	}
}

void	ps_pushback(t_ps **b, t_ps **a)
{
	int	max;
	
	// show_list(b);
	while (!ps_check_sort(a) || ps_lst_len(b) > 0)
	{
		max = find_highest(b);
		// printf("max = %d\n",max);
		ps_btoa(b, a, max);
		// 	r_rotate(a, NULL);
		// if (!ps_check_sort(a))
		// {
		// 	printf("No sort\n");
		// 	r_rotate(a, NULL);
		// }
		// sleep(1);
		// printf("A\n");
		// show_list(a);
		// printf("========\n");
		// printf("B\n");
		// show_list(b);
	}
}