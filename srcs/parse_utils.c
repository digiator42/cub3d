/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:25:06 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/03 14:42:32 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_color(const char *str)
{
	int	num;
	int i;
	
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if(num > 255)
			return -1;
	}
	while (str[i] == ' ')
		++str;
	if (str[i] != '\0' && str[i] != ',' && str[i] != '\n')
		put_error("Not valid colors");
	return (num);
}

int	cur_index(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		++i;
	return (i);
}

void	put_error(const char *error)
{
	write(2, "ERROR\n", ft_strlen("ERROR\n"));
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(1);
}

void print_map(t_map *map, t_player *pos)
{
	int i;

	i = 0;
	printf("py == %lf\n", pos->py);
	printf("px == %lf\n", pos->px);
	printf("pa == %lf\n", pos->pa);
	while(map->map[i])
		ft_printf("{%s}\n", map->map[i++]);
}

int	check_surface(const char *line)
{
	int i;
	char c;

	i = 0;
	c = line[i];
	while(line[i] && line[i] != '\n')
		i++;
	i++;	
	i += cur_index(&line[i], c);
	if(line[i] == c)
		put_error("Duplicate Sides");	
	if (ft_strncmp(line, "F ", 2) == 0)
		return (E_FLOOR);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (E_CEIL);
	put_error("Not valid color side");
	return (-1);
}