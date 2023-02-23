/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:20:05 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/09 09:29:46 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	error_writer(int error)
{
	if (error == HANDLED)
		return ;
	my_write("Error\n");
	if (error == MALLOC_ERROR)
		my_write("Couldn't allocate memory.\n");
	else if (error == MLX_ERROR)
		my_write("Mlx didn't initiate properly.\n");
	else if (error == IMG_ERROR)
		my_write("Couldn't create the game images.\n");
	my_write("\nExit\n");
}

void	error_manager(int error)
{
	t_cub	*cub;

	cub = set_cubptr(0);
	if (error == EXOK)
	{
		my_write("Exit\n");
		free_and_exit(cub, 0);
	}
	error_writer(error);
	free_and_exit(cub, 1);
}
