/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:06:07 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 02:21:08 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac >= 2 && av[1][0])
	{
		while (i < ac)
		{
			ps_args_to_lst(av[i], &a);
			i++;
		}
		if (ps_check_sort(&a) == 1)
			ps_error(&a, 1, 0);
		ps_find_median(&a);
		ps_put_index(&a);
		push_swap(&a, &b);
		ps_lstclear(&a);
	}
}
