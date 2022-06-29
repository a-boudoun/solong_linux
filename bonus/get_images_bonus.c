/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:11:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/25 15:14:26 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	player_images(t_program *program)
{
	int	img_height;
	int	img_width;

	program->img.player_right = mlx_xpm_file_to_image(program->mlx,
			"images/player_right.xpm", &img_width, &img_height);
	if (!program->img.player_right)
		exit_error(4, program);
	program->img.player_down = mlx_xpm_file_to_image(program->mlx,
			"images/player_down.xpm", &img_width, &img_height);
	if (!program->img.player_down)
		exit_error(4, program);
	program->img.player_up = mlx_xpm_file_to_image(program->mlx,
			"images/player_up.xpm", &img_width, &img_height);
	if (!program->img.player_up)
		exit_error(4, program);
	program->img.player_left = mlx_xpm_file_to_image(program->mlx,
			"images/player_left.xpm", &img_width, &img_height);
	if (!program->img.player_left)
		exit_error(4, program);
}

void	exit_images(t_program *program)
{
	int	img_height;
	int	img_width;

	program->img.exit_no = mlx_xpm_file_to_image(program->mlx,
			"images/exit_no.xpm", &img_width, &img_height);
	if (!program->img.exit_no)
		exit_error(4, program);
	program->img.exit_yes = mlx_xpm_file_to_image(program->mlx,
			"images/exit_yes.xpm", &img_width, &img_height);
	if (!program->img.exit_yes)
		exit_error(4, program);
}

void	map_images(t_program *program)
{
	int	img_height;
	int	img_width;

	program->img.collect = mlx_xpm_file_to_image(program->mlx,
			"images/collect.xpm", &img_width, &img_height);
	if (!program->img.collect)
		exit_error(4, program);
	program->img.wall = mlx_xpm_file_to_image(program->mlx,
			"images/wall.xpm", &img_width, &img_height);
	if (!program->img.wall)
		exit_error(4, program);
	program->img.floor = mlx_xpm_file_to_image(program->mlx,
			"images/floor.xpm", &img_width, &img_height);
	if (!program->img.floor)
		exit_error(4, program);
	program->img.imposter = mlx_xpm_file_to_image(program->mlx,
			"./images/imposter.xpm", &img_width, &img_height);
	if (!program->img.imposter)
		exit_error(4, program);
}

void	get_images(t_program *program)
{
	map_images(program);
	player_images(program);
	exit_images(program);
}
