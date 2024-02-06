/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:12:06 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/05 20:11:35 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"
#include "../../../ft_printf/ft_printf.h"

void	validate_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sso_long: %s: No such file or directory.%s\n",
			RED, file_name, END);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	get_map(char *file_name, t_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	validate_file(file_name);
	data->map.row = map_len(fd);
	if (!data->map.row)
	{
		ft_printf("%sso_long: %s: is empty!%s\n", RED,
			file_name, END);
		exit(1);
	}
	close(fd);
	data->map.map = malloc(sizeof(char *) * (data->map.row + 1));
	if (!data->map.map)
	{
		ft_printf("%s%s%s\n", RED, MALLOC_ERROR, END);
		exit(EXIT_FAILURE);
	}
	data->map.map[data->map.row] = 0;
	fd = open(file_name, O_RDONLY);
	while (i < data->map.row)
		data->map.map[i++] = get_next_line(fd);
	close(fd);
}
