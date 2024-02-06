/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:14:50 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/02 05:01:45 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_up(t_data *data)
{
	if (data->map.map[data->map.player.x - 1][data->map.player.y] == '0')
	{
		ft_swap(&data->map.map[data->map.player.x - 1][data->map.player.y],
			&data->map.map[data->map.player.x][data->map.player.y]);
		data->map.player.x--;
		ft_printf("[%sMOVED UP%s] - [%sCOUNT%s] > %d\n", RED, END, YELLOW, END,
			++data->mv_count);
	}
	else if (data->map.map[data->map.player.x - 1][data->map.player.y] == 'C')
	{
		data->map.collectables--;
		data->map.map[data->map.player.x][data->map.player.y] = '0';
		data->map.map[data->map.player.x - 1][data->map.player.y] = 'P';
		data->map.player.x--;
	}
	else if (data->map.map[data->map.player.x - 1][data->map.player.y] == 'E'
		&& !data->map.collectables)
		ft_free(data, "CONGRATS!");
}

void	move_down(t_data *data)
{
	if (data->map.map[data->map.player.x + 1][data->map.player.y] == '0')
	{
		ft_swap(&data->map.map[data->map.player.x + 1][data->map.player.y],
			&data->map.map[data->map.player.x][data->map.player.y]);
		data->map.player.x++;
		ft_printf("[%sMOVED DOWN%s]-[%sCOUNT%s] > %d\n", RED, END, YELLOW, END,
			++data->mv_count);
	}
	else if (data->map.map[data->map.player.x + 1][data->map.player.y] == 'C')
	{
		data->map.collectables--;
		data->map.map[data->map.player.x][data->map.player.y] = '0';
		data->map.map[data->map.player.x + 1][data->map.player.y] = 'P';
		data->map.player.x++;
	}
	else if (data->map.map[data->map.player.x + 1][data->map.player.y] == 'E'
		&& !data->map.collectables)
		ft_free(data, "CONGRATS!");
}

void	move_left(t_data *data)
{
	if (data->map.map[data->map.player.x][data->map.player.y - 1] == '0')
	{
		ft_swap(&data->map.map[data->map.player.x][data->map.player.y - 1],
			&data->map.map[data->map.player.x][data->map.player.y]);
		data->map.player.y--;
		ft_printf("[%sMOVED LEFT%s]-[%sCOUNT%s] > %d\n", RED, END, YELLOW, END,
			++data->mv_count);
	}
	else if (data->map.map[data->map.player.x][data->map.player.y - 1] == 'C')
	{
		data->map.collectables--;
		data->map.map[data->map.player.x][data->map.player.y] = '0';
		data->map.map[data->map.player.x][data->map.player.y - 1] = 'P';
		data->map.player.y--;
	}
	else if (data->map.map[data->map.player.x][data->map.player.y - 1] == 'E'
		&& !data->map.collectables)
		ft_free(data, "CONGRATS!");
}

void	move_right(t_data *data)
{
	if (data->map.map[data->map.player.x][data->map.player.y + 1] == '0')
	{
		ft_swap(&data->map.map[data->map.player.x][data->map.player.y + 1],
			&data->map.map[data->map.player.x][data->map.player.y]);
		data->map.player.y++;
		ft_printf("[%sMOVED RIGHT%s]-[%sCOUNT%s] > %d\n", RED, END, YELLOW, END,
			++data->mv_count);
	}
	else if (data->map.map[data->map.player.x][data->map.player.y + 1] == 'C')
	{
		data->map.collectables--;
		data->map.map[data->map.player.x][data->map.player.y] = '0';
		data->map.map[data->map.player.x][data->map.player.y + 1] = 'P';
		data->map.player.y++;
	}
	else if (data->map.map[data->map.player.x][data->map.player.y + 1] == 'E'
		&& !data->map.collectables)
		ft_free(data, "CONGRATS!");
}
