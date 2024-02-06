/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:46:39 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/31 18:53:44 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"

void	ft_free(t_data *data, char *msg)
{
	int	i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (ft_strcmp(msg, "CONGRATS!") == 0)
		ft_printf("\n%s%s%s\n", GREEN,
			"⊱ ───────────── {.⋅ ✯ CONGRATS! ✯ ⋅.} ────────────── ⊰", END);
	else
		ft_printf("\n%s%s%s\n", RED, msg, END);
	exit(EXIT_SUCCESS);
}
