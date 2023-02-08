/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:12:47 by arecce            #+#    #+#             */
/*   Updated: 2023/02/08 16:36:30 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		printf("ERROR!\n");
	return ((tv.tv_sec * (long long)1000) + (tv.tv_usec / 1000));
}

// long long	now_ms(t_data *data)
// {
// 	long long	now;

// 	now = get_time() - data->start;
// 	return (now);
// }

long long	now_ms(long long now)
{
	if (now > 0)
		return (get_time() - now);
	return (0);
}

void	time_to_do(long long time)
{
	usleep(time * 1000);
}
