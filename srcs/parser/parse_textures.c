/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:40:42 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 13:44:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
		cub->textures[i++].img = 0;
}

int	are_all_textures_set(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!cub->textures[i].img)
			return (0);
		i++;
	}
	return (1);
}

void	assign_textures(t_cub *cub, int fd)
{
	char	*line;

	while (are_all_textures_set(cub) == 0)
	{
		line = get_next_line(fd);
		if (!line || add_texture_to_struct(line, cub) == -1)
		{
			if (line)
				free(line);
			close(fd);
			parser_error(cub, 2);
		}
		free(line);
	}
}

void	parse_textures(t_cub *cub, int fd)
{
	init_textures(cub);
	assign_textures(cub, fd);
}
