/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iustoglu <iustoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:14:43 by iustoglu          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:22 by iustoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_error(short error_code)
{
	if (error_code == ARGS_ERROR)
		printf("Argument is not a digit "
			"or it overflows int "
			"or it is negative "
			"or have two plus signs\n");
	else if (error_code == ARGS_NUM_ERROR)
		printf("Wrong number of arguments\n");
	return (1);
}
