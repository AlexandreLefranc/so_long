/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:10:11 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 16:57:45 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	get_win_width(t_all *all)
{
	return (ft_strlen(all->map[0]));
}

static size_t	get_win_height(t_all *all)
{
	size_t	i;

	i = 0;
	while (all->map[i] != NULL)
		i++;
	return (i);
}

void	create_window(t_all *all)
{
	size_t	win_width;
	size_t	win_height;

	win_width = get_win_width(all);
	win_height = get_win_height(all);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, win_width * SPRITE_SIZE,
			win_height * SPRITE_SIZE, "so_long!");
}
