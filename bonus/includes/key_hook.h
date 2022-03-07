/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:53:12 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 13:46:47 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

# include "global.h"

void	parser(char *argument, t_cub *cub);
void	key_init(t_cub *cub);
void	mouse_click_main_menu(t_cub *cub, int x, int y);
void	mouse_click_lose_menu(t_cub *cub, int x, int y);
void	mouse_click_win_menu(t_cub *cub, int x, int y);
void	mouse_click_break_menu(t_cub *cub, int x, int y);

#endif
