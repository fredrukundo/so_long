/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collectibles_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:11:46 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 10:27:43 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	get_collectables(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				data->map.collectables++;
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **temp_map, int y, int x);

bool	check_path_collectible(t_data *data)
{
	char	**map;
	int		p_row;
	int		p_col;
	char	**temp_map;
	int		i;

	map = data->map.map;
	if (!get_player_pozition(map, data->map.row, &p_row, &p_col))
		return (false);
	temp_map = malloc(sizeof(char *) * (data->map.row + 1));
	copy_map(temp_map, map, data->map.row);
	flood_fill(temp_map, p_row, p_col);
	i = 0;
	while (i < data->map.row)
	{
		if (ft_strchrs(temp_map[i], COL) != NULL)
		{
			free_maps(temp_map, data->map.row);
			return (true);
		}
		i++;
	}
	free_maps(temp_map, data->map.row);
	return (false);
}

static void	flood_fill(char **temp_map, int y, int x)
{
	if (temp_map[y][x] == '1' || temp_map[y][x] == 'v')
		return ;
	temp_map[y][x] = 'v';
	flood_fill(temp_map, y, x - 1);
	flood_fill(temp_map, y + 1, x);
	flood_fill(temp_map, y, x + 1);
	flood_fill(temp_map, y - 1, x);
}
