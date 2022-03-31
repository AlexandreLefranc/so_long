/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:42:35 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/01 00:24:20 by alefranc         ###   ########.fr       */
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

// check_map.c
void	check_map(char **map);

// error.c
void	print_usage();
void	msg_free_exit(char *msg, char **map, int exit_code);

// parsing.c
char	**parse_input(int argc, char **argv);

#endif
