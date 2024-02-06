/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:41:37 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/31 18:54:48 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../ft_printf/ft_printf.h"

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
