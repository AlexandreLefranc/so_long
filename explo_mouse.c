/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:21:47 by alefranc          #+#    #+#             */
/*   Updated: 2022/03/31 15:49:40 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	hook(int x, int y, void *vars)
{
	printf("x=%d, y=%d\n", x, y);
	(void)vars;
	return (0);
}

int	enter(void *vars)
{
	printf("Hello!\n");
	(void)vars;
	return (0);
}

int	leave(void *vars)
{
	printf("Bye!\n");
	(void)vars;
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	mlx_hook(vars.win, 6, 1L<<6, hook, &vars); // position
	mlx_hook(vars.win, 7, 1L<<4, enter, &vars); // enter
	mlx_hook(vars.win, 8, 1L<<5, leave, &vars); // leave
	// mlx_hook(vars.win, 23, 1L<<17, leave, &vars);
	mlx_loop(vars.mlx);
}
