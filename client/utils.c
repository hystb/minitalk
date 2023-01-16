/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:17:59 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 18:43:39 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(2, "Error\nNot correct format PID", 28);
			exit (0);
		}
		i++;
	}
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
	{
		write(2, "Error\nNot correct format PID", 28);
		exit (0);
	}
	if (ft_strlen(str) > 12)
	{
		write(2, "Error\nNot correct format PID", 28);
		exit (0);
	}
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result != ((result * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		result = result * 10 + sign * (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
