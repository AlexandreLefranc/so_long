/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo_mouse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:00:21 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 11:07:19 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	mouse_hook(int button, int x, int y, t_vars *var)
{
	if (button == 1)
		printf("%d, %d\n", x, y);
	(void)var;
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
