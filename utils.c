# include "push_swap.h"

long	ft_atol(char *str)
{
	long	number;
	int		i;
	int		flag;

	i = 0;
	number = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')  
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' )
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (flag * number);
}

void	initialize_node_variables(t_stack *new_node)
{
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->is_cheapest_move = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
}

void	append_node(t_stack **head, int number)
{
	t_stack	*new_node;
	t_stack	*current;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return;
	initialize_node_variables(new_node);
	new_node->value = number;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

void	print_stack(t_stack *head)
{
	t_stack	*current;

	current = head;
	if (head == NULL)
		return;
	while (current != NULL)
	{
		ft_printf("Value is: %d\n", current->value);
		current = current->next;
	}
}
