/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:47 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/06 12:34:04 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sfinal;
	int		i;
	int		j;
	int		total;

	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	sfinal = (char *)malloc(total * sizeof(char));
	if (sfinal == 0)
		return (0);
	i = -1;
	while (++i < ft_strlen(s1))
		sfinal[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		sfinal[i + j] = s2[j];
	sfinal[i + j] = '\0';
	return (sfinal);
}
