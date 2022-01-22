/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:02:22 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 15:05:43 by tamighi          ###   ########.fr       */
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

void	parser(char *argument, t_cub *cub)
{
	t_parser	p;

	parser_init(&p, cub);
	p.fd = open(argument, O_RDONLY);
	if (p.fd == -1)
		parser_error(OPEN_ERROR, 0);
	fd_to_arr(&p);
	parse_file(&p);
	player_init(cub);
	close(p.fd);
	free_my_arr(p.file);
	printf("OK\n");
	exit(0);
}
