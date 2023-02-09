/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:09:31 by arecce            #+#    #+#             */
/*   Updated: 2023/02/04 19:09:31 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	threads_init(t_data *data)
{
	int	i;

	i = 0;
	data->dead = 0;
	data->start = get_time();
	pthread_mutex_init(&data->print, NULL);
	while (i < data->philo_nb)
	{
		data->thread = i;
		if (pthread_create(&data->p[i].t, NULL, &routine, (void *) data) != 0)
			return (0);
		i++;
		usleep(1000);
	}
	if (pthread_create(&data->control, NULL, &c_process, (void *) data) != 0)
		return (0);
	usleep(1000);
	if (!threads_join(data))
		return (0);
	return (1);
}

int	threads_join(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->control, NULL) != 0)
		return (0);
	while (i < data->philo_nb)
	{
		if (pthread_join(data->p[i].t, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
