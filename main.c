/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:50 by arecce            #+#    #+#             */
/*   Updated: 2023/02/08 19:33:58 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_philo(t_data *data)
{
	data->start = get_time();
	print_msg(data, FORK, 0);
	time_to_do(data->die_ms);
	print_msg(data, DEATH, 0);
}

int	start_philo(t_data *data)
{	
	if (!philos_init(data))
		return (0);
	if (!set_the_table(data))
		return (0);
	if (data->philo_nb == 1)
	{
		lonely_philo(data);
		return (0);
	}
	else
		if (!threads_init(data))
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (0);
	arg_init(&data, av);
	if (!start_philo(&data))
	{
		clear_away(&data);
		free(data.p);
		return (0);
	}
	close_philo(&data);
	return (0);
}
