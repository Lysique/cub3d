/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:23:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 09:36:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	open_file_error(void)
{
	if (errno == EACCES)
		my_write("Requested access to the file is not allowed.\n");
	else if (errno == ENOENT)
		my_write("The file does not exist.\n");
	else if (errno == EISDIR)
		my_write("Argument is a directory. A file is needed.\n");
	else
		my_write("Unknown error while opening the file.\n");
}

void	parser_error(int error, void *ptr)
{
	t_parser	*p;

	p = set_parserptr(0);
	my_write("Error\n");
	if (error == OPEN_ERROR)
		open_file_error();
	else if (error == MALLOC_ERROR)
		my_write("Memory didn't allocate properly.\n");
	else if (error == EMPTY_FILE)
		my_write("File is empty.\n");
	else if (error == FILE_NOT_ENDED)
		my_write("Unnecessary characters in the end of the file.\n");
	else if (error / NB_ERRORS == TEXTURE_ERROR)
		texture_error(error, (char *)ptr);
	else if (error / NB_ERRORS == MAP_ERROR)
		map_error(error, p->cub->map, (t_coord *)ptr);
	my_write("\nExit\n");
	parser_free(p);
	error_manager(HANDLED);
}
