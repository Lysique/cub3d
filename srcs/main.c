/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:32:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 13:45:05 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		my_write("Error\nPlease enter a file as argument.\n");
		return (1);
	}
	else if (argc > 2)
	{
		my_write("Error\nTo many arguments.\nPlease enter only one file as argument.\n");
		return (1);
	}
	cub3d(argv[1]);
	return (0);
}
