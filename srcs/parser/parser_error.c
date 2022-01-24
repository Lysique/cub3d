/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:54:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/24 08:36:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	open_file_error(void)
{
	if (errno == EACCES)
		my_write("Requested access to the file is not allowed.\n");
	else if (errno == ENOENT)
		my_write("The file does not exist.\n");
	else
		my_write("Unknown error while opening the file.\n");
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
	else if (error == EMPTY_FILE)
		my_write("File is empty.\n");
	else if (error == FILE_NOT_ENDED)
		my_write("No characters are allowed after map assignement.\n");
	else if (error / NB_ERRORS == TEXTURE_ERROR)
		texture_error(error, (char *)ptr);
	else if (error / NB_ERRORS == MAP_ERROR)
		map_error(error, p->cub->map, (t_coord *)ptr);
	parser_free(p);
	my_write("\n");
	wr_and_ex(0, 1);
}
