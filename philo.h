/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:35:38 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 23:12:31 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>


# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

# include "messages.h"

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

// typedef struct s_fork
// {
// 	pthread_mutex_t	fork;
// 	int				fork_id;
// }	t_fork;


/*
	id;					identifier for the philosopher
	count_meal;			number of meals the philosopher has eaten.
	is_full;			flag if the philo is full
	last_meal_time;		time passed since philo's last meal.
	is_eating;			mutex to avoid data racing when the philo is eating
	first_fork;			pointer to the philosopher's first fork to take.
	second_fork;		pointer to the philosopher's secon fork.
	thread_id;
	data;				pointer to the table data
*/
typedef struct s_philo
{
	int				id;
	int				count_meal;
	int				is_full;
	//long			last_meal_time;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_t		thread_id;
	t_table			*data;
}			t_philo;


/*
	nb_philo;	number of philos at the table
	t_die;		time after which a philosopher will die if they haven't eaten.
	t_eat;		time it takes for a philosopher to eat a meal
	t_sleep;	Time it takes for a philosopher to sleep.
	max_meal;	limit of meals
	start;		time when we start
	end;		when a philo dies || all philo full
	m_death;
	flag_dead;	flag updated when a philo dies
	//forks;		array with forks
	philos;		array with philos
	write_mutex; Mutex for managing data races when writing to stdout
*/
typedef struct s_table
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_meal;
	long				start;
	int				end;
	pthread_mutex_t	m_death;
	int				flag_dead;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	write_mutex;
}		t_table;

/*main*/
int	main(int argc, char *argv[]);

/*init.c*/
void	init(t_table *table, char *argv[]);
void	parse_input(t_table *table, char *argv[]);
void	data_init(t_table *table);
void	init_forks(t_table *data);

/*input*/
void	print_error(int nb);
int	is_all_digit(char *str);
int	check_input(char **argv);

/*dinner.c*/
void	*routine(void *phil);
void	begin_dinner(t_table *data);
int	is_dead(t_philo *philo);

/*utils.c*/
int		ft_atoi(const char *str);
int		precise_usleep(long usec);
long	get_msec(void);
void	print_msg(t_philo *philo, char *msg);

/*routine*/
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	drop_forks(t_philo	*philo);
void	take_forks(t_philo *philo);

/*one philo*/
int	one_philo(t_table *data);

/*monitor*/
void	*monitor_routine(void *data_ptr);


#endif
