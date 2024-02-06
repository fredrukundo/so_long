/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:39:02 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 18:39:03 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	reset_struct(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->img_size = 0;
	data->fd = 0;
	data->can_exit = 0;
	data->mv_count = 0;
	data->map.map = NULL;
	data->map.col = 0;
	data->map.row = 0;
	data->map.collectables = 0;
	data->map.number_of_enemies = 0;
	data->map.player.y = 0;
	data->map.player.x = 0;
	data->map.enemy = NULL;
}
