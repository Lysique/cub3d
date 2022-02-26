/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:04:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 15:03:07 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	count_nb_ennemies(char **map)
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
			if (is_ennemy_char(map[j][i]))
				nb++;
	}
	return (nb);
}

void	ennemy_in_struct(t_cub *cub)
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
			if (is_ennemy_char(map[j][i]))
				add_enemy(cub, map[j][i], j, i);
	}
}

void	ennemy_init(t_cub *cub)
{
	int	nb;

	nb = count_nb_ennemies(cub->map);
	cub->en = malloc(sizeof(t_en) * (nb + 1));
	if (!cub->en)
		parser_error(MALLOC_ERROR, 0);
	cub->en[0].action = -1;
	ennemy_in_struct(cub);
	cub->max_enemies = nb;
	cub->nb_enemies = nb;
}
