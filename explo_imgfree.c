/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo_imgfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:04:15 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/04 17:41:18 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define WALL_F	"./asset/wall64.xpm"

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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	wall.img = mlx_xpm_file_to_image(mlx, WALL_F, &wall.width, &wall.height);

	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 64, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 128, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 192, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 256, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall.img, 320, 0);

	//mlx_loop(mlx);
	sleep(1);

	mlx_destroy_image(mlx, wall.img);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}
