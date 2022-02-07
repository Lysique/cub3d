/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:47 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/07 10:18:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

t_time	get_time(void)
{
	struct timeval	tv;
	t_time			time;

	gettimeofday(&tv, 0);
	time = tv.tv_usec / 1000;
	time += tv.tv_sec * 1000;
	return (time);
}

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}
