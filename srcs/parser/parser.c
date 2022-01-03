/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 15:38:45 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	player_data(char c, t_cub *cub, int i, int j)
{
	if (c == 'S')
		cub->player.view = 180;
	else if (c == 'N')
		cub->player.view = 0;
	else if (c == 'E')
		cub->player.view = 90;
	else if (c == 'W')
		cub->player.view = 270;
	cub->player.x = i * UNIT + UNIT / 2;
	cub->player.y = j * UNIT + UNIT / 2;
}

void	player_init(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cub->map[++j])
	{
		while (cub->map[j][++i])
		{
			if (is_player_char(cub->map[j][i]))
			{
				player_data(cub->map[j][i], cub, i, j);
				cub->map[j][i] = '0';
				return ;
			}
		}
		i = -1;
	}
}

void	parser(char *argument, t_cub *cub)
{
	int	fd;

	fd = open(argument, O_RDONLY);
	if (fd == -1)
		parser_error(cub, 1);
	if (parse_textures(cub, fd) == -1)
	{
		close(fd);
		parser_error(cub, 2);
	}
	if (parse_map(cub, fd) == -1)
	{
		close(fd);
		parser_error(cub, 3);
	}
	close(fd);
	player_init(cub);
}
