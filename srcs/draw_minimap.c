/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:00:59 by mfirdous          #+#    #+#             */
/*   Updated: 2023/05/01 22:38:15 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_fov(t_mlx *m)
{
	int	ray_no;

	ray_no = -1;
	while (++ray_no < WIN_WIDTH)
		dda(m, (t_point){m->p->px, m->p->py},
			(t_point){m->rays[ray_no].x, m->rays[ray_no].y}, TEAL);
}

void	draw_minimap(t_mlx *m)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	i = -1;
	color = GRAY;
	while (++i < m->map->map_height)
	{
		j = -1;
		while (++j < m->map->map_width)
		{
			x = j * MM_SIZE;
			y = i * MM_SIZE;
			if (m->map->map[i][j] == '1')
				color = WHITE;
			draw_square(m, (t_point){x, y}, MM_SIZE, color);
			color = GRAY;
		}
	}
	draw_square(m, (t_point){m->p->px, m->p->py}, 3, GREEN);
	draw_fov(m);
}
