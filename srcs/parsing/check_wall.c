/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:03:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 12:39:09 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
