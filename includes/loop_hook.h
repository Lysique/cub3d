/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:06:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 14:34:21 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "global.h"

# define DISTANCE (UNIT / 10)

void	display(t_cub *cub);
void	move_manager(t_cub *cub);

#endif
