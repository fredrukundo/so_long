/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:29:09 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 11:59:18 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"
#include "../../ft_printf/ft_printf.h"

static char	*ft_get_enemy_sprite(void)
{
	static int	i;
	char		*output;

	output = NULL;
	if (++i <= FRAME)
		output = "textures_bonus/enemy-1.xpm";
	else if (i > FRAME && i <= FRAME * 2)
		output = "textures_bonus/enemy-2.xpm";
	else
	{
		output = "textures_bonus/enemy-2.xpm";
		i = 0;
	}
	return (output);
}

char	*ft_get_image(char c, int can_exit)
{
	char	*output;

	output = NULL;
	if (c == WALL)
		output = "textures_bonus/newwall.xpm";
	else if (c == PLAYER)
		output = "textures_bonus/player.xpm";
	else if (c == COL)
		output = "textures_bonus/colle.xpm";
	else if (c == ENEMY)
		output = ft_get_enemy_sprite();
	else if (c == EXIT)
	{
		if (can_exit)
			output = "textures_bonus/exit_open.xpm";
		else
			output = "textures_bonus/exit_closed.xpm";
	}
	return (output);
}

void	render_images_action(t_data data, int x, int y)
{
	char	*img_path;

	if (data.map.collectables == 0)
		data.can_exit = 1;
	img_path = ft_get_image(data.map.map[x][y], data.can_exit);
	if (img_path)
	{
		data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, img_path,
				&data.img_size, &data.img_size);
		if (data.img_ptr)
		{
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr,
				y * SQUARE, x * SQUARE);
			mlx_destroy_image(data.mlx_ptr, data.img_ptr);
		}
		else
		{
			ft_printf("%s image path is invalid!%s\n", RED, END);
			exit(1);
		}
	}
}

static void	put_str_to_window(t_data *data)
{
	char		*num;
	char		*str;

	num = ft_itoa(data->mv_count);
	str = ft_strjoin("MOVEMENTS: ", num);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		(((data->map.col - 1) * SQUARE) / 2) - SQUARE, data->map.row * SQUARE,
		0x00ff00, str);
	free(num);
	free(str);
}

int	ft_render_images(void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)param;
	x = 0;
	data->img_size = SQUARE;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y] != '\n' && data->map.map[x][y])
		{
			render_images_action(*data, x, y);
			y++;
		}
		x++;
	}
	put_str_to_window(data);
	return (0);
}
