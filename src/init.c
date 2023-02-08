/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:19:15 by arecce            #+#    #+#             */
/*   Updated: 2023/02/06 12:26:29 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	arg_init(t_data *data, char **av)
{
	data->philo_nb = ft_atoi(av[1]);
	data->die_ms = (long long) ft_atoi(av[2]);
	data->eat_ms = (long long) ft_atoi(av[3]);
	data->sleep_ms = (long long) ft_atoi(av[4]);
	if (av[5])
		data->max_eat = ft_atoi(av[5]);
	else
		data->max_eat = -1;
}

int	philos_init(t_data *data)
{
	int	i;

	data->p = malloc(sizeof(t_philo) * (data->philo_nb + 1));
	if (!data->p)
		return (0);
	i = 0;
	while (i++ < data->philo_nb)
	{
		data->p[i].id = i + 1;
		data->p[i].eat_count = 0;
		data->p[i].to_die_ms = 0;
	}
	data->thread = 0;
	return (1);
}
