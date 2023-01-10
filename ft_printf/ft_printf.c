/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:01:18 by nmilan            #+#    #+#             */
/*   Updated: 2022/11/22 14:07:00 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;
	int		mem_len;

	len = 0;
	i = 0;
	if (!format)
		return (len);
	va_start(arg, format);
	while (format[i])
	{
		mem_len = len;
		if (format[i] == '%' && format[i + 1] != '\0')
			len += switchman(arg, format[++i]);
		else if (format[i] != '%')
			len += ft_putchar_fd(format[i], 1);
		if (len < mem_len)
			return (-1);
		i++;
	}
	va_end(arg);
	return (len);
}
