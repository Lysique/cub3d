/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:40:42 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 14:37:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	are_all_textures_set(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!cub->textures[i].img)
			return (0);
		i++;
	}
	return (1);
}

void	parse_textures(t_cub *cub, char **file)
{
	int	i;

	i = 0;
	while (!are_all_textures_set(cub))
	{
		if (!file[i])
			parse_error(cub, file, 7);
		if (add_texture_to_struct(cub, file[i++]) == -1)
			parser_error(cub, file, 2);
	}
}
