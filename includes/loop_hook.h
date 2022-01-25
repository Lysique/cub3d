/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/25 10:13:17 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "global.h"

# define DISTANCE 0.25
# define SPEED 0.1
# define ROTATE 0.1

void	display(t_cub *cub);
void	key_manager(t_cub *cub);
void	key_init(t_cub *cub);
void	key_w(t_cub *cub);
void	key_s(t_cub *cub);
void	key_a(t_cub *cub);
void	key_d(t_cub *cub);
void	hitbox(float x, float y, t_cub *cub);

#endif
