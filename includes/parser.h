/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 16:48:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

# define NB_ERRORS 10

# define MALLOC_ERROR 1
# define OPEN_ERROR 2
# define EMPTY_FILE 3
# define FILE_NOT_ENDED 4

# define TEXTURE_ERROR 1
# define MISSING_TEXTURE TEXTURE_ERROR * NB_ERRORS + 1
# define DUPL_TEXTURE TEXTURE_ERROR * NB_ERRORS + 2
# define FORMAT_TEXTURE TEXTURE_ERROR * NB_ERRORS + 3
# define MISSING_FILE_NAME TEXTURE_ERROR * NB_ERRORS + 4
# define MISSING_SPACE TEXTURE_ERROR * NB_ERRORS + 5
# define XPM_ERROR TEXTURE_ERROR * NB_ERRORS + 6

# define MAP_ERROR 2
# define MISSING_NL TEXTURE_ERROR * NB_ERRORS + 1
# define MISSING_MAP MAP_ERROR * NB_ERRORS + 2
# define UNKNOWN_CHAR MAP_ERROR * NB_ERRORS + 3
# define OPEN_MAP MAP_ERROR * NB_ERRORS + 4
# define MULT_PLAYER MAP_ERROR * NB_ERRORS + 5
# define NO_PLAYER MAP_ERROR * NB_ERRORS + 6

typedef struct	s_parser {
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
void		player_init(t_cub *cub);
char		**parse_textures(t_parser *p, char **file);
char		**parse_map(t_parser *p, char **file);



int			is_texture_line(char *line);
char		*cub3d_get_next_line(int fd);
int			cub3d_isspace(char c);
char		*cub3d_cpy(char *line, void *ptr);

int			is_line_empty(char *line);
int			is_player_char(char c);
int			is_known_char(char c);

void		parser_error(int error, void *ptr);
void		parser_free(t_parser *p);
void		free_my_arr(char **arr);

#endif
