/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:48:28 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/25 08:33:49 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdarg.h>

typedef struct s_key {
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}				t_key;

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

typedef struct s_hit {
	float	x;
	float	y;
	float	cote;
}				t_hit;

typedef struct s_player {
	float	x;
	float	y;
	float	angle;
}				t_player;

typedef struct s_line {
	float	pente;
}				t_line;

typedef struct s_cub {
	char		**map;
	t_img		display;
	t_player	player;
	t_mlx		mlx;
	t_img		textures[6];
	t_key		key;
	t_line		line;
	t_hit		hit;
}				t_cub;

# define WIN_H 1080
# define WIN_W 1920
# define MINI 300
# define PI 3.14159265359
# define MIDPI 1.570796326795

# define F 0
# define C 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5

void	my_write(char *str);
void	wr_and_ex(char *str, int ex);
void	free_and_exit(t_cub *cub, char *msg, int error);

#endif
