/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:43:56 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 17:59:00 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 1 || argv[0][0] != '\0')
		write(2, "Error\nNo need Args", 19);
	pid = getpid();
	ft_printf("Server has started\nPID : %d\n", pid);
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	while (1)
		pause();
	return (0);
}

void	receive_message(int sig)
{
	static char	*res = NULL;
	static int	size = 0;
	static int	is_finish = 0;

	if (is_finish == 0)
		get_size(sig, &size, &is_finish);
	else if (is_finish == 1)
		alloc_message(&is_finish, size, &res);
	if (is_finish == 2)
		get_message(sig, res, &is_finish, size);
	if (is_finish == 3)
	{
		ft_printf("%s\n", res);
		is_finish = 0;
		free(res);
		res = NULL;
		size = 0;
	}
}

void	alloc_message(int *is_finish, int size, char **res)
{
	*res = malloc (sizeof(char) * (size + 1));
	if (!*res)
		exit (1);
	*is_finish = 2;
}

void	get_size(int sig, int *size, int *is_finish)
{
	static int	i = 0;

	if (i < 32)
	{
		if (sig == 30)
		{
			*size *= 2;
			*size = *size + 0;
		}
		else
		{
			*size *= 2;
			*size = *size + 1;
		}
		i++;
		if (i == 32)
		{
			*is_finish = 1;
			i = 0;
		}
	}
}

void	get_message(int sig, char *res, int *is_finish, int size)
{
	static int	x = 0;
	static char	c = 0;
	static int	i = 0;

	if (x++ < 8)
	{
		if (sig == 30)
		{
			c *= 2;
			c = c + 0;
		}
		else
		{
			c *= 2;
			c = c + 1;
		}
	}
	if (x == 8)
	{
		res[i++] = c;
		c = 0;
		x = 0;
	}
	reset_end_message(res, &i, is_finish, size);
}
