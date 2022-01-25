/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:21:58 by tuytters          #+#    #+#             */
/*   Updated: 2022/01/25 10:05:33 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

// int	colision(t_cub *cub, float px,float py, float ry, float rx)
// {
// 	int	x;
// 	int	y;

// 	y = (int) py - 2;
// 	hitbox(px, py, cub);
// 	while (++y < py + 1 && y >= 0)
// 	{
// 		x = (int) px - 2;
// 		printf("%d %d %c\n", y, x, cub->map[y][x]);
// 		while (++x < px + 1)
// 		{
// 			if (cub->map[y][x] == '1')
// 			{
// 				if (cub->hit.x + cub->hit.cote < x || cub->hit.x >= x + 1
// 					|| cub->hit.y + cub->hit.cote < y || cub->hit.y >= y + 1)
// 					return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }
// // int	colision(t_cub *cub, float px,float py/*, float ry, float rx*/)
// // {
// // 	int	x;
// // 	int	y;

// // 	y = (int) py;
// // 	x = (int) px;
// // 	hitbox(px, py, cub);
// // 	// while (++y < py + 1 && y >= 0)
// // 	// {
// // 	// 	x = (int) px - 2;
// // 	// printf("%d %d %c\n", y, x, cub->map[y][x]);
// // 	// 	while (++x < px + 1)
// // 	// 	{
// // 			if (cub->map[y][x] == '1')
// // 			{
// // 				if (cub->hit.x + cub->hit.cote < x && cub->hit.x >= x + 1
// // 					&& cub->hit.y + cub->hit.cote < y && cub->hit.y >= y + 1)
// // 				{
// // 					printf("0\n");
// // 					return (0);
// // 				}
// // 				else
// // 				{
// // 					printf("1\n");
// // 					return (1);
// // 				}
// // 			}
// // 			else
// // 				return (0);
// // 	// 	}
// // 	// }
// // 	return (1);
// // }

// void	key_w(t_cub *cub)
// {
// 	// printf("%f\n", sinf(cub->player.angle) * SPEED);
// 	const float tmpy = cub->player.y + sinf(cub->player.angle) * SPEED;
// 	// if (colision(cub, cub->player.x, tmpy/*, cub->player.y + sinf(cub->player.angle) * SPEED, 0*/) == 0)
// 	// 		cub->player.y = tmpy;
// 	// const float tmpx = cub->player.x + cosf(cub->player.angle) * SPEED;
// 	// if (colision(cub, tmpx, cub->player.y/*, 0, cub->player.x + cosf(cub->player.angle) * SPEED*/) == 0)
// 	// 		cub->player.x = tmpx;
// 	// if (colision(cub, playerx, playertmpy) == 0]
// 	// 		cub->player.y += sin(cub->player.angle) * SPEED;
// 	// 		playery=p
// 	// if (colision(cub) == 0 && cub->map[(int)(cub->player.y)]
// 	// 	[(int)(cub->player.x + cos(cub->player.angle) * DISTANCE)] != '1')
// 	// 		cub->player.x += cos(cub->player.angle) * SPEED;
// }

// void	key_s(t_cub *cub)
// {
// 	const float tmpy = cub->player.y - sin(cub->player.angle) * SPEED;
// 	if (colision(cub, cub->player.x, tmpy) == 0)
// 			cub->player.y = tmpy;
// 	const float tmpx = cub->player.x - cos(cub->player.angle) * SPEED;
// 	if (colision(cub, tmpx, cub->player.y) == 0)
// 			cub->player.x = tmpx;
// // 	if (/*colision(cub) == 0 && */cub->map[(int)(cub->player.y 
// // 		- sin(cub->player.angle) * DISTANCE)]
// // 		[(int)cub->player.x] != '1')
// // 			cub->player.y -= sin(cub->player.angle) * SPEED;
// // 	if (/*colision(cub) == 0 && */cub->map[(int)cub->player.y]
// // 		[(int)(cub->player.x - cos(cub->player.angle) * DISTANCE)] != '1')
// // 			cub->player.x -= cos(cub->player.angle) * SPEED;
// }

// void	key_a(t_cub *cub)
// {
// 	// const float tmpy = cub->player.y - sin(cub->player.angle + MIDPI) * SPEED;
// 	// if (colision(cub, cub->player.x, tmpy) == 0)
// 	// 		cub->player.y = tmpy;
// 	// const float tmpx = cub->player.x - cos(cub->player.angle + MIDPI) * SPEED;
// 	// if (colision(cub, tmpx, cub->player.y) == 0)
// 	// 		cub->player.x = tmpx;
// 	// if (/*colision(cub) == 0 && */cub->map[(int)(cub->player.y 
// 	// 	- sin(cub->player.angle + MIDPI) * DISTANCE)]
// 	// 	[(int)cub->player.x] != '1')
// 	// 		cub->player.y -= sin(cub->player.angle + MIDPI) * SPEED;
// 	// if (/*colision(cub) == 0 && */cub->map[(int)cub->player.y]
// 	// 	[(int)(cub->player.x - cos(cub->player.angle + MIDPI) * DISTANCE)] != '1')
// 	// 		cub->player.x -= cos(cub->player.angle + MIDPI) * SPEED;
// }

// void	key_d(t_cub *cub)
// {
// 	// const float tmpy = cub->player.y - sin(cub->player.angle - MIDPI) * SPEED;
// 	// if (colision(cub, cub->player.x, tmpy) == 0)
// 	// 		cub->player.y = tmpy;
// 	// const float tmpx = cub->player.x - cos(cub->player.angle - MIDPI) * SPEED;
// 	// if (colision(cub, tmpx, cub->player.y) == 0)
// 			// cub->player.x = tmpx;
// 	// if (/*colision(cub) == 0 && */cub->map[(int)(cub->player.y 
// 	// 	- sin(cub->player.angle - MIDPI) * DISTANCE)]
// 	// 	[(int)cub->player.x] != '1')
// 	// 		cub->player.y -= sin(cub->player.angle - MIDPI) * SPEED;
// 	// if (/*colision(cub) == 0 && */cub->map[(int)cub->player.y]
// 	// 	[(int)(cub->player.x - cos(cub->player.angle - MIDPI) * DISTANCE)] != '1')
// 	// 		cub->player.x -= cos(cub->player.angle - MIDPI) * SPEED;
// }
