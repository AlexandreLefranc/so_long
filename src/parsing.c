/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:46:39 by alefranc          #+#    #+#             */
/*   Updated: 2022/04/07 15:23:06 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

static char	*read_file_to_str(char *file)
{
	int		fd;
	ssize_t	ret;
	char	buffer[1024];
	char	*old_str;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buffer, 1023);
	if (ret <= 0)
		return (NULL);
	old_str = ft_strdup("");
	if (old_str == NULL)
		return (NULL);
	while (ret != 0)
	{
		buffer[ret] = '\0';
		str = ft_strjoin(old_str, buffer);
		free(old_str);
		old_str = str;
		ret = read(fd, buffer, 1023);
	}
	close(fd);
	return (str);
}

char	**parse_input(int argc, char **argv, t_all *all)
{
	char	*str_map;
	int		i;
	char	*tmp;

	if (argc != 2)
		print_usage(all);
	if (is_ber_file(argv[1]) == 0)
		print_usage(all);
	str_map = read_file_to_str(argv[1]);
	if (str_map == NULL || str_map[0] == '\0')
		destroy_all_errmsg_exit(all, "Error\nInvalid map", 1);
	all->map = ft_split(str_map, '\n');
	free(str_map);
	if (all->map == NULL)
		destroy_all_errmsg_exit(all, "failed to split map", 1);
	i = 0;
	while (all->map[i] != NULL)
	{
		tmp = all->map[i];
		all->map[i] = ft_strtrim(all->map[i], "	 ");
		free(tmp);
		i++;
	}
	return (NULL);
}
