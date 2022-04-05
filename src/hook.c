/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:13:44 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 17:02:17 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	apply_move(t_all *all, int x, int y)
{
	int	old_x;
	int	old_y;

	get_player_pos(all, &old_x, &old_y);
	mlx_put_image_to_window(all->mlx, all->win, all->player->img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
	mlx_put_image_to_window(all->mlx, all->win, all->floor->img,
		old_x * SPRITE_SIZE, old_y * SPRITE_SIZE);
	all->map[old_y][old_x] = '0';
	all->map[y][x] = 'P';
	all->count++;
	ft_printf("Move count: %d\n", all->count);
}

static void	move(t_all *all, int x, int y)
{
	int	p_x;
	int	p_y;

	get_player_pos(all, &p_x, &p_y);
	if (all->map[p_y + y][p_x + x] == '0')
		apply_move(all, p_x + x, p_y + y);
	if (all->map[p_y + y][p_x + x] == 'C')
		apply_move(all, p_x + x, p_y + y);
	if (all->map[p_y + y][p_x + x] == 'E' && any_collectible_left(all) == 0)
	{
		all->count++;
		ft_printf("Move count: %d\n", all->count);
		ft_printf("Congratz! You beat this map in %d moves!\n", all->count);
		destroy_all_msg_exit(all, "", 0);
	}
}

static int	hook_function(int key, t_all *all)
{
	if (key == 65307)
		destroy_all_msg_exit(all, "Bye!", 0);
	if (key == 97)
		move(all, -1, 0);
	if (key == 100)
		move(all, 1, 0);
	if (key == 119)
		move(all, 0, -1);
	if (key == 115)
		move(all, 0, 1);
	return (0);
}

void	hook(t_all *all)
{
	mlx_key_hook(all->win, hook_function, all);
	mlx_hook(all->win, 17, 0, cross, all);
}
