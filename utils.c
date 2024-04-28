/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:40:51 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 23:09:02 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*mine*/
int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}


// int	ft_atoi(const char *s)
// {
// 	int					i;
// 	unsigned long long	v;

// 	i = 0;
// 	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
// 		i++;
// 	if (!s[i] || s[i] == '-' || ((s[i] == '+')
// 			&& !(s[i + 1] >= '0' && s[i + 1] <= '9')))
// 		return (-1);
// 	if (s[i] == '+')
// 		i++;
// 	v = 0;
// 	while (s[i])
// 	{
// 		if (!(s[i] >= '0' && s[i] <= '9'))
// 			return (-1);
// 		else
// 			v = v * 10 + (s[i] - '0');
// 		i++;
// 	}
// 	// if (v > INT_MAX)
// 	// 	return (-1);
// 	return ((int)v);
// }

/*
usec : nombre en microsecondes (usec)
*/
/*
 * Function to precisely wait for a specified number of microseconds.
 * @param usec: Number of microseconds to wait.
 * @return: Returns 0 on successful completion, -1 on error.
 */
int	precise_usleep(long usec)
{
	long	start;

	start = get_msec(); //retourne le temps ecoule en milisecondes depuis un temps de ref
	while ((get_msec() - start) * 1000 < usec)
	{
		if (usleep(usec / 1000) == -1)
			return (-1);
	}
	return (0);
}

/*
 * get_msec - Function to get the current time in milliseconds.
 * @return: Returns the current time in milliseconds if successful, 1 on error.
 */
long	get_msec(void)
{
	long			msec;
	struct timeval	time;

	if (!gettimeofday(&time, NULL))
	{
		msec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		return (msec);
	}
	return (1);
}
void	print_msg(t_philo *philo, char *msg)
{
	long	t;

	t = 0;
	if (!is_dead(philo))
	{
		pthread_mutex_lock(&philo->data->write_mutex);
		t = get_msec() - philo->data->start;
		printf("%ld %d %s\n", t, philo->id, msg);
		pthread_mutex_unlock(&philo->data->write_mutex);
	}
}
