/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:35:38 by ecarlier          #+#    #+#             */
/*   Updated: 2024/03/05 17:53:51 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	[number_of_times_each_philosopher_must_eat]

	./philo 5 800 200 200 5
*/

typedef struct s_table t_table;
typedef struct s_philo t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int	fork_id;
}	t_fork;

typedef struct s_philo
{
	int	id;
	int	count_meal; //how many the philo has eaten
	int	is_full;
	long last_meal_time; //time passed from last meal
	t_fork *left_fork;
	t_fork *right_fork;
	pthread_t thread_id; //philo == thread
	t_table	*table;
}			t_philo;

typedef struct s_table
{
	int	nb_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_meal; //limit of meals
	int	start; //time when we start
	int end; //when a philo dies || all philo full
	t_fork *forks; //array with forks
	t_philo *philos; //array with philos
}		t_table;


int	ft_atoi(const char *str);
void	parse_input(t_table *table, char *argv[]);

int	check_input(char **argv);

#endif
