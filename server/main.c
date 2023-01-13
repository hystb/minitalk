/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:57:51 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/12 14:39:55 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_data	g_data;

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	g_data.is_finish = 0;
	g_data.is_first = 0;
	ft_printf("Server has started\nPID : %d\n", pid);
	if (g_data.is_first == 0)
	{
		signal(SIGUSR1, get_size);
		signal(SIGUSR2, get_size);
	}
	else
	{
		g_data.message = malloc(sizeof(char) * (g_data.size + 1));
		if (!g_data.message)
			exit(1);
		signal(SIGUSR1, get_message);
		signal(SIGUSR2, get_message);
	}
	while (1)
	{
		pause();
		if (g_data.is_finish == 1)
		{
			ft_printf("%d", g_data.message);
			g_data.is_finish = 0;
		}
	}
	return (0);
}

void	get_size(int sig)
{
	static int	i = 0;

	if (i < 32)
	{
		if (sig == 30)
		{
			g_data.size *= 2;
			g_data.size = g_data.size + 0;
		}
		else
		{
			g_data.size *= 2;
			g_data.size = g_data.size + 1;
		}
		i++;
		if (i == 32)
		{
			g_data.is_first = 1;
			i = 0;
		}
	}
}

void	get_message(int sig)
{
	static int	x = 0;
	static char	c = 0;
	static int	i = 0;

	if (x++ < 8)
	{
		if (sig == 30)
		{
			ft_printf("ok\n");
			c *= 2;
			c = c + 0;
		}
		else
		{
			ft_printf("ok\n");
			c *= 2;
			c = c + 1;
		}
		if (x == 8)
		{
			g_data.message[i++] = c;
			c = 0;
			x = 0;
		}
		if (i == g_data.size - 1)
			g_data.is_finish = 1;
	}
}
//char c
//c = 0 + c << 1;
//c = 1 + c << 1;
