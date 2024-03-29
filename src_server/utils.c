/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:39:23 by nmilan            #+#    #+#             */
/*   Updated: 2023/01/16 18:28:05 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	reset_end_message(char *res, int *i, int *is_finish, int size)
{
	if (*i == size)
	{
		res[*i] = '\0';
		*i = 0;
		*is_finish = 3;
	}
}
