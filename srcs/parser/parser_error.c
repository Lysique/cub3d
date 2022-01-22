/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:54:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 14:16:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	texture_error(int error, char *line)
{
	if (error == MISSING_TEXTURE)
		my_write("Missing textures.\n");
	else if (error == DUPL_TEXTURE)
		my_write("Texture duplicates.\n");
	else if (error == FORMAT_TEXTURE)
		my_write("Bad line format.\n");
	else if (error == MISSING_FILE_NAME)
		my_write("Missing xpm file name.\n");
	else if (error == MISSING_SPACE)
		my_write("Missing space between texture id and image name.\n");
	else if (XPM_ERROR)
		my_write("Path to XPM image invalid.\n");
	if (!line)
		return ;
	my_write("|\033[0;31m");
	my_write(line);
	my_write("\033[0m|\n");
}

void	open_file_error(void)
{
	if (errno == EACCES)
		my_write("Requested access to the file is not allowed.\n");
	else if (errno == ENOENT)
		my_write("The file does not exist.\n");
	else
		my_write("Unknown error while opening the file.\n");
}

void	draw_map_error(char **map, t_coord *c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	my_write("\n");
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (i == c->i && j == c->j)
				my_write("\033[0;31m");
			write(1, &map[j][i], 1);
			if (i == c->i && j == c->j)
				my_write("\033[0m");
		}
		i = -1;
		my_write("\n");
	}
}

void	map_error(int error, char **map, t_coord *c)
{
	if (error == MISSING_NL)
		my_write("Missing newline after texture initialization.\n");
	else if (error == MISSING_MAP)
		my_write("Map is missing in the file.\n");
	else if (error == UNKNOWN_CHAR)
		my_write("Unknown character in the map.\n");
	else if (error == OPEN_MAP)
		my_write("Map is open. Close it.\n");
	else if (error == NO_PLAYER)
		my_write("No player on the map.\n");
	else if (error == MULT_PLAYER)
		my_write("Too many player on the map.\n");
	if (!c)
		return ;
	draw_map_error(map, c);
}

void	parser_error(int error, void *ptr)
{
	t_parser	*p;

	p = set_parser_ptr(0);
	my_write("Error\n");
	if (error == OPEN_ERROR)
		open_file_error();
	else if (error == MALLOC_ERROR)
		my_write("Memory didn't allocate properly.\n");
	else if (error / NB_ERRORS == TEXTURE_ERROR)
		texture_error(error, (char *)ptr);
	else if (error / NB_ERRORS == MAP_ERROR)
		map_error(error, p->cub->map, (t_coord *)ptr);
	parser_free(p);
	my_write("\n");
	wr_and_ex(0, 1);
}
