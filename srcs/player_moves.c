/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:18 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/18 03:23:55 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_input(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC_KEY)
		ft_free(data, "QUITTING THE GAME!.");
	else if (key == UP_KEY)
		move_up(data);
	else if (key == DOWN_KEY)
		move_down(data);
	else if (key == RIGHT_KEY)
		move_right(data);
	else if (key == LEFT_KEY)
		move_left(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_render_images(*data);
	return (0);
}
