/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:31:52 by sthitiku          #+#    #+#             */
/*   Updated: 2022/09/10 03:09:04 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	checker(char *inst, t_ps **a, t_ps **b)
{
	if (check_inst(a, b, inst) == 0)
	{
		write(2, "KO\n", 3);
		free(inst);
		exit (INPUT_ERR);
	}
}

void	check_av(char *inst, t_ps **a, t_ps **b)
{
	if (inst == NULL)
	{
		if (ps_check_sort(a) && !*b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		exit (0);
	}
	else
	{
		if (!ft_strncmp(inst, " ", 1) || !ft_strncmp(inst, "\t", 1) || \
				!ft_strncmp(inst, "\n", 1))
		{
			if (a)
				ps_lstclear(a);
			if (b)
				ps_lstclear(b);
			write(2, "Error\n", 6);
			exit (INPUT_ERR);
		}
		checker(inst, a, b);
		free(inst);
		return ;
	}
}

int	main(int ac, char **av)
{
	char	*inst;
	t_ps	*a;
	t_ps	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac >= 2 && av[1][0])
	{
		while (i < ac)
		{
			ps_args_to_lst(av[i], &a);
			i++;
		}
		if (ps_check_dup(&a))
			ps_error(&a, 0, DUP_SORT);
		while (1)
		{
			inst = get_next_line(0);
			check_av(inst, &a, &b);
		}
	}
}
