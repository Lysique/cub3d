/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 14:54:08 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	display(t_cub *cub)
{
	view_casting(cub);
	display_menu(cub);
	display_map(cub);
	display_char(cub);
	display_gun(cub);
}
