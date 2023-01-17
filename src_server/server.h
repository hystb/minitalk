/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:57:39 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 18:31:42 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

void	receive_message(int sig);
void	alloc_message(int *is_finish, int size, char **res);
void	get_size(int sig, int *size, int *is_finish);
void	get_message(int sig, char *res, int *is_finish, int size);
void	reset_end_message(char *res, int *i, int *is_finish, int size);

#endif
