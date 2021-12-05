/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_my_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:04:27 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 13:10:46 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_my_struct(t_game *game)
{
	printf("North : %sSouth : %sWest : %sEast : %sceiling : %sfloor : %s\n", game->north_texture, game->south_texture, game->west_texture, game->east_texture, game->ceiling_texture, game->floor_texture);
	int	i = 0;
	printf("Map :\n");
	while (game->map[i])
		printf("%s", game->map[i++]);
	printf("\n");
}
