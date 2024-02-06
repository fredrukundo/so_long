/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:14:18 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 17:21:02 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

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
