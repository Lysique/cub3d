/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:08:25 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 11:27:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	game_variables_init(t_game *game)
{
	game->error = 0;
	game->north_texture = 0;
	game->south_texture = 0;
	game->east_texture = 0;
	game->west_texture = 0;
	game->ceiling_texture = 0;
	game->floor_texture = 0;
}

void	game_struct_init(int fd, t_game *game)
{
	game_variables_init(game);
	if (add_texture_paths(fd, game) == -1)
		error_manager(game, game->error);
	if (add_map(fd, game) == -1)
		error_manager(game, game->error);
}
