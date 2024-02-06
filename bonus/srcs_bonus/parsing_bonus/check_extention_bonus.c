/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:57:56 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/15 17:20:30 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	check_extention(const char *src, const char *to_find)
{
	size_t	to_find_len;
	size_t	src_len;

	to_find_len = ft_strlen(to_find);
	src_len = ft_strlen(src);
	while (src_len > to_find_len)
	{
		src++;
		src_len--;
	}
	return (ft_strcmp(src, to_find));
}
