/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:08:10 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 09:58:19 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../ft_printf/ft_printf.h"

void	error_invalid_path(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: invalid path on the map!.%s\n", RED,
		file_name, END);
	free_map(data);
}

static void	flood_fill(char **temp_map, int y, int x);

bool	check_valid_path(t_data *data)
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
		if (strchr(temp_map[i], EXIT) != NULL)
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
