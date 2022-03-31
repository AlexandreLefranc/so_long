/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:05:44 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 00:29:08 by alefranc         ###   ########.fr       */
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

static void	check_first(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			msg_free_exit("Error\nFirst row isn't only 1", map, 1);
		i++;
	}
}

static void	check_middle(char **map, int width)
{
	int	i;

	i = 1;
	while (map[i+1] != NULL)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			msg_free_exit("Error\nMiddle row: no 1 at start or end", map, 1);
		if ((int)ft_strlen(map[i]) != width)
			msg_free_exit("Error\nMiddle row: not good length", map, 1);
		i++;
	}
}

static void	check_last(char **map, int width)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i + 1] == NULL)
		{
			if ((int)ft_strlen(map[i]) != width)
				msg_free_exit("Error\nLast row length problem", map, 2);
			while (map[i][j] != '\0')
			{
				if (map[i][j] != '1')
					msg_free_exit("Error\nLast row not only 1", map, 1);
				j++;
			}
		}
		i++;
	}
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
	check_middle(map, width);
	check_last(map, width);
}
