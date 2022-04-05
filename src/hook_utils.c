/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:52:39 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 14:56:12 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross(t_all *all)
{
	destroy_all_msg_exit(all, "Bye!", 0);
	return (0);
}

void	get_player_pos(t_all *all, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i] != NULL)
	{
		j = 0;
		while (all->map[i][j] != '\0')
		{
			if (all->map[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	any_collectible_left(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i] != NULL)
	{
		j = 0;
		while (all->map[i][j] != '\0')
		{
			if (all->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
