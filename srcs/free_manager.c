/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:22:31 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 11:30:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_my_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	free(arr);
	while (arr[i])
		free(arr[i++]);
}

void	close_fd_and_free_textures(t_game *game)
{
	close(game->fd);
	if (game->north_texture)
		free(game->north_texture);
	if (game->south_texture)
		free(game->south_texture);
	if (game->east_texture)
		free(game->east_texture);
	if (game->west_texture)
		free(game->west_texture);
	if (game->ceiling_texture)
		free(game->ceiling_texture);
	if (game->floor_texture)
		free(game->floor_texture);
}

int	free_manager(t_game *game, int free_nb)
{
	if (free_nb <= 3)
		return (0);
	else if (free_nb == 4)
		close_fd_and_free_textures(game);
	else if (free_nb == 5)
		free_my_arr(game->map);
	return (free_manager(game, free_nb - 1));
}
