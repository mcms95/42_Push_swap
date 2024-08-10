# include "push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = get_stack_highest_value_node(*a);
	if (highest_node == (*a))
		ra(a);
	if (highest_node == (*a)->next)
		rra(a);
	if (!check_if_stack_is_sorted(*a))
		sa(a);
}
