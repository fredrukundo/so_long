/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:05 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/03 01:56:18 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
