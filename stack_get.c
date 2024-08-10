# include "push_swap.h"

int	get_stack_len(t_stack *stack)
{
	t_stack	*current;
	int		counter;

	current = stack;
	counter = 0;
	while (current != NULL)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

t_stack	*get_stack_highest_value_node(t_stack *stack)
{
	t_stack	*highest_node;
	int		max_value;

	if (stack == NULL)
		return (NULL);
	highest_node = NULL;
	max_value = INT_MIN;
	while (stack != NULL)
	{
		if(stack->value > max_value)
		{
			max_value = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack	*get_stack_lowest_value_node(t_stack *stack)
{
	t_stack	*lowest_node;
	int		min_value;

	if (stack == NULL)
		return (0);
	lowest_node = NULL;
	min_value = INT_MAX;
	while (stack != NULL)
	{
		if(stack->value < min_value)
		{
			min_value = stack->value;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}

t_stack	*get_chepeast_node(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	while(current != NULL)
	{
		if (current->is_cheapest_move == true)
			return (current);
		current = current->next;
	}
}