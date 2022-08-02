/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubii <rubii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:57:55 by sthitiku          #+#    #+#             */
/*   Updated: 2022/08/03 01:26:11 by rubii            ###   ########.fr       */
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
	int		i;

	printf("check in lst_init %s\n", num);
	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-')
		{
			write(1, "Error\n", 6);
			exit(CONV_ERR);
		}
		i++;
	}
	lst = malloc(sizeof(t_ps));
	if (!lst)
	{
		ps_lstclear(&lst);
		exit(MALLOC_ERR);
	}
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
		if (ps_check_dup(&a) == 1)
		{
			ps_lstclear(&a);
		}
		else
		{
			write(1, "push_swap\n", 10);
			show_list(&a);
			printf("--\n");
			printf("%d\n", ps_find_median(&a));
			printf("--\n");
			ps_lstclear(&a);
		}
	}
	else
		write(1, "Error\n", 6);
}

// What to do
// 1. check for non number in args --> done
// 2. check for number beyond int boundary --> done
