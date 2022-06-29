/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:47:40 by aboudoun          #+#    #+#             */
/*   Updated: 2022/03/22 15:34:44 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = (unsigned char)c;
	return (b);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, size * count);
	return (p);
}

void	ft_initialize(t_program *program)
{
	program->moves = 0;
	program->map.column = 0;
	program->map.row = 0;
	program->map.map = ft_calloc(sizeof(char *), 1);
	if (!program->map.map)
		exit_error(2, program);
	program->map.collectible = 0;
	program->map.exit = 0;
	program->player.position = 0;
	program->player.x = 0;
	program->player.y = 0;
	program->img.player_down = NULL;
	program->img.player_up = NULL;
	program->img.player_left = NULL;
	program->img.player_right = NULL;
	program->img.collect = NULL;
	program->img.exit_no = NULL;
	program->img.exit_yes = NULL;
	program->img.floor = NULL;
	program->img.wall = NULL;
}

void	generate_window(t_program *program)
{	
	program->mlx = mlx_init();
	if (!(program->mlx))
		exit_error(3, program);
	program->mlx_win = mlx_new_window(program->mlx, program->map.row * WIDTH,
			program->map.column * HEIGHT, "so_long_bonus");
}
