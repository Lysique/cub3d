/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/12 08:51:21 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

void	parser_error(t_cub *cub, int error);
int		parse_textures(t_cub *cub, int fd);
int		add_texture_to_struct(char *line, t_cub *cub);
int		parse_map(t_cub *cub, int fd);
int		map_checker(t_cub *cub);
void	free_my_arr(char **arr);
void	destroy_imgs(t_cub *cub);

int		ft_strcmp(char *texture, char *line);
char	*get_next_line(int fd);
int		is_player_char(char c, int check);
int		is_char_allowed_on_map(char c, int i, int j);

#endif
