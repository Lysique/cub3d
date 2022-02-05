/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:22:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/24 08:41:20 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	add_line_to_map(t_cub *cub, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (cub->map && cub->map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		parser_error(MALLOC_ERROR, 0);
	i = -1;
	while ((++i || cub->map) && cub->map[i])
		new[i] = cub->map[i];
	new[i] = cub3d_cpy(line, new);
	new[++i] = 0;
	if (cub->map)
		free(cub->map);
	cub->map = new;
	return (1);
}

char	**parse_map(t_parser *p, char **file)
{
	if (!*file)
		parser_error(MISSING_MAP, 0);
	if (!is_line_empty(*file))
		parser_error(MISSING_NL, 0);
	while (is_line_empty(*file))
		file++;
	while (*file && !is_line_empty(*file))
		add_line_to_map(p->cub, *(file++));
	if (!p->cub->map)
		parser_error(MISSING_MAP, 0);
	map_checker(p->cub->map);
	return (file);
}
