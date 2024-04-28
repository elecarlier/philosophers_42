/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:56:23 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 23:06:52 by ecarlier         ###   ########.fr       */
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


void	parse_input(t_table *table, char *argv[])
{
	table->nb_philo = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]) ;
	table->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->max_meal = ft_atoi(argv[5]);
	else
		table->max_meal = -1; //use it as a flag
	//what about the forks ?
}

void	init_forks(t_table *data)
{
	int	i;

	i = 0;
	while(i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].first_fork = &data->forks[i];
		data->philos[i].second_fork = &data->forks[(i + 1) % data->nb_philo];
		i++;
	}


}

// static void	assign_forks(t_philo *philo,  *forks, int pos)
// {
// 	int	nbr_philo;

// 	nbr_philo = philo->data->nb_philo; //to make the code clean
// 	if (philo->id % 2 == 0)
// 	{
// 		philo->first_fork = &forks[pos];
// 		philo->second_fork = &forks[(pos + 1) % nbr_philo];
// 	}
// 	else
// 	{
// 		philo->second_fork = &forks[pos];
// 		philo->first_fork = &forks[(pos + 1) % nbr_philo];
// 	}
// }

static void	philo_init(t_table *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->nb_philo)
	{
		philo = data->philos + i; //parcourt l'array des philos
		philo->id = i + 1;
		philo->count_meal = 0;
		philo->is_full = 0;
		//philo->last_meal_time = 0;
		pthread_mutex_init(&data->philos[i].is_eating, NULL); //not sure about this
		//philo->is_eating
		//assign_forks(philo, data->forks, i);
		//philo->thread_id;
		philo->data = data;
	}

}

void	data_init(t_table *data)
{
	int	i;

	i = -1;
	//data->nb_philo; parse_input
	//data->t_die; parse_input
	//data->t_eat; parse_input
	//data->t_sleep; parse_input
	//data->max_meal; parse_input
	data->start = 0;
	data->end = 0;
	pthread_mutex_init(&data->m_death, NULL);
	data->flag_dead = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return ;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return ;
	// data->forks = malloc(sizeof(t_fork) * data->nb_philo);
	// if (!data->forks)
	// 	return ;
	// while (++i < data->nb_philo)
	// {
	// 	pthread_mutex_init(&data->forks[i].fork, NULL);
	// 	data->forks[i].fork_id = i;
	// }
	pthread_mutex_init(&data->write_mutex, NULL);
}


void	init(t_table *data, char *argv[])
{
	parse_input(data, argv);
	data_init(data);

	philo_init(data);
	init_forks(data);
}

