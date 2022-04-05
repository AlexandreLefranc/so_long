/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:24:55 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/05 16:42:06 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_usage(t_all *all)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Usage:", 2);
	ft_putendl_fd("    ./so_long <file.ber>", 2);
	ft_putendl_fd("Example:", 2);
	ft_putendl_fd("    ./so_long maps/example.ber", 2);
	free(all);
	exit(1);
}
