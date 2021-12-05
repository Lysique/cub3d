/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:13:58 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 11:14:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_manager2(int error)
{
	if (error == 6)
		printf("Hello\n");
	else
		printf("Error not managed\n");
}

void	error_manager(t_game *game, int error)
{
	if (error == 0)
	{
		printf("Everything went well.\n");
		error = 99;
	}
	else if (error == 1)
		printf("Error\nWrong number of argument\n");
	else if (error == 2)
		printf("Error\n.cub format file is required\n");
	else if (error == 3)
		printf("Error\nArgument file invalid\n");
	else if (error == 4)
		printf("Error\nSome path to textures are missing and/or are invalids in the file\n");
	else if (error == 5)
		printf("Error\nThe map in the file is invalid\n");
	else if (error > 100)
	{
		printf("Error while allocating memory\n");
		error -= 100;
	}
	else
		error_manager2(error);
	free_manager(game, error);
	exit(error);
}
