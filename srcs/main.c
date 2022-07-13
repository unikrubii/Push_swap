/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:06:07 by sthitiku          #+#    #+#             */
/*   Updated: 2022/07/10 21:20:29 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	push(t_ps **from, t_ps **to)
{
	t_ps	*to_push;
	t_ps	*head;
	
	to_push = *from;
	head = (*from)->next;
	*from = head;
	head = *to;
	to_push->next = head;
	*to = to_push;
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int		i;

	a = malloc(sizeof(t_ps));
	a->num = 0;
	a->next = NULL;
	tmp = a;
	i = 1;
	while(i <= 5)
	{
		tmp->next = malloc(sizeof(t_ps));
		tmp->next->num = i;
		tmp = tmp->next;
		i++;
	}
	// r_rotate(&a, NULL);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	printf("------\n");
	tmp = b;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	while(a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
