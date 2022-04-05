/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:05:05 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 14:11:23 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	echap(int key, t_all *all)
{
	if (key == 65307)
		destroy_all_msg_exit(all, "Bye!", 0);
	return (0);
}

static int	cross(t_all *all)
{
	destroy_all_msg_exit(all, "Bye!", 0);
	return (0);
}

void	hook_quit(t_all *all)
{
	mlx_key_hook(all->win, echap, all);
	mlx_hook(all->win, 17, 0, cross, all);
}
