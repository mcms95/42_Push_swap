# include "push_swap.h"

void	initiate_stack(t_stack **a, char **av, bool ac_is_2_flag)
{
	long	number;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!is_digit(av[i]))
			free_all(a, av, ac_is_2_flag);
		number = ft_atol(av[i]);
		if (number < INT_MIN || number > INT_MAX)
			free_all(a, av, ac_is_2_flag);
		if (!check_duplicates(*a, number))
			free_all(a, av, ac_is_2_flag);
		append_node(a, (int)number);
		i++;
	}
	if ( ac_is_2_flag == true)
	{
		free_array(av);
	}
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