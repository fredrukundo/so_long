/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:16:30 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/02 00:00:15 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"
#include "../../../ft_printf/ft_printf.h"

void	err_extention(char *file_name)
{
	ft_printf("%sso_long: %s: Invalid file extention.%s\n",
		RED, file_name, END);
	exit(EXIT_FAILURE);
}

void	err_rectangular(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Map isn't rectangualr!.%s\n", RED,
		file_name, END);
	free_map(data);
}

void	err_characters(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Invalid character found!.%s\n",
		RED, file_name, END);
	free_map(data);
}

void	err_walls(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Invalid walls!.%s\n", RED, file_name, END);
	free_map(data);
}

void	err_ecp(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Player or Exit or Collectible not Found!!.%s\n",
		RED, file_name, END);
	free_map(data);
}
