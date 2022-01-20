/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:14:02 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 12:10:30 by tamighi          ###   ########.fr       */
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
		return (0);
	i = -1;
	while ((++i || arr) && arr[i])
		new[i] = arr[i];
	new[i++] = line;
	new[i] = 0;
	if (arr)
		free(arr);
	return (new);
}

char	**fd_to_arr(t_cub *cub, int fd)
{
	char	**arr;
	char	*line;

	arr = 0;
	line = cub3d_get_next_line(cub, arr, fd);
	while (line)
	{
		arr = add_line_to_arr(arr, line);
		if (!arr)
		{
			close(fd);
			parser_error(cub, arr, 1);
		}
		line = cub3d_get_next_line(cub, arr, fd);
	}
	close(fd);
	return (arr);
}
