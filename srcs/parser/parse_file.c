/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:18:53 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 15:12:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	are_all_textures_set(t_img *textures)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!textures[i].img)
			return (0);
		i++;
	}
	return (1);
}

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

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		if (!cub3d_isspace(line[i++]))
			return (0);
	return (1);
}
void	parse_file(t_parser *p)
{
	int	i;

	i = 0;
	while (!are_all_textures_set(p->cub->textures))
		add_texture_to_struct(p->cub, p->file[i++]);
	if (p->file[i] && !is_line_empty(p->file[i]))
		parser_error(MISSING_NL, 0);
	while (p->file[i] && is_line_empty(p->file[i]))
		i++;
	if (!p->file[i])
		parser_error(MISSING_MAP, 0);
	while (p->file[i] && !is_line_empty(p->file[i]))
		add_line_to_map(p->cub, p->file[i++]);
	map_checker(p->cub->map);
}
