/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_component_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:32:37 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/23 18:18:10 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static void	valid_char(t_program *program, char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E' && c != 'I')
		exit_error(1, program);
	if (c == 'C')
		program->map.collectible += 1;
	else if (c == 'P')
		program->player.position += 1;
	else if (c == 'E')
		program->map.exit += 1;
}

static void	check_chars(t_program *program)
{
	if (program->map.collectible == 0 || program->player.position != 1
		|| program->map.exit == 0)
		exit_error(1, program);
}

static void	check_walls(t_program *program)
{
	int	i;
	int	column;

	i = 0;
	while (program->map.map[0][i] && program->map.map[0][i] != '\n')
	{
		if (program->map.map[0][i] != '1')
			exit_error(1, program);
		i++;
	}
	i = 0;
	column = program->map.column - 1;
	while (program->map.map[column][i] && program->map.map[column][i] != '\n')
	{
		if (program->map.map[column][i] != '1')
			exit_error(1, program);
		i++;
	}
}

void	check_component(t_program *program)
{
	int	i;
	int	j;

	i = 0;
	while (program->map.map[i])
	{
		j = 0;
		while (program->map.map[i][j] && j < program->map.row - 1)
		{
			valid_char (program, program->map.map[i][j]);
			j++;
		}
		if (program->map.map[i][0] != '1' || program->map.map[i][j] != '1')
			exit_error(1, program);
		i++;
	}
	check_chars(program);
	check_walls(program);
}
