/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 10:44:03 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "global.h"

void	display(t_cub *cub);

void	player_manager(t_cub *cub);
void	door_manager(t_cub *cub);
void	map_dist_manager(t_cub *cub);
void	gun_manager(t_cub *cub);
void	shoot_manager(t_cub *cub, t_gun *gun);
void	hit_manager(t_cub *cub, t_gun *gun);
void	order_enemies(t_cub *cub);
void	emotion_manager(t_cub *cub);
void	enemy_manager(t_cub *cub);

void	enemy_still(t_en *en, t_cub *cub);
void	enemy_attack(t_en *en, t_cub *cub);
void	enemy_die(t_en *en, t_cub *cub);
void	enemy_move(t_en *en, t_cub *cub);

void	set_enemy_action(t_en *en, t_cub *cub);
void	set_enemy_angle(t_en *en, t_cub *cub);
void	set_en_img_angle(t_en *en, t_cub *cub);

int		check_p_dir(t_cub *cub, float y, float x);

// DISPLAY FCTS

void	side_init(t_ray *r, float p_x, float p_y);
int		is_raycast_end(t_cub *cub, int y, int x);

#endif
