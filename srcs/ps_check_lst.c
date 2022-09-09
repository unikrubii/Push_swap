/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:57:53 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:51:04 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ps_check_sort(t_ps **lst)
{
	t_ps	*curr;
	int		min;

	min = (*lst)->num;
	curr = (*lst)->next;
	while (curr)
	{
		if (curr->num <= min)
			return (0);
		min = curr->num;
		curr = curr->next;
	}
	return (1);
}

int	ps_lst_len(t_ps **lst)
{
	t_ps	*curr;
	int		len;

	len = 0;
	curr = *lst;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

int	ps_check_dup(t_ps **lst)
{
	t_ps	*curr;
	t_ps	*next;
	int		len;

	len = ps_lst_len(lst);
	curr = *lst;
	while (len > 0)
	{
		next = curr->next;
		while (curr && next)
		{
			if (curr->num == next->num)
				return (1);
			next = next->next;
		}
		curr = curr->next;
		len--;
	}
	return (0);
}

int	lowest_index(t_ps **lst)
{
	t_ps	*curr;
	int		lowest;
	int		i;

	curr = (*lst)->next;
	lowest = (*lst)->index;
	i = 1;
	while (curr)
	{
		if (curr->index < lowest)
			lowest = curr->index;
		i++;
		curr = curr->next;
	}
	return (i);
}

void	ps_put_index(t_ps **lst)
{
	int		*arr;
	int		arr_len;
	int		i;
	t_ps	*curr;

	curr = *lst;
	arr = lst_to_arr(lst);
	arr_len = ps_lst_len(lst);
	quicksort(arr, 0, arr_len - 1);
	while (curr)
	{
		i = 0;
		while (i < arr_len)
		{
			if (curr->num == arr[i])
			{
				curr->index = i + 1;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
	free(arr);
}
