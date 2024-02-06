/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:07:48 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/05 18:35:25 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

size_t	ft_strlen_exclude_newline(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

int	check_rectangular(t_data data)
{
	int	row;
	int	len;
	int	line_len;

	row = 0;
	line_len = ft_strlen_exclude_newline(data.map.map[row]);
	while (data.map.map[row] != NULL)
	{
		len = ft_strlen_exclude_newline(data.map.map[row]);
		if (line_len != len)
			return (1);
		row++;
	}
	return (0);
}
