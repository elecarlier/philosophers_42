/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:37:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/03/06 16:35:06 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*dinner_simulation(void *data)
{

}

void	begin_dinner(t_table *table)
{
	int i;

	i = -1;
	if (table->max_meal == 0 || table->nb_philo == 1 || table->nb_philo == 0 )
	{
		printf("end simulation..\n");
		return;
	}
	else
	{
		while (++i < table->nb_philo)
		{
			pthread_create(&table->philos[i].thread_id, NULL, dinner_simulation, &table->philos[i]);
		}
	}

}
