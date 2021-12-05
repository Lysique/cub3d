/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:37:41 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 11:26:49 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_and_return_error(void *ptr)
{
	if (ptr)
		free(ptr);
	return (-1);
}

char	*skip_spaces(char *line, void *ptr, t_game *game)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '	')
		i++;
	while (line[i + j])
		j++;
	new = malloc(j + 1);
	if (!new)
		error_manager(game, game->error + 100);
	j = 0;
	while (line[i])
		new[j++] = line[i++];
	new[j] = '\0';
	free(ptr);
	return (new);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
