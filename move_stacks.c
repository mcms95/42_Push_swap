# include "push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_stacks(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both_stacks(a, b, cheapest_node);
	finish_a_rotation(a, cheapest_node);
	finish_b_rotation(b, cheapest_node->target_node);

}

void	finish_a_rotation(t_stack **a, t_stack *cheapest_node)
{
	while(*a != cheapest_node)
	{
		if (cheapest_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void move_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *cheapest_node = get_cheapest_node(*b);
    
    ft_printf("Moving node %d from B to A\n", cheapest_node->value);
    ft_printf("Target node in A: %d\n", cheapest_node->target_node->value);

    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
    {
        ft_printf("Both nodes above median, rotating both\n");
        rotate_both_stacks(b, a, cheapest_node);
    }
    else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
    {
        ft_printf("Both nodes below median, reverse rotating both\n");
        reverse_rotate_both_stacks(b, a, cheapest_node);
    }
    
    ft_printf("Finishing A rotation\n");
    finish_a_rotation(a, cheapest_node->target_node);
    
    ft_printf("Finishing B rotation\n");
    finish_b_rotation(b, cheapest_node);
    
    ft_printf("Pushing from B to A\n");
    pa(a, b);
}

void	finish_b_rotation(t_stack **b, t_stack *target_node)
{
	while(*b != target_node)
	{
		if (target_node->above_median)
			rb(b);
		else
			rrb(b);
	}
}