/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:38:51 by nmilan            #+#    #+#             */
/*   Updated: 2022/11/21 16:40:30 by nmilan           ###   ########.fr       */
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

static int	ft_put_in_hexa(unsigned long nb, int fd)
{
	int		i;
	char	table_num[17];

	i = 0;
	while (nb > 0)
	{
		if ((nb % 16) > 9)
			table_num[i] = (nb % 16 % 10) + 'a';
		else
			table_num[i] = (nb % 16) + '0';
		nb = nb / 16;
		i++;
	}
	table_num[i] = '\0';
	ft_rev_in_tab(table_num, ft_strlen(table_num));
	if (ft_putstr_fd(table_num, fd) == -1)
		return (-1);
	return (i + 2);
}

int	ft_puthex_ptr(void *nb)
{
	unsigned long	address;

	if (write(1, "0x", 2) == -1)
		return (-1);
	if (!nb)
	{
		if (write (1, "0", 1) < 0)
			return (-1);
		return (3);
	}
	address = (unsigned long) nb;
	if (nb > 0)
	{
		return (ft_put_in_hexa(address, 1));
	}
	else if (nb == 0)
		return (write(1, "0", 1));
	return (0);
}
