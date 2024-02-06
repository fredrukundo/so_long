/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:08:58 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 17:20:49 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map.col = ft_strlen(data->map.map[0]) - 1;
	while (i < data->map.row)
	{
		j = 0;
		while (data->map.map[i][j] != '\n' && data->map.map[i][j]
			&& j < data->map.col)
		{
			if (i == 0 || i == data->map.row - 1)
				if (data->map.map[i][j] != '1')
					return (1);
			if (j == 0 || j == data->map.col - 1)
				if (data->map.map[i][j] != '1')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}
