/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:05:44 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 16:51:48 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_cep2(char **map, int *c, int *e, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				(*c)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_cep(t_all *all)
{
	int	collectible;
	int	exit;
	int	player;

	collectible = 0;
	exit = 0;
	player = 0;
	check_cep2(all->map, &collectible, &exit, &player);
	if (collectible > 0 && exit > 0 && player == 1)
		return (1);
	return (0);
}

static void	check_first_middle(t_all *all, int width)
{
	int	i;

	i = 0;
	while (all->map[0][i] != '\0')
	{
		if (all->map[0][i] != '1')
			destroy_all_msg_exit(all, "Error\nInvalid map", 1);
		i++;
	}
	i = 1;
	while (all->map[i + 1] != NULL)
	{
		if (all->map[i][0] != '1' || all->map[i][width - 1] != '1')
			destroy_all_msg_exit(all, "Error\nInvalid map", 1);
		if ((int)ft_strlen(all->map[i]) != width)
			destroy_all_msg_exit(all, "Error\nInvalid map", 1);
		i++;
	}
}

static void	check_last(t_all *all, int width)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (all->map[i] != NULL)
	{
		if (all->map[i + 1] == NULL)
		{
			if ((int)ft_strlen(all->map[i]) != width)
				destroy_all_msg_exit(all, "Error\nInvalid map", 1);
			while (all->map[i][j] != '\0')
			{
				if (all->map[i][j] != '1')
					destroy_all_msg_exit(all, "Error\nInvalid map", 1);
				j++;
			}
		}
		i++;
	}
}

void	check_map(t_all *all)
{
	int	width;

	if (check_cep(all) == 0)
		destroy_all_msg_exit(all, "Error\nInvalid map", 1);
	width = ft_strlen(all->map[0]);
	check_first_middle(all, width);
	check_last(all, width);
}
