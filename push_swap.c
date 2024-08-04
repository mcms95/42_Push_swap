# include "push_swap.h"

// 1 for true, 0 for false
// exit(1) -> error, exit(0)-> success
// We can declare many times a function but only definite once -> write code in it
// Initiate pointers and struct to NULL to prevent SEG_FAULT
// TODO create function to free linked list and if needed the array

void initiate_stack(t_stack **a, char **av, bool ac_is_2_flag)
{
	printf("Entering initiate_stack\n");
	long	number;
	int		i;

	i = 0;
	while (av[i])
	{
		// Check if number is a digit
		if (!is_digit(av[i]))
		{   
			printf("Error, '%s' is not a valid number!\n", av[i]);
			free_all(a, av, ac_is_2_flag);
			return;
		}
		// Convert number to long to check range
		number = ft_atol(av[i]);
		if (number < INT_MIN || number > INT_MAX)
		{   
			printf("Error, number %ld is out of range\n", number);
			free_all(a, av, ac_is_2_flag);
			return;
		}
		// Check if number is a duplicate
		if (!check_duplicates(*a, number))
		{
			printf("Error, number %ld is a duplicate\n", number);
			free_all(a, av, ac_is_2_flag);
			return;
		}
		// Append node to tail
		append_node(a, (int)number);
		i++;
	}
	if ( ac_is_2_flag == true)
	{
		free_array(av);
	}
}

int main(int ac, char **av)
{
	// Check if numbers came in av[1] or in various arguments
	t_stack	*a;
	t_stack	*b;
	a = NULL;
	b = NULL;

	bool	ac_is_2_flag;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = push_swap_split(av[1], ' ');
		if (!av)
			return	1;
		ac_is_2_flag = true;
	}
	initiate_stack(&a, av + 1, ac_is_2_flag);
	printf("Stack created successfully!\n");
	// Check if stack is sorted
	if (check_if_stack_is_sorted(a))
	{
		ft_printf("Stack is already sorted!\n");
	}
	// Stack a
	ft_printf("\nOriginal stack a ..\n");
	print_stack(a);

	// Stack b
	ft_printf("Original stack b ..\n");
	print_stack(b);

	// TODO PUSH
	ft_printf("\nPushing first value of a to b:..\n");
		// Stack a
	ft_printf("After push stack a ..\n");
	print_stack(a);

	// Stack b
	ft_printf("After push stack b ..\n");
	print_stack(b);


	printf("\nFreeing stack...\n");
	free_stack(&a);
	return (0);
}