/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:30 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/18 07:55:31 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	count_number_of_enemies(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->map.number_of_enemies = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == ENEMY)
				data->map.number_of_enemies++;
			y++;
		}
		x++;
	}
}

void	get_enemies_positions(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	data->map.enemy = malloc(sizeof(t_vec) * data->map.number_of_enemies);
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y])
		{
			if (data->map.map[x][y] == ENEMY)
			{
				data->map.enemy[i].x = x;
				data->map.enemy[i].y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

static void	enemy_moves_action(t_data *data, int i, int x, int y)
{
	if (data->map.map[x - 1][y] == '0')
	{
		ft_swap(&data->map.map[data->map.enemy[i].x - 1][data->map.enemy[i].y],
			&data->map.map[data->map.enemy[i].x][data->map.enemy[i].y]);
		data->map.enemy[i].x--;
	}
	else if (data->map.map[x + 1][y] == '0')
	{
		ft_swap(&data->map.map[data->map.enemy[i].x + 1][data->map.enemy[i].y],
			&data->map.map[data->map.enemy[i].x][data->map.enemy[i].y]);
		data->map.enemy[i].x++;
	}
	else if (data->map.map[x][y - 1] == '0')
	{
		ft_swap(&data->map.map[data->map.enemy[i].x][data->map.enemy[i].y - 1],
			&data->map.map[data->map.enemy[i].x][data->map.enemy[i].y]);
		data->map.enemy[i].y--;
	}
	else if (data->map.map[x][y + 1] == '0')
	{
		ft_swap(&data->map.map[data->map.enemy[i].x][data->map.enemy[i].y + 1],
			&data->map.map[data->map.enemy[i].x][data->map.enemy[i].y]);
		data->map.enemy[i].y++;
	}
}

void	enemy_moves(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->map.number_of_enemies)
	{
		x = data->map.enemy[i].x;
		y = data->map.enemy[i].y;
		enemy_moves_action(data, i, x, y);
		i++;
	}
}
