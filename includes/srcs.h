/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:38:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 13:08:37 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "global.h"
# include <stdio.h>

void	cub3d(char *argument);

void	parser(char *argument, t_cub *cub, t_player *player);
void	display(t_cub *cub);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
int		loop_hook(t_cub *cub);

#endif
