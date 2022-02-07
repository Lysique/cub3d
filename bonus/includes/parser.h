/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/07 13:09:15 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

/*######## PARSER_ERROR DEFINE ########*/

# define NB_ERRORS 100

# define OPEN_ERROR 1
# define MALLOC_ERROR 2
# define EMPTY_FILE 3
# define FILE_NOT_ENDED 4

/*		ERROR = {TYPE_ERROR}_ERROR * NB_ERRORS + X
 
		X = NTH ERROR OF TYPE {TYPE_ERROR}. SHOULD NOT EXCEED NB_ERRORS.
 		TYPE ERRORS : [TEXTURE_ERROR; MAP_ERROR]*/

# define TEXTURE_ERROR 1
# define MISSING_TEXTURE 101
# define DUPL_TEXTURE 102
# define FORMAT_TEXTURE 103
# define MISSING_FILE_NAME 104
# define MISSING_SPACE 105
# define XPM_ERROR 106

# define MAP_ERROR 2
# define MISSING_NL 201
# define MISSING_MAP 202
# define UNKNOWN_CHAR 203
# define OPEN_MAP 204
# define MULT_PLAYER 205
# define NO_PLAYER 206

typedef struct s_parser {
	t_cub	*cub;
	char	**file;
	int		fd;
	void	*ptr;
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

void		parser_error(int error, void *ptr);
void		map_error(int error, char **map, t_coord *c);
void		texture_error(int error, char *line);

void		parser_free(t_parser *p);
void		free_my_arr(char **arr);

void		put_my_pixel(t_img img, int y, int x, int color);

#endif
