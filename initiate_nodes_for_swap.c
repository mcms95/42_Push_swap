# include "push_swap.h"

void	initiate_nodes(t_stack *a, t_stack *b)
{
	set_current_index_and_check_median(a);
	set_current_index_and_check_median(b);
	set_target_node(a, b);
	set_push_cost(a, b);
	set_cheapest_node(b);

}

void	set_current_index_and_check_median(t_stack *stack)
{
	int		stack_median_line;
	int		index;

	if (NULL == stack)
		return ;
	index = 1;
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

// The target node is the closest highest node in stack a
void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_a_node;
	int		index_of_best_match;

	while(b != NULL)
	{
		index_of_best_match = INT_MAX;
		current_a_node = a;
		while(current_a_node != NULL)
		{
			if (current_a_node->value < index_of_best_match 
				&& current_a_node->value > b->value)
			{
				target_node->value = current_a_node->next;
				target_node = current_a_node;
			}
			current_a_node = current_a_node->next;
		}
		if ( index_of_best_match == INT_MAX) // No bigger number found
			b->target_node = get_stack_lowest_value_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_push_cost(t_stack *a, t_stack *b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = get_stack_len(a);
	stack_b_len = get_stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!b->above_median) // If it is under the median 
			b->push_cost = stack_b_len - b->index; // Counting the number of moves to go to the top going from the end
		if (b->target_node->above_median) // If target node is above median
			b->push_cost += b->target_node->index;
		else
			b->push_cost += stack_a_len - (b->target_node->index);
		b = b->next;
	}	
}

void	set_cheapest_node(t_stack *b)
{
	t_stack	*lowest_cost_to_push_node;
	int		lowest_cost_to_push;

	lowest_cost_to_push = INT_MAX;
	if (NULL == b)
		return;
	while(b)
	{
		if (b->push_cost < lowest_cost_to_push)
		{
			lowest_cost_to_push = b->push_cost;
			lowest_cost_to_push_node = b;
		}
		b = b->next;
	}
	lowest_cost_to_push_node->is_cheapest_move = true;
}