/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:02:57 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 18:04:17 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	send_size(int size, int x, char **argv);
static void	send_message(int x, char **argv, int i);

static int	ft_atoi(const char *str)
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

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	x;
	int	i;
	int	size;

	i = 0;
	x = 31;
	if (argc != 3)
	{
		write(2, "Error\nRun the program as follow ./client <PID> <INFO>", 61);
		return (0);
	}
	size = ft_strlen(argv[2]);
	send_size(size, x, argv);
	send_message(x, argv, i);
	return (0);
}

static void	send_size(int size, int x, char **argv)
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

static void	send_message(int x, char **argv, int i)
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
