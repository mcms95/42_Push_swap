# include "push_swap.h"

// 1 for true, 0 for false
// exit(1) -> error, exit(0)-> success
// We can declare many times a function but only definite once -> write code in it
// Initiate pointers and struct to NULL to prevent SEG_FAULT

int main(int ac, char **av)
{
	// Check if numbers came in av[1] or in various arguments
	//t_stack	*a;
	//t_stack	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = push_swap_split(av[1], ' ');
		printf("%s\n", av[1]);
	}
	free_array(av);
	return (0);
}