/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:01:25 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/05 08:56:50 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"
#include "../../../ft_printf/ft_printf.h"

void	err_player(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Only one player is allowed!%s\n", RED,
		file_name, END);
	free_map(data);
}

void	err_exit(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Only one exit is allowed!%s\n", RED,
		file_name, END);
	free_map(data);
}

int	check_player(t_data data)
{
	int		p;
	int		i;
	int		j;
	char	*row;

	p = 0;
	i = 0;
	while (data.map.map[i])
	{
		row = data.map.map[i];
		j = 0;
		while (row[j])
		{
			if (row[j] == 'P')
			{
				p++;
				if (p > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (p == 1);
}

int	check_exit(t_data data)
{
	int		e;
	int		i;
	int		j;
	char	*row;

	e = 0;
	i = 0;
	while (data.map.map[i])
	{
		row = data.map.map[i];
		j = 0;
		while (row[j])
		{
			if (row[j] == 'E')
			{
				e++;
				if (e > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (e == 1);
}
