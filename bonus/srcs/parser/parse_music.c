/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_music.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:45:29 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/06 15:20:57 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*music_join(char *play, char *file, char *end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(play) + ft_strlen(file) + ft_strlen(end) + 1);
	if (!str)
		error_manager(MALLOC_ERROR);
	while (*play)
		str[i++] = *(play++);
	while (*file)
		str[i++] = *(file++);
	while (*end)
		str[i++] = *(end++);
	str[i] = 0;
	return (str);
}

void	music_play(char *music_file)
{
	char	*str;

	str = music_join("afplay ", music_file, " &>/dev/null &");
	system(str);
	free(str);
}

char	**parse_music(char **file)
{
	char	*music_file;

	if (!*file)
		parser_error(MISSING_MAP, 0);
	if (!is_line_empty(*file))
		parser_error(MISSING_NL, 0);
	while (is_line_empty(*file))
		file++;
	music_file = *file;
	music_file = go_to_path(music_file, 1);
	if (access(music_file, F_OK) < 0)
		parser_error(MUSIC_NOT_FOUND, *file);
	file++;
	music_play(music_file);
	return (file);
}
