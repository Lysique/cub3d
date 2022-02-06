/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:48:28 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/06 15:22:09 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include <stdarg.h>
# include "define.h"
# include <sys/time.h>

typedef unsigned int	t_time;

typedef struct s_key {
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}				t_key;

typedef struct s_mouse {
	int	x;
}				t_mouse;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		sizel;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct s_player {
	float	x;
	float	y;
	float	angle;
}				t_player;

typedef struct s_cub {
	char		**map;
	t_player	player;
	t_key		key;
	t_mouse		mouse;
	t_time		time;
	t_img		display;
	t_img		sprites[NB_SPR][MAX_SPR + 1];
	t_img		textures[7];
	t_mlx		mlx;
}				t_cub;

void		my_write(char *str);
void		wr_and_ex(char *str, int ex);

t_cub		*set_cubptr(t_cub *ptr);
void		error_manager(int error);

int			ft_strlen(const char *s);
t_time		get_time(void);

void		free_my_arr(char **arr);
void		free_and_exit(t_cub *cub, int error);

#endif
