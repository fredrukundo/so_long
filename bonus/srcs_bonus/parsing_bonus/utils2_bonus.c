/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:37:41 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 10:25:18 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

bool	get_player_pozition(char **map, int rows, int *p_row, int *p_col)
{
	*p_row = 0;
	while (*p_row < rows && strchr(map[*p_row], PLAYER) == NULL)
		(*p_row)++;
	if (*p_row == rows)
		return (false);
	*p_col = 0;
	while (map[*p_row][*p_col] != PLAYER)
		(*p_col)++;
	return (true);
}

void	copy_map(char **dest, char **src, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[rows] = NULL;
}

void	free_maps(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*ft_strchrs(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
