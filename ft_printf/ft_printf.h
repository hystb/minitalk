/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:11:17 by nmilan            #+#    #+#             */
/*   Updated: 2022/11/19 14:44:02 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putstr_fd(char *s, int fd);
int		switchman(va_list arg, char c);
size_t	ft_strlen(const char *str);
int		ft_puthex_ptr(void *nb);
int		ft_puthex_maj(unsigned long nb);
int		ft_puthex_min(unsigned long nb);
int		ft_putnbr_unsigned(unsigned int nb, int fd);
int		ft_printf(const char *format, ...);

#endif
