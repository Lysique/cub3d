/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:37:07 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 13:44:32 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	texture_error(int error, char *line)
{
	if (error == MISSING_TEXTURE)
		my_write("Missing texture assignement.\n");
	else if (error == DUPL_TEXTURE)
		my_write("Texture duplicates.\n");
	else if (error == FORMAT_TEXTURE)
		my_write("Bad line format or missing textures.\n");
	else if (error == MISSING_FILE_NAME)
		my_write("Missing RGB color or xpm file name.\n");
	else if (error == MISSING_SPACE)
		my_write("Missing space between texture id and image file or RGB.\n");
	else if (error == XPM_ERROR)
		my_write("Path to XPM image invalid.\n");
	else if (error == BAD_RGB)
		my_write("Bad rgb format.\n");
	if (line)
	{
		my_write("|\033[0;31m");
		my_write(line);
		my_write("\033[0m|\n");
	}
}
