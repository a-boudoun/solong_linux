/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:03 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/29 22:23:40 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	render_player(t_program *program, int j, int i)
{
	program->player.x = i;
	program->player.y = j;
	if (program->player.position == 1)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.player_right, i * HEIGHT, j * WIDTH);
	else if (program->player.position == 2)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.player_left, i * HEIGHT, j * WIDTH);
	else if (program->player.position == 3)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.player_down, i * HEIGHT, j * WIDTH);
	else if (program->player.position == 4)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.player_up, i * HEIGHT, j * WIDTH);
}

void	render_exit(t_program *program, int j, int i)
{
	if (program->map.collectible)
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.exit_no, i * HEIGHT, j * WIDTH);
	else
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.exit_yes, i * HEIGHT, j * WIDTH);
}

void	render_map(t_program *program, int j, int i)
{
	if (program->map.map[j][i] == '1')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.wall, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == '0')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.floor, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == 'P')
		render_player(program, j, i);
	if (program->map.map[j][i] == 'C')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.collect, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == 'I')
		mlx_put_image_to_window(program->mlx, program->mlx_win,
			program->img.imposter, i * HEIGHT, j * WIDTH);
	if (program->map.map[j][i] == 'E')
		render_exit(program, j, i);
}

static char	*ft_write(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (str);
}

static int	ft_numberlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	number;
	int		sign;

	sign = 1;
	len = ft_numberlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_write(str, number, len);
	return (str);
}

void	put_moves(t_program *program, int mv)
{
	char	*moves;

	moves = ft_itoa(mv);
	mlx_string_put(program->mlx, program->mlx_win, 1, 0, GREEN, "Moves : ");
	mlx_string_put(program->mlx, program->mlx_win, 90, 0, GREEN, moves);
	free(moves);
}

void	render_game(t_program *program)
{
	int	i;
	int	j;

	j = 0;
	while (j < program->map.column)
	{
		i = 0;
		while (i < program->map.row)
		{
			render_map(program, j, i);
			i++;
		}
		j++;
	}
	put_moves(program, program->moves);
}
