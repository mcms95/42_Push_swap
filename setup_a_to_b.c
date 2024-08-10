# include "push_swap.h"

void	setup_a_to_b(t_stack *a, t_stack *b)
{
	set_current_index_and_check_median(a);
	set_current_index_and_check_median(b);
	set_target_for_a(a, b);
	set_a_push_cost(a, b);
	set_a_cheapest_node(a);

}

void	set_target_for_a(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_b_node;
	int		index_of_best_match;

	while(a != NULL)
	{
		index_of_best_match = INT_MIN;
		current_b_node = b;
		while(current_b_node != NULL)
		{
			if (current_b_node->value > index_of_best_match 
				&& current_b_node->value < a->value)
			{
				index_of_best_match = current_b_node->value;
				target_node = current_b_node;
			}
			current_b_node = current_b_node->next;
		}
		if ( index_of_best_match == INT_MIN) // No lower number found
			a->target_node = get_stack_highest_value_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_a_push_cost(t_stack *a, t_stack *b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = get_stack_len(a);
	stack_b_len = get_stack_len(b);
	while (a)
	{
		a->push_cost = b->index;
		if (!(a->above_median)) // If it is under the median 
			a->push_cost = stack_a_len - a->index; // Counting the number of moves to go to the top going from the end
		if (a->target_node->above_median) // If target node is above median
			a->push_cost += a->target_node->index;
		else
			a->push_cost += stack_b_len - (a->target_node->index);
		a = a->next;
	}	
}

void	set_a_cheapest_node(t_stack *a)
{
	t_stack	*lowest_cost_to_push_node;
	int		lowest_cost_to_push;

	lowest_cost_to_push = INT_MAX;
	if (a == NULL)
		return;
	while(a)
	{
		if (a->push_cost < lowest_cost_to_push)
		{
			lowest_cost_to_push = a->push_cost;
			lowest_cost_to_push_node = a;
		}
		a = a->next;
	}
	lowest_cost_to_push_node->is_cheapest_move = true;
}