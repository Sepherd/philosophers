/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:09:04 by arecce            #+#    #+#             */
/*   Updated: 2023/02/04 19:09:04 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_data *data, int i)
{
	pthread_mutex_lock(&data->p[i].fork);
	print_msg(data, FORK, i);
	if (i == data->philo_nb - 1)
		pthread_mutex_lock(&data->p[0].fork);
	else
		pthread_mutex_lock(&data->p[i + 1].fork);
	print_msg(data, FORK, i);
	print_msg(data, EAT, i);
	data->p[i].to_die_ms = get_time();
	ft_usleep(data->eat_ms);
	pthread_mutex_unlock(&data->p[i].fork);
	if (i == data->philo_nb - 1)
		pthread_mutex_unlock(&data->p[0].fork);
	else
		pthread_mutex_unlock(&data->p[i + 1].fork);
	data->p[i].eat_count++;
}

void	p_sleep(t_data *data, int i)
{
	print_msg(data, SLEEP, i);
	ft_usleep(data->sleep_ms);
}

void	think(t_data *data, int i)
{
	print_msg(data, THINK, i);
}

int	death(t_data *data, int *i)
{
	long long	time;

	if (*i == data->philo_nb)
		*i = 0;
	time = now_ms(data->p[*i].to_die_ms);
	if (time > data->die_ms)
	{
		print_msg(data, DEATH, *i);
		data->dead = 1;
		return (1);
	}
	i++;
	return (0);
}
