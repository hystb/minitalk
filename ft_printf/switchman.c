/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:10:36 by nmilan            #+#    #+#             */
/*   Updated: 2022/11/22 12:47:09 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	switchman(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (c == 'p')
		return ((ft_puthex_ptr(va_arg(arg, void *))));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int), 1));
	else if (c == 'x')
		return (ft_puthex_min(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_maj(va_arg(arg, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &c, 1));
}
