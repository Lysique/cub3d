/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:47 by tuytters          #+#    #+#             */
/*   Updated: 2022/03/07 09:40:39 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

t_time	get_microtime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_usec);
}

t_time	get_time(void)
{
	struct timeval	tv;
	t_time			time;

	gettimeofday(&tv, 0);
	time = tv.tv_usec / 1000;
	time += tv.tv_sec * 1000;
	return (time);
}

int	get_door_index(t_door *d, int y, int x)
{
	int	i;

	i = 0;
	while (d[i].open != -1)
	{
		if (d[i].y == y && d[i].x == x)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}
