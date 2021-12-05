/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:41:04 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 10:59:11 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub3d(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_manager(&game, 1);
	file_reading(argv, &game);
	error_manager(&game, 0);
	return (0);
}
