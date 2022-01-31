/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:45:51 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/31 15:30:54 by tamighi          ###   ########.fr       */
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

char	*go_to_path(char *line, int i)
{
	int	j;

	if (!line[i])
		parser_error(MISSING_FILE_NAME, line);
	else if (!cub3d_isspace(line[i]))
		parser_error(MISSING_SPACE, line);
	while (cub3d_isspace(line[i]))
		i++;
	if (!line[i])
		parser_error(MISSING_FILE_NAME, line);
	j = i;
	while (!cub3d_isspace(line[j]) && line[j])
		j++;
	line[j] = '\0';
	return (&line[i]);
}

char	**parse_textures(t_parser *p, char **file)
{
	int	index;

	while (!are_all_textures_set(p->cub->textures))
	{
		index = is_texture_line(*file);
		if (index == -1 && !is_line_empty(*file))
			parser_error(FORMAT_TEXTURE, *file);
		if (cub->textures[index].img)
			parser_error(DUPL_TEXTURE, line);
		if (index == F || index == C)
			line = go_to_path(line, 1);
		else
			line = go_to_path(line, 2);
		add_texture(*file, p->cub, index);
		file++;
	}
	return (file);
}
