/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/12 09:34:04 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	player_data(char c, t_cub *cub, int i, int j)
{
	if (c == 'S')
		cub->player.angle = PI / 2.;
	else if (c == 'N')
		cub->player.angle = 3 * PI / 2.;
	else if (c == 'E')
		cub->player.angle = 0;
	else if (c == 'W')
		cub->player.angle = PI;
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
			if (is_player_char(cub->map[j][i], 0))
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
	{
		printf("Error\nCouldn't open the file.\n");
		parser_error(cub, 1);
	}
	if (parse_textures(cub, fd) == -1)
	{
		printf("Error\nTexture initialisation didn't work properly.\n");
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
