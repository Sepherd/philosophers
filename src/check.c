/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:04:13 by arecce            #+#    #+#             */
/*   Updated: 2023/02/11 15:20:16 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	error_check(void)
{
	printf("An error occurred in arguments. Please try again.\n");
	return (0);
}

int	ft_check_input(char **str)
{
	int	i;
	int	k;

	i = 1;
	while (str[i])
	{
		k = 0;
		while (str[i][k])
		{
			if (!ft_isdigit(str[i][k]))
				return (error_check());
			k++;
		}
		i++;
	}
	return (1);
}

int	check_positive(char **str)
{
	if ((ft_atoi(str[1]) > 0 && ft_atoi(str[1]) < 201) \
			&& ft_atoi(str[2]) > 0 && ft_atoi(str[3]) > 0 \
			&& ft_atoi(str[4]) > 0)
		return (1);
	return (error_check());
}
