/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ecp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:04:00 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 12:38:20 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_ecp(t_data data)
{
	int	e;
	int	c;
	int	p;
	int	i;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (data.map.map[i])
	{
		if (ft_strchr(data.map.map[i], 'E') == 1)
			e = 1;
		if (ft_strchr(data.map.map[i], 'C') == 1)
			c = 1;
		if (ft_strchr(data.map.map[i], 'P') == 1)
			p = 1;
		i++;
	}
	return (e && c && p);
}
