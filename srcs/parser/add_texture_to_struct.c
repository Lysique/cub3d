/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:45:51 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 13:56:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	textures_check_line(char *line)
{
	int	i;

	i = 0;
	while (cub3d_isspace(line[i]))
		i++;
	if (line[i])
		parser_error(FORMAT_TEXTURE, line);
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

void	add_img(char *line, t_cub *cub, int index)
{
	t_img	img;

	img = cub->textures[index];
	if (index == F || index == C)
		line = go_to_path(line, 1);
	else
		line = go_to_path(line, 2);
	img.img = mlx_xpm_file_to_image(cub->mlx.mlx, line, &img.w, &img.h);
	if (!img.img)
		parser_error(XPM_ERROR, line);
	cub->textures[index] = img;
}

void	add_texture(char *line, t_cub *cub, int index)
{
	if (cub->textures[index].img)
		parser_error(DUPL_TEXTURE, line);
	add_img(line, cub, index);
}

void	add_texture_to_struct(t_cub *cub, char *line)
{
	int	index;

	if (!line)
		parser_error(MISSING_TEXTURE, 0);
	index = is_texture_line(line);
	if (index == -1)
		textures_check_line(line);
	else 
		add_texture(line, cub, index);
}
