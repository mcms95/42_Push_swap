/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:03:51 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 16:01:51 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	bool	ac_is_2_flag;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
	{
		av = push_swap_split(av[1], ' ');
		if (!av)
			return (0);
		ac_is_2_flag = true;
	}
	initiate_stack(&a, av + 1, ac_is_2_flag);
	if (!(check_if_stack_is_sorted(a)))
	{	
		main_sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}


void	main_sort(t_stack **a, t_stack **b)
{
	int	stack_a_len;

	stack_a_len = get_stack_len(*a);
	if (stack_a_len == 2)
		sa(a);
	else if (stack_a_len == 3)
		sort_3(a);
	else
		push_swap(a, b);
	return ;
}