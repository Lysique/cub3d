/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 15:05:53 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "global.h"

void	display(t_cub *cub);

void	player_manager(t_cub *cub);
void	door_manager(t_cub *cub);
void	gun_manager(t_cub *cub);

int		check_direction(t_cub *cub, int y, int x);
int		get_door_index(t_door *d, int y, int x);

#endif
