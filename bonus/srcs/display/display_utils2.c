/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 14:54:08 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

static int	ft_lennb(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*valeur;
	int				len;
	long long int	nb;

	nb = n;
	len = ft_lennb(nb);
	valeur = malloc(sizeof(char) * len + 1);
	if (!valeur)
		return (NULL);
	if (nb < 0)
	{
		valeur[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		valeur[0] = '0';
	valeur[len--] = '\0';
	while (nb)
	{
		valeur[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (valeur);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sfinal;
	int		i;
	int		j;
	int		total;

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
