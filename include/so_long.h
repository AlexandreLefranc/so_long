/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:42:35 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/04 17:48:14 by alefranc         ###   ########.fr       */
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

# define WALL_F	"./asset/wall64.xpm"
# define FLOOR_F "./asset/floor64.xpm"
# define PLAYER_F "./asset/Alex_grey.xpm"
# define EXIT_F "./asset/exit64.xpm"
# define COLLECTIBLE_F "./asset/collectible64.xpm"
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
void	check_map(char **map);

// create_sprites.c
void	create_sprites(t_all *all);

// create_window.c
void	create_window(t_all *all);

// destroy_all.c
void	destroy_all(t_all *all);

// display_map.c
void	display_map(t_all *all);

// error.c
void	print_usage(void);
void	msg_free_exit(char *msg, char **map, int exit_code);
void	msg_free2_exit(char *msg, void	*ptr, int exit_code);
void	msg_exit(char *msg, int exit_code);

// parsing.c
char	**parse_input(int argc, char **argv);

#endif
