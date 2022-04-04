/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:57:42 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/04 17:43:08 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_mlx(t_all *all)
{
	if (all->mlx != NULL && all->win != NULL)
	{
		mlx_destroy_window(all->mlx, all->win);
		mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
}

static void	destroy_sprites1(t_all *all)
{
	if (all->wall != NULL)
	{
		if (all->wall->img != NULL)
			mlx_destroy_image(all->mlx, all->wall->img);
		free(all->wall);
	}
	if (all->floor != NULL)
	{
		if (all->floor->img != NULL)
			mlx_destroy_image(all->mlx, all->floor->img);
		free(all->floor);
	}
}

static void	destroy_sprites2(t_all *all)
{
	if (all->player != NULL)
	{
		if (all->player->img != NULL)
			mlx_destroy_image(all->mlx, all->player->img);
		free(all->player);
	}
	if (all->exit != NULL)
	{
		if (all->exit->img != NULL)
			mlx_destroy_image(all->mlx, all->exit->img);
		free(all->exit);
	}
	if (all->collectible != NULL)
	{
		if (all->collectible->img != NULL)
			mlx_destroy_image(all->mlx, all->collectible->img);
		free(all->collectible);
	}
}

void	destroy_all(t_all *all)
{
	if (all->map != NULL)
		ft_strtabfree(all->map);
	destroy_sprites1(all);
	destroy_sprites2(all);
	destroy_mlx(all);
	free(all);
}
