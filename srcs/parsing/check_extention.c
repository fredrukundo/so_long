/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:17:30 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/31 17:13:49 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_extention(const char *src, const char *to_find)
{
	size_t	len_to_find;
	size_t	src_len;

	len_to_find = ft_strlen(to_find);
	src_len = ft_strlen(src);
	while (src_len > len_to_find)
	{
		src++;
		src_len--;
	}
	return (ft_strcmp(src, to_find));
}
