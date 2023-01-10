/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:34:40 by nmilan            #+#    #+#             */
/*   Updated: 2022/11/22 13:39:55 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_rev_in_tab(char *str, int size)
{
	int		i;
	char	tmp;
	int		end;

	i = 0;
	end = size - 1;
	while (i < end)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		i++;
		end--;
	}
}

static int	ft_put_in_nb(unsigned long nb, int minus, int fd)
{
	int		i;
	char	table_num[11];

	i = 0;
	while (nb > 0)
	{
		if (nb % 16 > 9)
			table_num[i] = (nb % 16 % 10) + 'A';
		else
			table_num[i] = (nb % 16) + '0';
		nb = nb / 16;
		i++;
	}
	if (minus == 1)
		table_num[i++] = '-';
	table_num[i] = '\0';
	ft_rev_in_tab(table_num, ft_strlen(table_num));
	return (ft_putstr_fd(table_num, fd));
}

int	ft_puthex_maj(unsigned long nb)
{
	int	minus;

	minus = 0;
	if (nb > 0)
	{
		return (ft_put_in_nb(nb, minus, 1));
	}
	else if (nb < 0)
	{
		nb = -nb;
		minus = 1;
		return (ft_put_in_nb(nb, minus, 1));
	}
	else if (nb == 0)
	{
		return (ft_putchar_fd('0', 1));
	}
	return (0);
}
