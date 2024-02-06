/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:57:36 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 12:34:03 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	free(data->map.map);
	exit(EXIT_FAILURE);
}
