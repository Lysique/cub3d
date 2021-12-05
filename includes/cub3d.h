/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:03:57 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 13:18:46 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game {
	int		error;
	int		status;
	int		fd;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	*ceiling_texture;
	char	*floor_texture;
	char	**map;
}				t_game;

// SRCS FILES

void	print_my_struct(t_game *game);

int		cub3d(int argc, char **argv);
void	error_manager(t_game *game, int error);
int		free_manager(t_game *game, int free_nb);

// STRUCT_INIT FILES

void	game_struct_init(char **argv, t_game *game);
void	file_reading(char **argv, t_game *game);
int		add_texture_paths(t_game *game);
int		add_map(t_game *game);

int		ft_strcmp(char *s1, char *s2);
char	*skip_spaces(char *line, void *ptr, t_game *game);
int		free_and_return_error(void *ptr);
char	*get_next_line(int fd, t_game *game);

#endif
