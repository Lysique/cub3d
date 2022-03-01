/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medikit_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:34:20 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:57:35 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	count_nb_medikits(char **map)
{
	int	i;
	int	j;
	int	nb;

	j = -1;
	nb = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == 'm')
				nb++;
	}
	return (nb);
}

void	add_medikit(t_cub *cub, int j, int i)
{
	int	k;

	k = 0;
	while (cub->mkits[k].active != -1)
		k++;
	cub->mkits[k].x = i + 0.5;
	cub->mkits[k].y = j + 0.5;
	cub->mkits[k].active = 1;
	cub->mkits[k].img = cub->sprites[MEDKIT][0];
	cub->mkits[++k].active = -1;
	cub->map[j][i] = '0';
}

void	medikit_in_struct(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;

	j = -1;
	map = cub->map;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == 'm')
				add_medikit(cub, j, i);
	}
}

void	medikit_init(t_cub *cub)
{
	int	nb;

	nb = count_nb_medikits(cub->map);
	cub->mkits = malloc(sizeof(t_mkit) * (nb + 1));
	if (!cub->mkits)
		parser_error(MALLOC_ERROR, 0);
	cub->mkits[0].active = -1;
	medikit_in_struct(cub);
}
