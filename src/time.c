/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:12:47 by arecce            #+#    #+#             */
/*   Updated: 2023/02/10 19:38:27 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		printf("ERROR!\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	now_ms(long long now)
{
	if (now > 0)
		return (get_time() - now);
	return (0);
}

// void	time_to_do(useconds_t time)
// {
// 	usleep(time * 1000);
// }

void	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}
