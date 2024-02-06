/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:25:45 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/06 13:06:52 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "ft_printf/ft_printf.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(EXIT_FAILURE);
	check_map(av[1], &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		ft_printf("Error: Unable to initialize MiniLibX\n");
		exit(EXIT_FAILURE);
	}
	ft_new_window(&data);
	ft_render_images(data);
	mlx_hook(data.win_ptr, 2, 0, *ft_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
