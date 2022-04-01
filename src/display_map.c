/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:16:32 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 17:27:57 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_sprite(t_all *all, char c, size_t col, size_t row)
{
	printf("c=%c\n", c);
	if (c == '1')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->wall->img,
			col * SPRITE_SIZE, row * SPRITE_SIZE);
	}
	else if (c == '0')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->floor->img,
			col * SPRITE_SIZE, row * SPRITE_SIZE);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->player->img,
			col * SPRITE_SIZE, row * SPRITE_SIZE);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->exit->img,
			col * SPRITE_SIZE, row * SPRITE_SIZE);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->collectible->img,
			col * SPRITE_SIZE, row * SPRITE_SIZE);
	}
	else
	{
		printf("Unknown sprite\n");
	}
}

void	display_map(t_all *all)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (all->map[row] != NULL)
	{
		col = 0;
		while (all->map[row][col] != '\0')
		{
			display_sprite(all, all->map[row][col], col, row);
			col++;
		}
		row++;
	}
}
