/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:18:23 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 17:21:17 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	map_len(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (len);
}
