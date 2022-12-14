/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <iustoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:15:39 by iustoglu          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:58 by iustoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **s)
{
	char	**p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p) || ft_atol(*p) < 0 || ft_atol(*p) > INT_MAX)
			return (1);
		++p;
	}
	return (0);
}

t_args	*parse_args(char **s)
{
	t_args	*ag;

	ag = (t_args *)malloc(sizeof(t_args));
	ag->nb_philo = ft_atol(*s++);
	ag->die_t = ft_atol(*s++);
	ag->eat_t = ft_atol(*s++);
	ag->sleep_t = ft_atol(*s++);
	if (*s)
		ag->max_eat = ft_atol(*s++);
	else
		ag->max_eat = -1;
	ag->philo_ate = 0;
	ag->stop_sim = 0;
	return (ag);
}
