/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:57:51 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/10 16:22:32 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"

void	get_message(int sig);
int		convert_back_int(char *str, int *is_first);

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server has started\nPID : %d\n", pid);
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
		pause();
	return (0);
}

void	get_message(int sig)
{
	static int		i = 0;
	static int		is_first = 0;
	char			len[33];
	char			*res;

	if (i < 32)
	{
		if (sig == 30)
			len[i] = '0';
		else
			len[i] = '1';
		i++;
	}
	else
	{
		if (is_first == 0)
		{
			res = malloc(sizeof(char) * (convert_back_int(len, &is_first) + 1));
			ft_printf(" malloc : %d\n", convert_back_int(len, &is_first));
		}
		else
		{
			len[32] = '\0';
			ft_printf("%s\n", len);
		}
	}
}

int	convert_back_int(char *str, int *is_first)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	*is_first = 1;
	while (i < 31)
	{
		res = res + str[i] - '0';
		res = res * 2;
		i++;
	}
	return (res);
}

//char c
//c = 0 + c << 1;
//c = 1 + c << 1;
