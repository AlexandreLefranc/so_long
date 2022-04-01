/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:46:42 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 17:15:40 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_sprites(t_all *all)
{
	all->wall = ft_calloc(sizeof(*(all->wall)), 1);
	all->wall->img = mlx_xpm_file_to_image(all->mlx, WALL_F,
		&all->wall->width, &all->wall->height);
	all->floor = ft_calloc(sizeof(*(all->floor)), 1);
	all->floor->img = mlx_xpm_file_to_image(all->mlx, FLOOR_F,
		&all->floor->width, &all->floor->height);
	all->player = ft_calloc(sizeof(*(all->player)), 1);
	all->player->img = mlx_xpm_file_to_image(all->mlx, PLAYER_F,
		&all->player->width, &all->player->height);
	all->exit = ft_calloc(sizeof(*(all->exit)), 1);
	all->exit->img = mlx_xpm_file_to_image(all->mlx, EXIT_F,
		&all->exit->width, &all->exit->height);
	all->collectible = ft_calloc(sizeof(*(all->collectible)), 1);
	all->collectible->img = mlx_xpm_file_to_image(all->mlx, COLLECTIBLE_F,
		&all->collectible->width, &all->collectible->height);
	//
	// mlx_put_image_to_window(all->mlx, all->win, all->wall->img, 0, 0);
	// mlx_put_image_to_window(all->mlx, all->win, all->floor->img, 64, 0);
	// mlx_put_image_to_window(all->mlx, all->win, all->player->img, 128, 0);
	// mlx_put_image_to_window(all->mlx, all->win, all->exit->img, 192, 0);
	// mlx_put_image_to_window(all->mlx, all->win, all->collectible->img, 256, 0);
}
