/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:18:39 by ecarlier          #+#    #+#             */
/*   Updated: 2024/04/28 18:33:48 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1); //return 1 if not digit
		i++;
	}
	return (0);

}

void	print_error(int nb)
{
	printf("Incorect input  :\n");
	if (nb == 0)
		printf(WRG_NBR_ARG);
	if (nb == 1)
		printf(WRG_TYPE_ARG);
	if (nb == 2)
		printf(WRG_NBR_PHILO);
	if (nb == 3)
		printf(WRG_SIGN_ARG);

}
/*
	//Only numbers
	//no more than 200 philo
	// all be bigger than 0 except the numbers of meals
*/
int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_all_digit(argv[i]))
		{
			print_error(1);
			return (1);
		}
		if (ft_atoi(argv[1]) > PHILO_MAX)
		{
			print_error(2);
			return (1);
		}
		if (i < 6)
		{
			if (argv[i] <= 0)
			{
				print_error(3);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
