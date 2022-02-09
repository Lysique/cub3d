/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:56:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/07 09:57:23 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	is_wall(char c)
{
	if (c == '1')
		return (c);
	return (0);
}

int	is_door(char c)
{
	if (c == '2' || c == '3')
		return (c);
	return (0);
}

int	is_open_element_to_draw(char c)
{
	if (c == '3')
		return (c);
	return (0);
}

int	is_closed_element(char c)
{
	if (c == '1' || c == '2')
		return (c);
	return (0);
}
