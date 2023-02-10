/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:37 by arecce            #+#    #+#             */
/*   Updated: 2023/02/10 19:39:00 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

/*******************
 	  MESSAGES
********************/
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define FORK "has taken a fork\n"
# define DEATH "died\n"

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		to_die_ms;
	pthread_mutex_t	fork;
	pthread_t		t;
}				t_philo;

typedef struct s_data
{
	int				philo_nb;
	long long		die_ms;
	long long		eat_ms;
	long long		sleep_ms;
	int				max_eat;
	long long		start;
	int				dead;
	int				thread;
	t_philo			*p;
	pthread_t		control;
	pthread_mutex_t	print;
}				t_data;

void			error_check(void);
unsigned int	ft_atoi(char *str);
int				ft_isdigit(int c);
int				ft_check_input(char **str);
void			print_msg(t_data *data, char *msg, int id);
int				check_positive(char **str);
void			arg_init(t_data *data, char **av);
int				philos_init(t_data *data);
int				set_the_table(t_data *data);
void			clear_away(t_data *data);
int				threads_init(t_data *data);
int				threads_join(t_data *data);
long long		get_time(void);
long long		now_ms(long long now);
// void			time_to_do(useconds_t time);
void			eat(t_data *data, int i);
void			p_sleep(t_data *data, int i);
void			think(t_data *data, int i);
int				death(t_data *data, int *i);
// void			drop_forks(t_data *data, int i);
void			*routine(void *args);
int				dining(t_data *data, int i);
void			*c_process(void *args);
void			close_philo(t_data *data);
void			ft_usleep(useconds_t time);

#endif