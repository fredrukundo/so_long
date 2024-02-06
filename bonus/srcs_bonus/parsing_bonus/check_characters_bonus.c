/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:30:21 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 17:19:58 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	in_set(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "10CEPX";
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_characters(t_data data)
{
	int	row;
	int	col;
	int	player;

	row = 0;
	player = 0;
	while (data.map.map[row] != NULL)
	{
		col = 0;
		while (data.map.map[row][col] != '\n' && data.map.map[row][col] != '\0')
		{
			if (data.map.map[row][col] == 'P')
				player++;
			if (!in_set(data.map.map[row][col]) || player > 1)
			{
				if (player > 1)
					return (2);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}
