/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:08:25 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 13:20:48 by tamighi          ###   ########.fr       */
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

void	game_struct_init(char **argv, t_game *game)
{
	file_reading(argv, game);
	game_variables_init(game);
	if (add_texture_paths(game) == -1)
		error_manager(game, game->error);
	if (add_map(game) == -1)
		error_manager(game, game->error);
}
