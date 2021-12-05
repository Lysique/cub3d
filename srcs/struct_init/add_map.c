/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:14:48 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 12:06:48 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	add_map(int fd, t_game *game)
{
	char	*line;
	char	**arr;
	int		j;

	game->error = 5;
	j = 0;
	arr = malloc(sizeof(char *) * 1);
	if (!arr)
		error_manager(game, game->error + 100);
	line = get_next_line(fd, game);
	while (!is_part_of_map(line))
		line = get_next_line(fd, game);
}
