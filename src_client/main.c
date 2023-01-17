/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:02:57 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 18:41:43 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	int	x;
	int	i;
	int	size;

	i = 0;
	x = 31;
	if (argc != 3)
	{
		write(2, "Error\nRun the program as follow ./client <PID> <INFO>", 53);
		return (0);
	}
	is_int(argv[1]);
	size = ft_strlen(argv[2]);
	send_size(size, x, argv);
	send_message(x, argv, i);
	return (0);
}

void	send_size(int size, int x, char **argv)
{
	while (x >= 0)
	{
		if (size >> x & 1)
			kill(ft_atoi(argv[1]), SIGUSR2);
		else
			kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		x--;
	}
}

void	send_message(int x, char **argv, int i)
{
	while (argv[2][i++])
	{
		x = 7;
		while (x >= 0)
		{
			if (argv[2][i - 1] >> x & 1)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			usleep(100);
			x--;
		}
	}
}
