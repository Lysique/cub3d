/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:38:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/02 09:47:20 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "global.h"
# include <stdio.h>

void	cub3d(char *argument);

void	parser(char *argument, t_cub *cub);
void	display(t_cub *cub);
int		key_hook(int key, void *param);

int		is_player_char(char c);

#endif
