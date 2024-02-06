/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:07:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 12:39:40 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_player_position(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map.map[row])
	{
		col = 0;
		while (data->map.map[row][col])
		{
			if (data->map.map[row][col] == 'P')
			{
				data->map.player.x = row;
				data->map.player.y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
