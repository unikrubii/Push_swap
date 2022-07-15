/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <sthitiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:28:55 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/15 23:22:00 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	lst_len(t_ps **lst)
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

static int	*lst_to_arr(t_ps **lst)
{
	t_ps	*curr;
	int		*arr;
	int		i;

	curr = *lst;
	arr = malloc(sizeof(int) * lst_len(lst));
	i = 0;
	while (curr)
	{
		arr[i++] = curr->num;
		curr = curr->next;
	}
	return (arr);
}

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int *num, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (num[i] <= num[pivot] && i < last)
				i++;
			while (num[j] > num[pivot])
				j--;
			if (i < j)
				ft_swap(&num[i], &num[j]);
		}
		ft_swap(&num[pivot], &num[j]);
		quicksort(num, first, j - 1);
		quicksort(num, j + 1, last);
	}
}

int	ps_find_median(t_ps **lst)
{
	int	*arr;
	int	arr_len;
	int	i;
	int	median;

	arr = lst_to_arr(lst);
	arr_len = lst_len(lst);
	quicksort(arr, 0, arr_len - 1);
	median = arr[arr_len / 2];
	free(arr);
	return (median);
}