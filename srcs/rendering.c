/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:53:50 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/05 10:12:58 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"

char	*ft_get_image(char c, int can_exit)
{
	char	*output;

	(void)can_exit;
	output = NULL;
	if (c == WALL)
		output = "textures/newwall.xpm";
	else if (c == PLAYER)
		output = "textures/player.xpm";
	else if (c == COLL)
		output = "textures/colle.xpm";
	else if (c == EXIT)
	{
		if (can_exit)
			output = "textures/exit_open.xpm";
		else
			output = "textures/exit_closed.xpm";
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

void	ft_render_images(t_data data)
{
	int		x;
	int		y;

	x = 0;
	data.img_size = SQUARE;
	while (data.map.map[x])
	{
		y = 0;
		while (data.map.map[x][y] != '\n' && data.map.map[x][y])
		{
			render_images_action(data, x, y);
			y++;
		}
		x++;
	}
}
