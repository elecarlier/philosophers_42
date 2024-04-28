/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:37:14 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 22:53:47 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*code que chaque thread de philos vont effectuer */
void	*routine(void *phil)
{
	t_philo	*philo;

	philo = phil;
	while(!is_dead(philo))
	{
		pthread_mutex_lock(&philo->is_eating);
		if (philo->is_full)
		{
			pthread_mutex_unlock(&philo->is_eating); //goes out of the while loop
			break;
		}
		pthread_mutex_unlock(&philo->is_eating);
		if (philo->data->nb_philo != 1)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
		//else
		//	one philo routine
	}
	return ((void *)0);

}

void	begin_dinner(t_table *data)
{
	int	i;

	pthread_t	t_monitor;
	i = -1;
	data->start = get_msec();
	// if (data->nb_philo == 1)
	// 	one_philo(data);
	// if (data->max_meal == 0 || data->nb_philo == 0)
	// {
	// 	printf("end simulation..\n");
	// 	//return ; //not sure this should be here
	// }
	// else
	// {
	while (++i < data->nb_philo)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, &routine, &data->philos[i]))
			printf(THREAD_CREATION_FAIL);
			//should print error msg if fail?
	}
	if (pthread_create(&t_monitor, NULL, &monitor_routine, data))
		printf(THREAD_CREATION_FAIL);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->philos[i].thread_id, NULL))
			printf(THREAD_JOIN_FAIL);
	}
	if (pthread_join(t_monitor, NULL))
		printf(THREAD_JOIN_FAIL);
}

/*
Return 1 if the flag that indicates that a philo is dead is one, returns 0 otherwise*/
int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_death);
	if (philo->data->flag_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->m_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_death);
	return (0);
}
