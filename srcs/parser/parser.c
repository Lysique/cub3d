/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/04 13:33:22 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	player_data(char c, t_cub *cub, int i, int j)
{
	if (c == 'S')
		cub->player.angle = PI;
	else if (c == 'N')
		cub->player.angle = 2 * PI;
	else if (c == 'E')
		cub->player.angle = 0.5 * PI;
	else if (c == 'W')
		cub->player.angle = 1.5 * PI;
	cub->player.x = i + 0.5;
	cub->player.y = j + 0.5;
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
