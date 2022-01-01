/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:03:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 11:29:44 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

void	parser_error(t_cub *cub, int error);
void	parse_textures(t_cub *cub, int fd);

int		ft_strcmp(char *texture, char *line);
char	*get_next_line(int fd);

#endif
