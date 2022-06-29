/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:46:49 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/25 15:12:34 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	destroy_images(t_program *program)
{
	if (program->img.player_down)
		mlx_destroy_image(program->mlx, program->img.player_down);
	if (program->img.player_up)
		mlx_destroy_image(program->mlx, program->img.player_up);
	if (program->img.player_left)
		mlx_destroy_image(program->mlx, program->img.player_left);
	if (program->img.player_right)
		mlx_destroy_image(program->mlx, program->img.player_right);
	if (program->img.collect)
		mlx_destroy_image(program->mlx, program->img.collect);
	if (program->img.exit_no)
		mlx_destroy_image(program->mlx, program->img.exit_no);
	if (program->img.exit_yes)
		mlx_destroy_image(program->mlx, program->img.exit_yes);
	if (program->img.wall)
		mlx_destroy_image(program->mlx, program->img.wall);
	if (program->img.floor)
		mlx_destroy_image(program->mlx, program->img.floor);
}

static void	ft_free(t_program *program)
{
	int	i;

	i = 0;
	while (i <= program->map.column)
	{
		if (program->map.map[i])
			free(program->map.map[i]);
		i++;
	}
	if (program->map.map)
		free(program->map.map);
}

void	exit_success(int nb, t_program *program)
{
	if (nb == 0)
		ft_printf("quit successfully\n");
	else if (nb == 1)
		ft_printf("you win\n");
	ft_free(program);
	destroy_images(program);
	exit (0);
}

int	destroy(t_program *program)
{
	exit_success(0, program);
	return (1);
}

void	exit_error(int error, t_program *program)
{
	if (error == 0)
	{
		ft_printf("error\ninvalide file");
		exit(1);
	}
	else if (error == 1)
		ft_printf("error \ninvalid map");
	else if (error == 2)
		ft_printf("error \nmalloc error");
	else if (error == 3)
		ft_printf("error \nMLX library initialization failed");
	else if (error == 4)
		ft_printf("error \nimage error");
	ft_free(program);
	destroy_images(program);
	exit(1);
}
