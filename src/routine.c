/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:09:25 by arecce            #+#    #+#             */
/*   Updated: 2023/02/04 19:09:25 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *) args;
	i = data->thread;
	if (data->max_eat > 0)
	{
		while (data->max_eat > data->p[i].eat_count && data->dead == 0)
		{
			if (dining(data, i) == 0)
				break ;
		}	
	}
	else
	{
		while (data->dead == 0)
		{
			if (dining(data, i) == 0)
				break ;
		}
	}
	return ((void *)0);
}

int	dining(t_data *data, int i)
{
	if (data->dead == 0)
		eat(data, i);
	if (data->dead == 0)
		p_sleep(data, i);
	if (data->dead == 0)
		think(data, i);
	if (data->dead == 0)
		return (1);
	return (0);
}

void	*c_process(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *) args;
	i = 0;
	if (data->max_eat > 0)
	{
		while (data->max_eat > data->p[i].eat_count \
				&& data->dead == 0)
			if (death(data, &i) == 1)
				break ;
	}
	else
	{
		while (data->dead == 0)
			if (death(data, &i) == 1)
				break ;
	}
	return ((void *)0);
}
