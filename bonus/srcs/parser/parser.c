/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/22 10:04:09 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_parser	*set_parserptr(t_parser *ptr)
{
	static t_parser	*p = 0;

	if (!p)
		p = ptr;
	return (p);
}

void	parser_init(t_parser *p, t_cub *cub)
{
	p->cub = cub;
	p->file = 0;
	set_parserptr(p);
}

void	parse_file(t_parser *p)
{
	char	**file;

	file = p->file;
	if (!file)
		parser_error(EMPTY_FILE, 0);
	file = parse_textures(p, file);
	file = parse_map(p, file);
	while (*file)
	{
		if (!is_line_empty(*(file++)))
			parser_error(FILE_NOT_ENDED, 0);
	}
}

void	parser(char *argument, t_cub *cub)
{
	t_parser	p;

	parser_init(&p, cub);
	p.fd = open(argument, O_RDWR);
	if (p.fd == -1)
		parser_error(OPEN_ERROR, 0);
	fd_to_arr(&p);
	parse_file(&p);
	player_init(p.cub);
	doors_init(p.cub);
	ennemy_init(p.cub);
	map_dist_init(p.cub);
	close(p.fd);
	free_my_arr(p.file);
}
