/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:39:19 by ecarlier          #+#    #+#             */
/*   Updated: 2024/03/05 18:00:36 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*

for the usleep function we need micro
 1e3 = 1_000
 1e6 = 1_000_000
 */
void	parse_input(t_table *table, char *argv[])
{
	table->nb_philo = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]) * 1e3;
	table->t_eat = ft_atoi(argv[3]) * 1e3;
	table->t_sleep = ft_atoi(argv[4]) * 1e3;
	if (argv[5])
		table->max_meal = ft_atoi(argv[5]);
	else
		table->max_meal = -1; //use it as a flag
}
