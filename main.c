/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:10:54 by ecarlier          #+#    #+#             */
/*   Updated: 2024/03/05 17:55:19 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	[number_of_times_each_philosopher_must_eat]
	./philo 5 800 200 200 [7]

*/
void	print_error(int nb);

static	int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1); //return 1 if not digit
		i++;
	}
	return (0);

}

/*
	//Only numbers
	//no more than 200 philo
	// all be bigger than 0 except the numbers of meals
*/
int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_all_digit(argv[i]))
		{
			print_error(1);
			return (1);
		}
		if (ft_atoi(argv[1]) > 200)
		{
			print_error(2);
			return (1);
		}
		if (i < 6)
		{
			if (argv[i] <= 0)
			{
				print_error(3);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table table;
	if (argc < 5 || argc > 6)
	{
		print_error(0);
		return (1);
	}
	if (check_input(argv))
		return (1);

	parse_input(&table, argv);

	printf("All good \n");
	return (0);
}

void	print_error(int nb)
{
	printf("Incorect input \n");
	if (nb == 0)
		printf("Wrong number of arguments\n");
	if (nb == 1)
		printf("Input must be a digit \n");
	if (nb == 2)
		printf("No more than 200 philos\n");
	if (nb == 3)
		printf("Arg should be more than 0\n");

}

