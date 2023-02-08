/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:09:19 by arecce            #+#    #+#             */
/*   Updated: 2023/02/04 19:09:19 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	set_the_table(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->philo_nb)
		if (pthread_mutex_init(&data->p[i].fork, NULL) != 0)
			return (0);
	return (1);
}

void	clear_away(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->philo_nb)
		pthread_mutex_destroy(&data->p[i].fork);
}
