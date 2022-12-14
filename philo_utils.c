/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <iustoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:15:47 by iustoglu          #+#    #+#             */
/*   Updated: 2022/11/30 14:40:08 by iustoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *ph)
{
	if (ph->num % 2 == 1)
	{
		pthread_mutex_lock(&ph->args->forks[ph->r_fork]);
		pthread_mutex_lock(&ph->args->forks[ph->l_fork]);
	}
	else
	{
		pthread_mutex_lock(&ph->args->forks[ph->l_fork]);
		pthread_mutex_lock(&ph->args->forks[ph->r_fork]);
	}
	if (!check_death(ph))
	{
		pthread_mutex_lock(&ph->args->printf_lock);
		printf("%-5ld %d has taken a fork\n", get_time() - ph->start_t,
			ph->num + 1);
		printf("%-5ld %d has taken a fork\n", get_time() - ph->start_t,
			ph->num + 1);
		pthread_mutex_unlock(&ph->args->printf_lock);
	}
}

void	eat_time(t_philo *ph)
{
	take_forks(ph);
	if (!check_death(ph))
	{
		printf("%-5ld %d is eating\n", get_time() - ph->start_t, ph->num + 1);
		set_meals(ph);
		set_nb(ph);
		psleep(ph->args->eat_t);
	}
	pthread_mutex_unlock(&ph->args->forks[ph->l_fork]);
	pthread_mutex_unlock(&ph->args->forks[ph->r_fork]);
}

void	sleep_time(t_philo *ph)
{
	if (!check_death(ph))
	{
		pthread_mutex_lock(&ph->args->printf_lock);
		printf("%-5ld %d is sleeping\n", get_time() - ph->start_t, ph->num + 1);
		pthread_mutex_unlock(&ph->args->printf_lock);
		psleep(ph->args->sleep_t);
	}
}

void	think_time(t_philo *ph)
{
	if (!check_death(ph))
	{
		pthread_mutex_lock(&ph->args->printf_lock);
		printf("%-5ld %d is thinking\n", get_time() - ph->start_t, ph->num + 1);
		pthread_mutex_unlock(&ph->args->printf_lock);
		usleep(500);
	}
}

void	die_time(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->printf_lock);
	printf("%-5ld %d died\n", get_time() - ph->start_t, ph->num + 1);
	pthread_mutex_unlock(&ph->args->printf_lock);
	set_death(ph);
}
