/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:05:26 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/02 00:02:22 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"
#include "../../ft_printf/ft_printf.h"

void	ft_free(t_data *data, char *msg)
{
	int	i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
	free(data->map.enemy);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (ft_strcmp(msg, "CONGRATS!") == 0)
		ft_printf("\n%s%s%s\n", GREEN,
			"⊱ ────────────── {.⋅ ✯ CONGRATS! ✯ ⋅.} ────────────── ⊰", END);
	else
		ft_printf("\n%s%s%s\n", RED, msg, END);
	exit(EXIT_SUCCESS);
}
