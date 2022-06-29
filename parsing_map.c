/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:52:35 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/21 23:29:18 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	build_map(t_program *program, char *line)
{
	int		i;
	char	**array;

	i = 0;
	program->map.column = program->map.column + 1;
	array = malloc (sizeof(char *) * (program->map.column + 1));
	if (!array)
		exit_error(2, program);
	while (program->map.map[i])
	{
		array[i] = program->map.map[i];
		i++;
	}
	array[i] = line;
	array[i + 1] = NULL;
	free(program->map.map);
	program->map.map = array;
}

void	parsing_map(t_program *program, int fd)
{
	int		len;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit_error(1, program);
	program->map.row = ft_strlen(line) - 1;
	while (line)
	{
		len = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			len--;
		if (len != program->map.row)
			exit_error(1, program);
		build_map (program, line);
		line = get_next_line(fd);
	}
	close (fd);
}
