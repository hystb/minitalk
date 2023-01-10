/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:49:33 by nmilan            #+#    #+#             */
/*   Updated: 2022/11/19 14:01:53 by nmilan           ###   ########.fr       */
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

static int	ft_put_in_nb(unsigned int nb, int minus, int fd)
{
	int		i;
	char	table_num[12];

	i = 0;
	while (nb > 0)
	{
		table_num[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	if (minus == 1)
	{
		table_num[i] = '-';
		i++;
	}
	table_num[i] = '\0';
	ft_rev_in_tab(table_num, ft_strlen(table_num));
	return (ft_putstr_fd(table_num, fd));
}

int	ft_putnbr_unsigned(unsigned int nb, int fd)
{
	int	minus;

	minus = 0;
	if (nb > 0)
	{
		return (ft_put_in_nb(nb, minus, fd));
	}
	else if (nb == 0)
	{
		return (ft_putchar_fd('0', fd));
	}
	return (write (fd, "(null)", 6));
}
