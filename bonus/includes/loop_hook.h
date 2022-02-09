/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/08 16:46:39 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "global.h"

		/* COLLISION WITH WALLS */

# define HITBOX 0.3

		/* DISTANCE OF DOOR OPENING OR CLOSING 
		   
		   CAREFULL TO NOT PUT TOO FAR OR TOO CLOSE */

# define DOOR_REACH 1.7

void	display(t_cub *cub);
void	player_manager(t_cub *cub);
void	door_manager(t_cub *cub);

int		check_direction(t_cub *cub, int y, int x);
int		get_door_index(t_door *d, int y, int x);

#endif
