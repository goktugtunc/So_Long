/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:00:56 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/09 16:11:09 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trueextension(char *map)
{
	int	len;

	len = ft_strlen(map) - 1;
	if (map[len] != 'r' && map[len - 1] != 'e' && map[len - 2] != 'b' 
		&& map[len - 3] != '.')
	{
		print("Error!\n");
		exit(-1);
	}
	if (ft_strlen(map) < 5)
	{
		print("Error!\n");
		exit(-1);
	}
}

void	placemap2(t_list *data, int i, int len)
{
	int		row;
	int		column;
	int		fd;
	char	*a;

	row = 0;
	column = 0;
	fd = open(data->mapname, O_RDONLY);
	while (row < i)
	{
		a = get_next_line(fd);
		while (column < len)
		{
			data->map[row][column] = a[column];
			column++;
		}
		column = 0;
		row++;
	}
	data->maprow = i;
	data->mapcolumn = len;
	mapcontrol(data);
}

void	placemap(t_list *data, char *map, int i, int len)
{
	int	m;

	m = 0;
	data = malloc(sizeof(t_list));
	data->mapname = map;
	data->map = malloc(sizeof(char *) * i);
	while (m < i)
	{
		data->map[m] = malloc(sizeof(char) * len - 1);
		m++;
	}
	placemap2(data, i, len - 1);
}

void	copymap(char *map, t_list *data)
{
	int		fd;
	int		len;
	char	*a;
	int		i;

	fd = open(map, O_RDONLY);
	a = get_next_line(fd);
	if (a == 0)
		errorfunc();
	i = 1;
	len = ft_strlen(a);
	while (a != 0)
	{
		a = get_next_line(fd);
		if (a == NULL)
			break ;
		if (len != ft_strlen(a))
			errorfunc();
		i++;
	}
	close(fd);
	placemap(data, map, i, len);
}

void	ishavemap(char *map, t_list *data)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd != 3)
	{
		print("Error!\n");
		exit(-1);
	}
	close(fd);
	trueextension(map);
	copymap(map, data);
}
