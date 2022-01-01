/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:40:42 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 11:42:07 by tamighi          ###   ########.fr       */
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

void	assign_textures(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	(void)cub;
}

void	parse_textures(t_cub *cub, int fd)
{
	int	i;

	i = 0;
	init_textures(cub);
	assign_textures(cub, fd);
}
