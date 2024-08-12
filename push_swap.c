/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:03:57 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/11 11:36:20 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*lowest_node;
	int		stack_a_len;

	stack_a_len = get_stack_len(*a);
	if (stack_a_len-- > 3 && !check_if_stack_is_sorted(*a))
		pb(b, a);
	if (stack_a_len-- > 3 && !check_if_stack_is_sorted(*a))
		pb(b, a);
	while (stack_a_len-- > 3 && !check_if_stack_is_sorted(*a))
	{
		setup_a_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		setup_b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	set_current_index_and_check_median(*a);
	lowest_node = get_stack_lowest_value_node(*a);
	put_lowest_node_on_top(a, lowest_node);
}

void	set_current_index_and_check_median(t_stack *stack)
{
	int		stack_median_line;
	int		index;

	if (stack == NULL)
		return ;
	index = 0;
	stack_median_line = get_stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = index;
		if (index > stack_median_line)
			stack->above_median = false;
		else if (index <= stack_median_line)
			stack->above_median = true;
		stack = stack->next;
		index++;
	}
}

void	put_lowest_node_on_top(t_stack **a, t_stack *lowest_node)
{
	while (*a != lowest_node)
	{
		if (lowest_node->above_median)
			ra(a);
		else
			rra(a);
	}
}
