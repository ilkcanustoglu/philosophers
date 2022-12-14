/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <iustoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:14:57 by iustoglu          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:44 by iustoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo(t_args *args)
{
	t_philo	**philo;
	int		i;

	i = -1;
	philo = (t_philo **)malloc(sizeof(t_philo *) * (args->nb_philo + 1));
	philo[args->nb_philo] = NULL;
	while (++i < args->nb_philo)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		memset(philo[i], 0, sizeof(t_philo));
		philo[i]->num = i;
		philo[i]->args = args;
		philo[i]->nb_eat = 0;
		philo[i]->is_finished = 0;
		philo[i]->r_fork = i;
		philo[i]->l_fork = (i + 1) % (args->nb_philo);
	}
	return (philo);
}

void	init_mutex(t_args *ag)
{
	int	i;

	i = -1;
	ag->forks = (pthread_mutex_t *)malloc(sizeof(*ag->forks) * ag->nb_philo);
	while (++i < ag->nb_philo)
		pthread_mutex_init(&ag->forks[i], NULL);
	pthread_mutex_init(&ag->printf_lock, NULL);
	pthread_mutex_init(&ag->check_lock, NULL);
	pthread_mutex_init(&ag->nb_lock, NULL);
	pthread_mutex_init(&ag->death_lock, NULL);
}
