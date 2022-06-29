/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:48:34 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/25 14:50:36 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_program	program;
	int			fd;

	if (argc != 2)
	{
		ft_printf("error \nusage: <./so_long> <map.ber>");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || ft_strcmp (".ber", &argv[1][ft_strlen(argv[1]) - 4]))
		exit_error (0, &program);
	ft_initialize (&program);
	parsing_map (&program, fd);
	check_component (&program);
	generate_window(&program);
	get_images(&program);
	render_game(&program);
	mlx_hook(program.mlx_win, 2, 1L << 0, moves, &program);
	mlx_hook(program.mlx_win, 17, 0L, destroy, &program);
	mlx_loop(program.mlx);
}
