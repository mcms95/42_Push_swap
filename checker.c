# include "push_swap.h"

// Check if is digit -> used check_if_arguments_are_numbers
int is_digit(char *av)
{
	int i;
	
	i = 0;

	while(av[i] == ' ' || av[i] == '\t')
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

// Check if array is all numbers
void	check_if_arguments_are_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_digit(av[i]))
		{
			printf("Error, not all numbers are digits\n");
			exit(0);
		}
		i++;
	}
	printf("All arguments are numbers!\n");
}
