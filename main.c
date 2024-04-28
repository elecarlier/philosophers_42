/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:10:54 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 19:02:12 by ecarlier         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_table	*table;

	table = NULL; //necessary ?
	if (argc < 5 || argc > 6)
	{
		print_error(0);
		return (1);
	}
	if (check_input(argv))
		return (1);
	table = (t_table *)malloc(sizeof(t_table));
	init(table, argv);
	//parse_input(&table, argv);
	printf("### START DINNER ###\n");
	begin_dinner(table);
	return (0);
}
