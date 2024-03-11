/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:56:23 by ecarlier          #+#    #+#             */
/*   Updated: 2024/03/06 14:46:40 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
False = 0
True = 1
*/

/*

Pour chaque philo, sa fourchette droite vaut son id - 1
(philo_pod + 1) % nbr_philo

on change si odd/even

*/

static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	nbr_philo;

	nbr_philo = philo->table->nb_philo; //to make the code clean
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % nbr_philo];
	}
	else
	{
		philo->second_fork = &forks[pos];
		philo->first_fork = &forks[(pos + 1) % nbr_philo];
	}


}

static void	philo_init(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nb_philo)
	{
		philo = table->philos + i; //parcourt l'array des philos
		philo->id = i + 1;
		philo->count_meal = 0;
		philo->is_full = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}

}

void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end = 0;
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philos)
		return (NULL);
	table->forks = malloc(sizeof(t_fork) * table->nb_philo);
	if (!table->forks)
		return (NULL);
	while (++i < table->nb_philo)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		table->forks[i].fork_id = i;
	}
}
/*
void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		error_exit("Error with the malloc");
	return (ret);
}
*/
