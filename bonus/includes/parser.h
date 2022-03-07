/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:37:49 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

typedef struct s_parser {
	t_cub	*cub;
	char	**file;
	int		fd;
}			t_parser;

typedef struct s_coord {
	int	i;
	int	j;
}				t_coord;

t_parser	*set_parserptr(t_parser *ptr);
void		fd_to_arr(t_parser *p);
char		**parse_textures(t_parser *p, char **file);
void		add_texture(char *texture, t_cub *cub, int index);
char		**parse_map(t_parser *p, char **file);
void		map_checker(char **map);
void		player_init(t_cub *cub);
void		doors_init(t_cub *cub);
void		ennemy_init(t_cub *cub);
void		add_enemy(t_cub *cub, char c, int j, int i);
void		medikit_init(t_cub *cub);
void		map_dist_init(t_cub *cub);
void		sprs_init(t_cub *cub);

int			is_texture_line(char *line);
char		*go_to_path(char *line, int i);
char		*cub3d_get_next_line(int fd);
int			cub3d_isspace(char c);
char		*cub3d_cpy(char *line, void *ptr);

int			is_line_empty(char *line);
int			is_door_char(char c);
int			is_player_char(char c);
int			is_known_char(char c);
int			is_close_char(char c);

int			is_ennemy_char(char c);

void		parser_error(int error, void *ptr);
void		map_error(int error, char **map, t_coord *c);
void		map_error_caller(int error, int i, int j);
void		texture_error(int error, char *line);

void		parser_free(t_parser *p);
void		free_my_arr(char **arr);

void		put_my_pixel(t_img img, int y, int x, int color);

#endif
