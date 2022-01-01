/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:54:15 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 10:33:21 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	my_write(char *str)
{
	write(1, str, ft_strlen(str));
}
