/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/29 12:44:45 by tamighi          ###   ########.fr       */
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
	mlx_hook(cub.mlx.win, 2, 1L<<0, key_press, (void *)&cub);
	mlx_hook(cub.mlx.win, 3, 1L<<1, key_release, (void *)&cub);
	mlx_hook(cub.mlx.win, 17, 0, mouse_press, (void *)&cub);
	mlx_loop_hook(cub.mlx.mlx, loop_hook, &cub);
	mlx_loop(cub.mlx.mlx);
}
