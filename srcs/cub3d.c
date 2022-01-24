/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 15:35:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"
#include "../includes/parser.h"
#include "../includes/loop_hook.h"

void	cub3d(char *argument)
{
	t_cub		cub;

	structure_init(&cub);
	parser(argument, &cub);
	wr_and_ex("OK\n", 0);
	display(&cub);
	mlx_hook(cub.mlx.win, 2, 0, key_press, &cub);
	mlx_hook(cub.mlx.win, 3, 0, key_release, &cub);
	mlx_hook(cub.mlx.win, 17, 0, mouse_press, &cub);
	mlx_loop_hook(cub.mlx.mlx, loop_hook, &cub);
	mlx_loop(cub.mlx.mlx);
}
