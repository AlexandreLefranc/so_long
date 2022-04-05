/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:44:59 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 14:49:46 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_all	*init_all(void)
{
	t_all	*all;

	all = ft_calloc(sizeof(*all), 1);
	all->map = NULL;
	all->mlx = NULL;
	all->win = NULL;
	all->wall = NULL;
	all->floor = NULL;
	all->player = NULL;
	all->exit = NULL;
	all->collectible = NULL;
	all->count = 0;
	return (all);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = init_all();
	parse_input(argc, argv, all);
	check_map(all);

	int i = 0;
	while (all->map[i] != NULL)
	{
		printf("%s\n", all->map[i]);
		i++;
	}

	create_window(all);
	create_sprites(all);
	display_map(all);
	// hook_quit(all);
	hook(all);
	// hook_keys

	mlx_loop(all->mlx);
	sleep(1);
	destroy_all(all);
	return (0);
}
