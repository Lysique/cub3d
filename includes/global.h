/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:48:28 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 08:46:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		w;
	int		h;
}				t_img;

typedef struct s_player {
	int		x;
	int		y;
	int		view;
}				t_player;

typedef struct s_cub {
	char		**map;
	t_player	player;
	t_mlx		mlx;
	t_img		textures[6];
}				t_cub;

# define WIN_H 1080
# define WIN_W 1920
# define MINI 300 
# define UNIT MINI 

void	my_write(char *str);
void	wr_and_ex(char *str, int ex);

#endif
