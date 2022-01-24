/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:37:07 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/24 08:52:53 by tamighi          ###   ########.fr       */
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
		my_write("Bad line format or missing textures.\n");
	else if (error == MISSING_FILE_NAME)
		my_write("Missing xpm file name.\n");
	else if (error == MISSING_SPACE)
		my_write("Missing space between texture id and image name.\n");
	else if (XPM_ERROR)
		my_write("Path to XPM image invalid.\n");
	if (line)
	{
		my_write("|\033[0;31m");
		my_write(line);
		my_write("\033[0m|\n");
	}
}
