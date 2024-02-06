/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:00:38 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/05 19:14:47 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	check_map(char *file_name, t_data *data)
{
	check_dir(file_name);
	if (check_extention(file_name, ".ber") != 0)
		err_extention(file_name);
	get_map(file_name, data);
	if (check_rectangular(*data) == 1)
		err_rectangular(data, file_name);
	if (check_characters(*data) == 0)
		err_characters(data, file_name);
	if (check_player(*data) == 0)
		err_player(data, file_name);
	if (check_exit(*data) == 0)
		err_exit(data, file_name);
	if (check_walls(data) != 0)
		err_walls(data, file_name);
	if (check_ecp(*data) == 0)
		err_ecp(data, file_name);
	if (check_valid_path(data))
		error_invalid_path(data, file_name);
	if (check_path_collectible(data))
		error_invalid_path(data, file_name);
	get_collectables(data);
	get_player_position(data);
	count_number_of_enemies(data);
	get_enemies_positions(data);
}
