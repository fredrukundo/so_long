/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:02:46 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 18:03:16 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
	free(data->map.enemy);
	exit(EXIT_FAILURE);
}
