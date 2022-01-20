/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 13:58:25 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parser(char *argument, t_cub *cub)
{
	int		fd;
	char	**file;

	fd = open(argument, O_RDONLY);
	if (fd == -1)
		parser_error(cub, 0, 0);
	file = fd_to_arr(cub, fd);
	parse_textures(cub, file);
//	parse_map(cub, file);
//	player_init(cub);
	printf("OK\n");
	exit(0);
}
