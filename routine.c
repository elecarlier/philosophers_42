/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:39:37 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 23:15:39 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
locks the mutex is eating
increment count of meal
NEED TO UPDATE TIME DO DIE
*/
void	eating(t_philo *philo)
{
	t_table	*data;

	data = philo->data;
	take_forks(philo);
	pthread_mutex_lock(&philo->is_eating);
	print_msg(philo, IS_EATING);
	philo->count_meal += 1;
	precise_usleep(data->t_eat * 100);
	if (philo->count_meal == data->max_meal)
		philo->is_full = 1;
	drop_forks(philo);
	pthread_mutex_unlock(&philo->is_eating);
}
/*
Puts the philosopher asleep for data->time_to_sleep milliseconds
*/
void	sleeping(t_philo *philo)
{
	//PRINT LOG IS SLEEPING
	print_msg(philo, IS_SLEEPING);
	precise_usleep(philo->data->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	(void)philo;
	print_msg(philo, IS_THINKING);
}

void	drop_forks(t_philo	*philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
/*
different cases if odd or even number of philos
*/
void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->first_fork);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->second_fork);
		print_msg(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->second_fork);
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->first_fork);
		print_msg(philo, "has taken a fork");
	}
}
