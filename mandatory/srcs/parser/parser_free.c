/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:23:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 14:58:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	destroy_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cub->textures[i].img)
			mlx_destroy_image(cub->mlx.mlx, cub->textures[i].img);
		i++;
	}
}

void	free_my_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	parser_free(t_parser *p)
{
	if (p->fd != -1)
		close(p->fd);
	free_my_arr(p->file);
	free_my_arr(p->cub->map);
	destroy_textures(p->cub);
	mlx_destroy_window(p->cub->mlx.mlx, p->cub->mlx.win);
}
