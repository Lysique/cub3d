/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:46:44 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/07 14:33:25 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	count_nb_doors(char **map)
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
			if (is_door_char(map[j][i]))
				nb++;
	}
	return (nb);
}

void	add_door(t_cub *cub, char c, int j, int i)
{
	int	k;

	k = 0;
	while (cub->doors[k].open != -1)
		k++;
	cub->doors[k].x = i;
	cub->doors[k].y = j;
	if (c == '2')
		cub->doors[k].open = 0;
	else if (c == '3')
		cub->doors[k].open = 1;
	cub->doors[k].is_opening = 0;
	cub->doors[k].went_through = 0;
	cub->map[j][i] = '1';
	cub->doors[++k].open = -1;
}

void	doors_in_struct(t_cub *cub)
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
			if (is_door_char(map[j][i]))
				add_door(cub, map[j][i], j, i);
	}
}

void	doors_init(t_cub *cub)
{
	int	nb;

	nb = count_nb_doors(cub->map);
	cub->doors = malloc(sizeof(t_door) * (nb + 1));
	if (!cub->doors)
		parser_error(MALLOC_ERROR, 0);
	cub->doors[0].open = -1;
	doors_in_struct(cub);
}
