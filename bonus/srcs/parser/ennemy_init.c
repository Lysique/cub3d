/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:04:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 14:50:05 by tamighi          ###   ########.fr       */
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


void	add_ennemy(t_cub *cub, char c, int j, int i)
{
	int	k;

	k = 0;
	(void)c;
	while (cub->en[k].action != -1)
		k++;
	cub->en[k].type = NAKED_EN;
	cub->en[k].x = i + 0.5;
	cub->en[k].y = j + 0.5;
	cub->en[k].angle = PI / 2;
	cub->en[k].action = E_STILL;
	cub->en[k].sprite = 0;
	cub->en[k].life = ENNU_LIFE;
	cub->en[k].nb_sprites = ENNU_NBSPR;
	cub->en[k].nb_runspr = ENNU_NBRUNSPR;
	cub->en[k].img = cub->sprites[NAKED_EN][0];
	cub->en[k].hbox = 0.3;
	cub->en[k].time = 0;
	cub->en[++k].action = -1;
	cub->map[j][i] = '0';
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
				add_ennemy(cub, map[j][i], j, i);
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
}
