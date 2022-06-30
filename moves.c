/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:07:51 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/30 19:11:01 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	move_right(t_program *program, bool *trigger)
{
	int	x;
	int	y;

	x = program->player.x;
	y = program->player.y;
	if (program->map.map[y][x + 1] == 'E')
	{
		if (program->map.collectible == 0)
			exit_success(1, program);
		return ;
	}
	program->player.position = 1;
	program->map.map[y][x] = '0';
	x++;
	if (program->map.map[y][x] == 'C')
	{
		program->map.collectible -= 1;
		program->map.map[y][x] = '0';
	}
	program->map.map[y][x] = 'P';
	*trigger = true;
}

void	move_left(t_program *program, bool *trigger)
{
	int	x;
	int	y;

	x = program->player.x;
	y = program->player.y;
	if (program->map.map[y][x - 1] == 'E')
	{
		if (program->map.collectible == 0)
			exit_success(1, program);
		return ;
	}
	program->player.position = 2;
	program->map.map[y][x] = '0';
	x--;
	if (program->map.map[y][x] == 'C')
	{
		program->map.collectible -= 1;
		program->map.map[y][x] = '0';
	}
	program->map.map[y][x] = 'P';
	*trigger = true;
}

void	move_down(t_program *program, bool *trigger)
{
	int	x;
	int	y;

	x = program->player.x;
	y = program->player.y;
	if (program->map.map[y + 1][x] == 'E')
	{
		if (program->map.collectible == 0)
			exit_success(1, program);
		return ;
	}
	program->player.position = 3;
	program->map.map[y][x] = '0';
	y++;
	if (program->map.map[y][x] == 'C')
	{
		program->map.collectible -= 1;
		program->map.map[y][x] = '0';
	}
	program->map.map[y][x] = 'P';
	*trigger = true;
}

void	move_up(t_program *program, bool *trigger)
{
	int	x;
	int	y;

	x = program->player.x;
	y = program->player.y;
	if (program->map.map[y - 1][x] == 'E')
	{
		if (program->map.collectible == 0)
			exit_success(1, program);
		return ;
	}
	program->player.position = 4;
	program->map.map[y][x] = '0';
	y--;
	if (program->map.map[y][x] == 'C')
	{
		program->map.collectible -= 1;
		program->map.map[y][x] = '0';
	}
	program->map.map[y][x] = 'P';
	*trigger = true;
}

int	moves(int key, t_program *program)
{
	bool		trigger;
	int			x;
	int			y;

	x = program->player.x;
	y = program->player.y;
	trigger = false;
	if ((key == W || key == UP) && program->map.map[y - 1][x] != '1')
		move_up(program, &trigger);
	if ((key == A || key == RIGHT) && program->map.map[y][x + 1] != '1')
		move_right(program, &trigger);
	if ((key == S || key == DOWN) && program->map.map[y + 1][x] != '1')
		move_down(program, &trigger);
	if ((key == D || key == LEFT) && program->map.map[y][x - 1] != '1')
		move_left(program, &trigger);
	if (key == ESC)
		exit_success(0, program);
	if (trigger)
		ft_printf("moves : %d\n", program->moves++);
	render_game(program);
	return (1);
}
