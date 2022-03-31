/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:47:29 by alefranc          #+#    #+#             */
/*   Updated: 2022/03/31 12:40:48 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_square(t_data *data, int x, int y, int color, int length)
{
	int	l = length;

	while (l > 0)
	{
		my_mlx_pixel_put(data, x + length, y + l, color);
		my_mlx_pixel_put(data, x, y + l, color);

		my_mlx_pixel_put(data, x + l, y, color);
		my_mlx_pixel_put(data, x + l, y + length, color);
		l--;
	}
	my_mlx_pixel_put(data, x, y, color);
	my_mlx_pixel_put(data, x + length, y + length, color);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_square(&img, 400, 300, 0x00FF0000, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(5);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_display(mlx);
	free(mlx);
}
