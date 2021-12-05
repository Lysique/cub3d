/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:03:13 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 10:31:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	format_checker(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (-1);
	if (!ft_strcmp(&file[i - 4], ".cub"))
		return (-1);
	return (0);
}

void	file_reading(char **argv, t_game *game)
{
	if (format_checker(argv[1]) == -1)
		error_manager(game, 2);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		error_manager(game, 3);
	game_struct_init(game->fd, game);
}
