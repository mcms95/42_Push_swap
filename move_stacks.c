/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:03:54 by nucardos          #+#    #+#             */
/*   Updated: 2024/08/10 14:14:58 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_stacks(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both_stacks(a, b, cheapest_node);
	finish_a_rotation(a, cheapest_node);
	finish_b_rotation(b, cheapest_node->target_node);
	pb(b, a);
}

void	finish_a_rotation(t_stack **a, t_stack *cheapest_node)
{
	while (*a != cheapest_node)
	{
		if (cheapest_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both_stacks(b, a, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both_stacks(b, a, cheapest_node);
	finish_a_rotation(a, cheapest_node->target_node);
	finish_b_rotation(b, cheapest_node);
	pa(a, b);
}

void	finish_b_rotation(t_stack **b, t_stack *target_node)
{
	while (*b != target_node)
	{
		if (target_node->above_median)
			rb(b);
		else
			rrb(b);
	}
}
