/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/20 14:33:57 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "global.h"

void	display(t_cub *cub);

void	player_manager(t_cub *cub);
void	door_manager(t_cub *cub);
void	gun_manager(t_cub *cub);
void	shoot_manager(t_cub *cub, t_gun *gun);
void	ennemy_manager(t_cub *cub);
void	hit_manager(t_cub *cub, t_gun *gun);

int		check_direction(t_cub *cub, int y, int x);

// DISPLAY FCTS

void	side_init(t_ray *r, float p_x, float p_y);
int		is_raycast_end(t_cub *cub, int y, int x);

#endif
