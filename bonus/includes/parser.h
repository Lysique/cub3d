/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/04 12:54:41 by tuytters         ###   ########.fr       */
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

# define NB_ERRORS 10

# define MALLOC_ERROR 1
# define OPEN_ERROR 2
# define EMPTY_FILE 3
# define FILE_NOT_ENDED 4

/*		ERROR = {TYPE_ERROR}_ERROR * NB_ERRORS + X
 
		X = NTH ERROR OF TYPE {TYPE_ERROR}. SHOULD NOT EXCEED NB_ERRORS.
 		TYPE ERRORS : [TEXTURE_ERROR; MAP_ERROR]*/

# define TEXTURE_ERROR 1
# define MISSING_TEXTURE 11
# define DUPL_TEXTURE 12
# define FORMAT_TEXTURE 13
# define MISSING_FILE_NAME 14
# define MISSING_SPACE 15
# define XPM_ERROR 16
# define MUSIC_NOT_FOUND 17

# define MAP_ERROR 2
# define MISSING_NL 21
# define MISSING_MAP 22
# define UNKNOWN_CHAR 23
# define OPEN_MAP 24
# define MULT_PLAYER 25
# define NO_PLAYER 26

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

t_parser	*set_parser_ptr(t_parser *ptr);
void		fd_to_arr(t_parser *p);
char		**parse_textures(t_parser *p, char **file);
char		**parse_music(t_parser *p, char **file);
void		add_texture(char *texture, t_cub *cub, int index);
char		**parse_map(t_parser *p, char **file);
void		map_checker(char **map);
void		player_init(t_cub *cub);

int			is_texture_line(char *line);
char		*go_to_path(char *line, int i);
char		*cub3d_get_next_line(int fd);
int			cub3d_isspace(char c);
char		*cub3d_cpy(char *line, void *ptr);

int			is_line_empty(char *line);
int			is_player_char(char c);
int			is_known_char(char c);

void		parser_error(int error, void *ptr);
void		map_error(int error, char **map, t_coord *c);
void		texture_error(int error, char *line);

void		parser_free(t_parser *p);
void		free_my_arr(char **arr);

void		put_my_pixel(t_img img, int y, int x, int color);

#endif
