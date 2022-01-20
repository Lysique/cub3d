/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 13:42:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

char	**fd_to_arr(t_cub *cub, int fd);
void	parse_textures(t_cub *cub, char **file);

int		add_texture_to_struct(t_cub *cub, char *line);
int		parse_map(t_cub *cub, int fd);
int		map_checker(t_cub *cub);
void	destroy_imgs(t_cub *cub);

int		cub3d_strcmp(char *texture, char *line);
char	*cub3d_get_next_line(t_cub *cub, char **arr, int fd);
int		cub3d_isspace(char c);
int		is_player_char(char c, int check, int i, int j);
int		is_char_allowed_on_map(char c, int i, int j);

void	parser_free(t_cub *cub, char **file);

void	parser_error(t_cub *cub, char **file, int error);
int		texture_error(int error, char *line);

#endif
