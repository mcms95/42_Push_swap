# include "push_swap.h"

void	sort_3(t_stack **a)
{
	// Cases 1 3 2
    // 3 2 1
    // 2 1 3

    t_stack	*highest_node;

	highest_node = get_stack_highest_value_node(*a);
	if (highest_node == (*a)) // If first node is the highest move to the end
		ra(a);
	if (highest_node == (*a)->next) // If second number is highest move to the end
		ra(&(*a)->next);
	if (!check_if_stack_is_sorted(*a)) // Check if it is sorted, if it is sawp first two numbers
		sa(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	sort_3(a);
	pa(b, a);
	pa(b, a);
}