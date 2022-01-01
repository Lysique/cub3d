/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 17:11:11 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
}
