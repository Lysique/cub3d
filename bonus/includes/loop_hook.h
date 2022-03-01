/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 14:29:13 by tamighi          ###   ########.fr       */
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
int		en_shot_manager(t_en *en, t_cub *cub, float angle);
void	enemy_die(t_en *en, t_cub *cub);
void	enemy_move(t_en *en, t_cub *cub);

void	manage_boss(t_en *en, t_cub *cub);
int		boss_found_door(t_en *en, t_cub *cub);
void	throw_missile_manager(t_en *en, t_cub *cub);
void	throw_missile(t_en *en, t_cub *cub);
void	missile_manager(t_en *en, t_cub *cub);

void	set_enemy_action(t_en *en, t_cub *cub);
void	en_action_reset(t_en *en, int action);
void	set_enemy_angle(t_en *en, t_cub *cub);
void	set_en_img_angle(t_en *en, t_cub *cub);

int		bad_trajectory_checker(float angle, float dist,
			float x, float y);
int		lh_wall_hit_checker(float angle, float dist, float x,
			float y);
void	reinitialize_map_dist(t_cub *cub);

int		check_p_dir(t_cub *cub, float y, float x);
int		miss_arrived_at_destination(t_miss miss);
int		is_en_on_door(t_door door, t_en *en);
void	player_life_manager(t_cub *cub, int life);
int		missile_hit_player(t_cub *cub, t_en *en);

// DISPLAY FCTS

void	side_init(t_ray *r, float p_x, float p_y);
int		is_raycast_end(t_cub *cub, int y, int x);

void	parser(char *argument, t_cub *cub);

#endif
