/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:32:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:36:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		my_write("Error\nTo many arguments.\n");
		my_write("Please enter only one file as argument.\n");
		return (1);
	}
	if (argc == 1)
		cub3d(0);
	else
		cub3d(argv[1]);
	return (0);
}
