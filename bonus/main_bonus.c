/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 16:25:14 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"
#include "../ft_printf/ft_printf.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(EXIT_FAILURE);
	reset_struct(&data);
	check_map(av[1], &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		ft_printf("Error: Unable to initialize MiniLibX\n");
		exit(EXIT_FAILURE);
	}
	ft_new_window(&data);
	mlx_loop_hook(data.mlx_ptr, ft_render_images, &data);
	mlx_hook(data.win_ptr, 2, 0, *ft_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
