/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:27:58 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 10:56:49 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	sprs_init(t_cub *cub)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (cub->en[++k].action != -1)
		i++;
	cub->sprs = malloc(sizeof(t_spr) * (i + 1));
	if (!cub->sprs)
		parser_error(MALLOC_ERROR, 0);
	cub->sprs[i].to_draw = -1;
}
