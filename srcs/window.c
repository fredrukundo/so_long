/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:34:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/05 10:14:25 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"

int	ft_close(t_data *data)
{
	ft_free(data, "WINDOW CLOSED!");
	return (0);
}

void	ft_new_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.col * SQUARE,
			data->map.row * SQUARE, "so_long");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error: Unable to create MiniLibX window\n");
		ft_close(data);
		exit(EXIT_FAILURE);
	}
	mlx_hook(data->win_ptr, WIN_CLOSE, 0, ft_close, data);
}
