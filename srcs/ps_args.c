/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:57:55 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/13 20:32:25 by sthitiku         ###   ########.fr       */
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

int		split_len(char **num)
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

void	lst_init(t_ps **a, char *num)
{
	t_ps	*lst;
	t_ps	*tmp;

	lst = malloc(sizeof(t_ps));
	lst->num = ft_atoi(num);
	lst->next = NULL;
	ps_addback(a, lst);
}

void	ps_args_to_lst(char *str, t_ps **a)
{
	// t_ps	*tmp;
	char	**num;
	int		len;
	int		i;

	// printf("%p\n", (*a)->next);
	num = ft_split(str, ' ');
	len = split_len(num);
	i = 0;
	while (i < len)
	{
		lst_init(a, num[i]);
		i++;
	}
	free_split(num);
}

void	show_list(t_ps **a)
{
	t_ps	*curr;

	curr = *a;
	while (curr)
	{
		printf("%d\n", curr->num);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		while (i < ac)
		{
			ps_args_to_lst(av[i], &a);
			i++;
		}
		show_list(&a);
		ps_lstclear(&a);
	}
	else
	{
		write(1, "exit\n", 5);
	}
}
