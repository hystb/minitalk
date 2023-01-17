/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:20:00 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 18:35:02 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

void	send_size(int size, int x, char **argv);
void	send_message(int x, char **argv, int i);
void	is_int(char *str);
long	ft_atoi(const char *str);
int		ft_strlen(char *str);

#endif
