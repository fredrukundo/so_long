/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:29:27 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/17 04:57:03 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	in_set(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "10CEP";
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

	row = 0;
	while (data.map.map[row] != NULL)
	{
		col = 0;
		while (data.map.map[row][col] != '\n' && data.map.map[row][col] != '\0')
		{
			if (!in_set(data.map.map[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
