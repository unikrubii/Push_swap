/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:57:55 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/02 19:06:45 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_split(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

int	split_len(char **num)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (num[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	lst_init(t_ps **a, char *num, char **split)
{
	t_ps	*lst;
	t_ps	*tmp;
	int		i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-')
			ps_error(a, 0, CONV_ERR);
		i++;
	}
	lst = malloc(sizeof(t_ps));
	if (!lst)
		ps_error(a, 0, MALLOC_ERR);
	if (*num == '-' && !ft_isdigit(*(num + 1)))
		ps_error(a, 0, CONV_ERR);
	lst->num = ps_atoi(num, a, split);
	lst->index = -1;
	lst->next = NULL;
	ps_addback(a, lst);
}

void	ps_args_to_lst(char *str, t_ps **a)
{
	char	**num;
	int		len;
	int		i;

	num = ft_split(str, ' ');
	len = split_len(num);
	i = 0;
	while (i < len)
	{
		lst_init(a, num[i], num);
		i++;
	}
	free_split(num);
}

void	show_list(t_ps **lst)
{
	t_ps	*curr;

	curr = *lst;
	while (curr)
	{
		printf("%d\t%d\n", curr->num, curr->index);
		curr = curr->next;
	}
}

int	check_num(t_ps **lst, int median)
{
	t_ps	*curr;
	
	curr = *lst;
	while (curr)
	{
		if (curr->num < median)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void push_3(t_ps **lst)
{
	int	max;
	
	max = find_highest(lst);
	if ((*lst)->index == max)
	{
		rotate(lst, NULL);
		if (!ps_check_sort(lst))
			swap(lst, NULL);
	}
	else if ((*lst)->index == max - 1)
	{
		if ((*lst)->next->index == max - 2)
			swap(lst, NULL);
		else
			r_rotate(lst, NULL);
	}
	else
	{
		rotate(lst, NULL);
		swap(lst, NULL);
		r_rotate(lst, NULL);
	}
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

void push_5(t_ps **from, t_ps **to, int len)
{
	if (ps_check_sort(from) && ps_lst_len(to) == 0)
		return ;
	if (!ps_check_sort(from) && ps_lst_len(to) == 0 && \
			(*from)->next->next->index == 3 && \
			(*from)->next->next->next->index == 4 && \
			(*from)->next->next->next->next->index == 5)
	{
		swap(from, NULL);
		return ;
	}
	if (ps_lst_len(from) == 3 && !ps_check_sort(from))
	{
		push_3(from);
		if ((*to)->index != 2)
			swap(NULL, from);
		push(to, from, 'a');
		push(to, from, 'a');
		return ;
	}
	if ((*from)->index <= 2)
	{
		if (ps_check_sort(from))
			push(to, from, 'a');
		else
			push(from, to, 'b');
	}
	else
	{
		if (lowest_index(from) <= len / 2)
			rotate(from, NULL);
		else
			r_rotate(from, NULL);
	}
	if (!ps_check_sort(from))
		len = ps_lst_len(from);
	push_5(from, to, len);
}

void push_intv(t_ps **from, t_ps **to, int counter, int intv)
{
	static int	i = 0;

	if (ps_lst_len(from) < 3)
		return ;
	if ((*from)->index <= counter && (*from)->index < find_highest(from) - 1)
	{
		push(from, to, 'b');
		i++;
	}
	else
	{
		rotate(from, NULL);
	}
	if (i == intv)
	{
		i = 0;
		counter += intv;
	}
	push_intv(from, to, counter, intv);
}

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*b;
	int		i;
	int		intv;

	i = 1;
	a = NULL;
	b = NULL;
	intv = 0;
	if (ac >= 2 && av[1][0])
	{
		while (i < ac)
		{
			ps_args_to_lst(av[i], &a);
			i++;
		}
		if (ps_check_sort(&a) == 1)
			ps_error(&a, 1, 0);
		// if (ps_check_dup(&a))
		// 	ps_error(&a, 0, DUP_SORT);
		ps_find_median(&a);
		ps_put_index(&a);

		// show_list(&a);
		// r_rotate(&a, NULL);
		// show_list(&a);
		
		if (ps_lst_len(&a) > 5)
		{
			if (ps_lst_len(&a) >= 500)
				intv = ps_lst_len(&a) / 11;
			else
				intv = ps_lst_len(&a) / 4;
			push_intv(&a, &b, intv, intv);
			if (!ps_check_sort(&a))
				swap(&a, NULL);
			ps_pushback(&b, &a);
		}
		else if (ps_lst_len(&a) == 3)
			push_3(&a);
		else
			push_5(&a, &b, ps_lst_len(&a));
		
		// printf("A\n");
		// show_list(&a);
		// printf("========\n");
		// printf("B\n");
		// show_list(&b);
		ps_lstclear(&a);
	}
}
