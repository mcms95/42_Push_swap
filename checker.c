# include "push_swap.h"

int is_digit(char *av)
{
	int i;
	
	i = 0;
	while (av[i] == ' ' || av[i] == '\t')
			i++;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == '\0')
		return (0);
	while (av[i] != '\0')
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *head, int number)
{
	t_stack *current;
	
	if (head == NULL)
		return (1);
	current = head;
	while (current != NULL)
	{	
		if (current->value == number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_if_stack_is_sorted(t_stack *head)
{
	t_stack *current;

	if (head == NULL || head->next == NULL)
		return 1; 
	current = head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}