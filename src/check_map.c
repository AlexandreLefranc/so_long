/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:05:44 by alefranc          #+#    #+#             */
/*   Updated: 2022/03/31 22:49:00 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_CEP(char	**map)
{
	int	collectible;
	int	exit;
	int	player;
	int	i;

	collectible = 0;
	exit = 0;
	player = 0;
	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strchr(map[i], 'C') != NULL)
			collectible++;
		if (ft_strchr(map[i], 'E') != NULL)
			exit++;
		if (ft_strchr(map[i], 'P') != NULL)
			player++;
		i++;
	}
	if (collectible > 0 && exit > 0 && player == 1)
		return (1);
	return (0);
}



void	check_map(char **map)
{
	int	width;

	if (check_CEP(map) == 0)
	{
		ft_strtabfree(map);
		ft_putendl_fd("Error\nMissing collectible, exit or player", 2);
		exit(1);
	}
	width = ft_strlen(map[0]);
	check_first(map);
	check_middles(map, width);
	check_last(map, width);
}
