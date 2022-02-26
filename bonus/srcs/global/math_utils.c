/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:04:03 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 12:12:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

float	get_angle(float d_y, float d_x)
{
	float	angle;

	angle = atan(d_y / d_x);
	if (d_x >= 0)
		angle = PI - angle;
	if (d_x < 0 && d_y < 0)
		angle = 2 * PI - angle;
	if (d_x < 0 && d_y > 0)
		angle = 0 - angle;
	return (angle);
}
