/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:42:35 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 17:37:56 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"

# define WALL_F	"./asset/road.xpm"
# define FLOOR_F "./asset/grass.xpm"
# define PLAYER_F "./asset/kitten.xpm"
# define EXIT_F "./asset/trampoline.xpm"
# define COLLECTIBLE_F "./asset/poisson.xpm"
# define SPRITE_SIZE 64

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_all
{
	char		**map;
	void		*mlx;
	void		*win;
	t_sprite	*wall;
	t_sprite	*floor;
	t_sprite	*player;
	t_sprite	*exit;
	t_sprite	*collectible;
	size_t		count;
}	t_all;

// check_map.c
void	check_map(t_all *all);

// create_sprites.c
void	create_sprites(t_all *all);

// create_window.c
void	create_window(t_all *all);

// destroy_all.c
void	destroy_all(t_all *all);
void	destroy_all_msg_exit(t_all *all, char *msg, int exit_code);

// display_map.c
void	display_map(t_all *all);

// error.c
void	print_usage(t_all *all);

// hook_utils.c
int		cross(t_all *all);
void	get_player_pos(t_all *all, int *player_x, int *player_y);
int		any_collectible_left(t_all *all);

// hook.c
void	hook(t_all *all);

// parsing.c
char	**parse_input(int argc, char **argv, t_all *all);

#endif
