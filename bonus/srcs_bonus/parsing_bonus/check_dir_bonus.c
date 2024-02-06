/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:57:00 by frukundo          #+#    #+#             */
/*   Updated: 2024/02/02 00:00:38 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"
#include "../../../ft_printf/ft_printf.h"

void	check_dir(char	*file_name)
{
	int	fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd != -1)
	{
		ft_printf("%sso_long: %s: %s%s\n", RED, file_name, DIR_ERROR, END);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
