/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:47 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/04 13:39:43 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sfinal;
	size_t	i;
	size_t	j;
	size_t	total;

	if (s1 == 0 || s2 == 0)
		return (0);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	sfinal = (char *)malloc(total * sizeof(char));
	if (sfinal == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		sfinal[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		sfinal[i + j] = s2[j];
		j++;
	}
	sfinal[i + j] = '\0';
	return (sfinal);
}
