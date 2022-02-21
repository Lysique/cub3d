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