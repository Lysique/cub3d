/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_music.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:45:29 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/04 13:39:05 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	music_play(t_cub *cub)
{
	char	*tmp;
	char	*cmd;

	tmp = ft_strjoin("afplay ", cub->music_file);
	cmd = ft_strjoin(tmp, " &>/dev/null &");
	system(cmd);
	free(tmp);
	free(cmd);
}

char	**parse_music(t_parser *p, char **file)
{
	if (!*file)
		parser_error(MISSING_MAP, 0);
	if (!is_line_empty(*file))
		parser_error(MISSING_NL, 0);
	while (is_line_empty(*file))
		file++;
	p->cub->music_file = *file;
	p->cub->music_file = go_to_path(p->cub->music_file, 1);
	if (access(p->cub->music_file, F_OK) < 0)
		parser_error(MUSIC_NOT_FOUND, *file);
	file++;
	music_play(p->cub);
	return (file);
}
