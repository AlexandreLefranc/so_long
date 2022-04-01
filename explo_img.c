/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:04:15 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 15:59:31 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>

# define WALL_F	"./asset/wall64.xpm"
# define FLOOR_F "./asset/floor64.xpm"
# define PLAYER_F "./asset/Alex_grey.xpm"
# define EXIT_F "./asset/exit64.xpm"
# define COLLECTIBLE_F "./asset/collectible64.xpm"

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
}	t_sprite;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	t_sprite	wall;
	t_sprite	floor;
	t_sprite	player;
	t_sprite	exit;
	t_sprite	collectible;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	wall.img = mlx_xpm_file_to_image(mlx, WALL_F, &wall.width, &wall.height);
	floor.img = mlx_xpm_file_to_image(mlx, FLOOR_F, &floor.width, &floor.height);
	player.img = mlx_xpm_file_to_image(mlx, PLAYER_F, &player.width, &player.height);
	exit.img = mlx_xpm_file_to_image(mlx, EXIT_F, &exit.width, &exit.height);
	collectible.img = mlx_xpm_file_to_image(mlx, COLLECTIBLE_F, &collectible.width, &collectible.height);

	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 64, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 128, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 192, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 256, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 320, 0);

	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 64);
	mlx_put_image_to_window(mlx, mlx_win, collectible.img, 64, 64);
	mlx_put_image_to_window(mlx, mlx_win, player.img, 128, 64);
	mlx_put_image_to_window(mlx, mlx_win, floor.img, 192, 64);
	mlx_put_image_to_window(mlx, mlx_win, floor.img, 256, 64);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 320, 64);

	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 128);
	mlx_put_image_to_window(mlx, mlx_win, floor.img, 64, 128);
	mlx_put_image_to_window(mlx, mlx_win, floor.img, 128, 128);
	mlx_put_image_to_window(mlx, mlx_win, floor.img, 192, 128);
	mlx_put_image_to_window(mlx, mlx_win, exit.img, 256, 128);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 320, 128);

	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 192);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 64, 192);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 128, 192);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 192, 192);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 256, 192);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 320, 192);

	sleep(2);

	mlx_put_image_to_window(mlx, mlx_win, player.img, 64, 64);
	mlx_put_image_to_window(mlx, mlx_win, floor.img, 128, 64);

	mlx_loop(mlx);
}
