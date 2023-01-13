/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:57:39 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/12 14:37:30 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_data
{
	int		is_first;
	int		is_finish;
	char	*message;
	int		size;
}		t_data;

void	get_message(int sig);
int		convert_back_int(char *str, int *is_first);
void	get_size(int sig);

#endif
