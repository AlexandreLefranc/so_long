/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:24:55 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 17:51:14 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_usage()
{
	ft_putendl_fd("Error" ,2);
	ft_putendl_fd("Usage:" ,2);
	ft_putendl_fd("    ./so_long <file.ber>" ,2);
	ft_putendl_fd("Example:" ,2);
	ft_putendl_fd("    ./so_long maps/example.ber" ,2);
	exit(1);
}

void	msg_free_exit(char *msg, char **map, int exit_code)
{
	ft_putendl_fd(msg, 2);
	ft_strtabfree(map);
	exit(exit_code);
}

void	msg_free2_exit(char *msg, void	*ptr, int exit_code)
{
	ft_putendl_fd(msg, 2);
	free(ptr);
	exit(exit_code);
}

void	msg_exit(char *msg, int exit_code)
{
	ft_putendl_fd(msg, 2);
	exit(exit_code);
}
