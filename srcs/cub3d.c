/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/02 10:22:03 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"
#include "../includes/parser.h"

void	mlx_variables_init(t_mlx *mlx, t_cub *cub)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		wr_and_ex("Error\nMlx init did not work properly.\n", 1);
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "cub3d");
	if (!mlx->win)
		wr_and_ex("Error\nFailed to create window.\n", 1);
	cub->mlx = *mlx;
}

void	init_player(char c, t_player *player, int i, int j)
{
	if (c == 'S')
		player->view = 180;
	else if (c == 'N')
		player->view = 0;
	else if (c == 'E')
		player->view = 90;
	else if (c == 'W')
		player->view = 270;
	player->x = i;
	player->y = j;
}

void	initial_player_pos(t_cub *cub, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cub->map[++j])
	{
		while (cub->map[j][++i])
		{
			if (is_player_char(cub->map[j][i]))
			{
				init_player(cub->map[j][i], player, i, j);
				cub->map[j][i] = 0;
				cub->player = player;
				return ;
			}
		}
		i = -1;
	}
}

void	cub3d(char *argument)
{
	t_cub		cub;
	t_mlx		mlx;
	t_player	player;

	mlx_variables_init(&mlx, &cub);
	parser(argument, &cub);
	initial_player_pos(&cub, &player);
	display(&cub);
	mlx_key_hook(cub.mlx.win, key_hook, (void *)&cub);
	mlx_loop(cub.mlx.mlx);
}
