/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 16:40:35 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_parser	*set_parser_ptr(t_parser *ptr)
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
	p->ptr = 0;
	set_parser_ptr(p);
}

void	parse_file(t_parser *p)
{
	char	**file;

	file = p->file;
	if (!file)
		parser_error(EMPTY_FILE, 0);
	file = parse_textures(p, file);
	file = parse_map(p, file);
}

void	parser(char *argument, t_cub *cub)
{
	t_parser	p;

	parser_init(&p, cub);
	p.fd = open(argument, O_RDONLY);
	if (p.fd == -1)
		parser_error(OPEN_ERROR, 0);
	fd_to_arr(&p);
	parse_file(&p);
	player_init(p.cub);
	parser_error(1000, 0);
	close(p.fd);
	free_my_arr(p.file);
}
