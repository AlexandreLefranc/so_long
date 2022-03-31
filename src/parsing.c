/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:46:39 by alefranc          #+#    #+#             */
/*   Updated: 2022/03/31 23:47:39 by alefranc         ###   ########.fr       */
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
	old_str = ft_strdup("");
	ret = read(fd, buffer, 1023);
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

char	**parse_input(int argc, char **argv)
{
	char	*str_map;
	char	**map;
	int		i;
	char	*tmp;

	if (argc != 2)
		print_usage();
	if (is_ber_file(argv[1]) == 0)
		print_usage();
	str_map = read_file_to_str(argv[1]);
	if (str_map == NULL)
		return (NULL);
	map = ft_split(str_map, '\n');
	free(str_map);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tmp = map[i];
		map[i] = ft_strtrim(map[i], "	 ");
		free(tmp);
		i++;
	}
	return (map);
}
