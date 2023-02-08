/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:04:13 by arecce            #+#    #+#             */
/*   Updated: 2022/11/30 16:26:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_check(void)
{
	printf("An error occurred in arguments. Please try again.\n");
	exit(0);
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
				error_check();
			k++;
		}
		i++;
	}
	return (1);
}
