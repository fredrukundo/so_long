/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:52:46 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/31 18:55:41 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../ft_printf/ft_printf.h"

void	extention_err(char *file_name)
{
	ft_printf("%sso_long: %s: Invalid file extention.%s\n",
		RED, file_name, END);
	exit(EXIT_FAILURE);
}

void	err_rectangular(t_data *data, char *file_name)
{
	ft_printf("%sso_long: %s: Map isn't rectangular!.%s\n", RED,
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
