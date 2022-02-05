/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:14:02 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 13:49:46 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	**add_line_to_arr(char **arr, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (arr && arr[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		parser_error(MALLOC_ERROR, 0);
	i = -1;
	while ((++i || arr) && arr[i])
		new[i] = arr[i];
	new[i++] = line;
	new[i] = 0;
	if (arr)
		free(arr);
	return (new);
}

void	fd_to_arr(t_parser *p)
{
	char	*line;

	p->file = 0;
	line = cub3d_get_next_line(p->fd);
	while (line)
	{
		p->file = add_line_to_arr(p->file, line);
		line = cub3d_get_next_line(p->fd);
	}
}
