/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:46:42 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 16:39:57 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_sprites(t_all *all)
{
	all->wall = ft_calloc(sizeof(*(all->wall)), 1);
	all->wall->img = mlx_xpm_file_to_image(all->mlx, WALL_F,
			&all->wall->width, &all->wall->height);
	if (all->wall->img == NULL)
		destroy_all_msg_exit(all, "Error\nMissing xpm file", 1);
	all->floor = ft_calloc(sizeof(*(all->floor)), 1);
	all->floor->img = mlx_xpm_file_to_image(all->mlx, FLOOR_F,
			&all->floor->width, &all->floor->height);
	if (all->floor->img == NULL)
		destroy_all_msg_exit(all, "Error\nMissing xpm file", 1);
	all->player = ft_calloc(sizeof(*(all->player)), 1);
	all->player->img = mlx_xpm_file_to_image(all->mlx, PLAYER_F,
			&all->player->width, &all->player->height);
	if (all->player->img == NULL)
		destroy_all_msg_exit(all, "Error\nMissing xpm file", 1);
	all->exit = ft_calloc(sizeof(*(all->exit)), 1);
	all->exit->img = mlx_xpm_file_to_image(all->mlx, EXIT_F,
			&all->exit->width, &all->exit->height);
	if (all->exit->img == NULL)
		destroy_all_msg_exit(all, "Error\nMissing xpm file", 1);
	all->collectible = ft_calloc(sizeof(*(all->collectible)), 1);
	all->collectible->img = mlx_xpm_file_to_image(all->mlx, COLLECTIBLE_F,
			&all->collectible->width, &all->collectible->height);
	if (all->collectible->img == NULL)
		destroy_all_msg_exit(all, "Error\nMissing xpm file", 1);
}
