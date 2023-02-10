/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:58:29 by arecce            #+#    #+#             */
/*   Updated: 2023/02/10 19:26:46 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num <= 0)
		error_check();
	return (num);
}

void	print_msg(t_data *data, char *msg, int id)
{
	long long	now;

	if (data->dead == 0)
	{
		pthread_mutex_lock(&data->print);
		now = now_ms(data->start);
		printf("%llu %d %s", now, id + 1, msg);
		pthread_mutex_unlock(&data->print);
	}
}

void	close_philo(t_data *data)
{
	clear_away(data);
	pthread_mutex_destroy(&data->print);
	free(data->p);
}
