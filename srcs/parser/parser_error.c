/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:54:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 14:39:52 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	texture_error_write(char *line, int error)
{
	if (error == 2)
		my_write("Please enter an xpm image file name : ");
	else if (error == 3)
		my_write("Please add a space between texture id and image name : ");
	else if (error == 4)
		my_write("Couldn't assign xpm image file : ");
	else if (error == 5)
	{
		my_write("All textures should be assigned before map initialisation.\n");
		return ;
	}
	else if (error == 6)
		my_write("Bad line format : ");
	else if (error == 7)
	{
		my_write("Missing textures ...\nand map ...\n");
		return ;
	}
	my_write("\033[0;31m");
	my_write(line);
	my_write("\033[0m\n");
}

int	texture_error(int error, char *line)
{
	my_write("Error\nTextures initialisation didn't work properly.\n");
	if (error == 1)
		my_write("Textures should only be assigned once in the file.\n");
	else if (error >= 2)
		texture_error_write(line, error);
	return (-1);
}

void	open_file_error(void)
{
	my_write("Error\n");
	if (errno == EACCES)
		my_write("Requested access to the file is not allowed.\n");
	else if (errno == ENOENT)
		my_write("The file does not exist.\n");
	else
		my_write("Unknown error while opening the file.\n");
}

void	parser_error(t_cub *cub, char **file, int error)
{
	if (error == 0)
		open_file_error();
	else if (error == 1)
		my_write("Error\nMemory didn't allocate properly.\n");
	parser_free(cub, file);
	wr_and_ex(0, 1);
}
