/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:41:04 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 13:18:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub3d(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_manager(&game, 1);
	game_struct_init(argv, &game);
//	print_my_struct(&game);
	error_manager(&game, 0);
	return (0);
}
