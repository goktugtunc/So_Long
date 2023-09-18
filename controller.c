/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:00:56 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/18 14:19:34 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trueextension(char *map)
{
	int	len;

	len = ft_strlen(map) - 1;
	if (map[len] != 'r' || map[len - 1] != 'e' || map[len - 2] != 'b'
		|| map[len - 3] != '.')
		errorfunc();
	if (map[len - 4] == '/' || ft_strlen(map) < 5)
		errorfunc();
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
	while (row <= i)
	{
		a = get_next_line(fd);
		while (column <= len)
		{
			data->map[row][column] = a[column];
			data->tempmap[row][column] = a[column];
			column++;
		}
		free(a);
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
	if (len > 41 || i > 21)
		errorfunc();
	data->mapname = map;
	data->map = malloc(sizeof(char *) * (i + 1));
	data->tempmap = malloc(sizeof(char *) * (i + 1));
	while (m <= i)
	{
		data->map[m] = malloc(sizeof(char) * len);
		data->tempmap[m] = malloc(sizeof(char) * len);
		m++;
	}
	placemap2(data, i, len);
}

void	copymap(char *map, t_list *data)
{
	int			fd;
	int			len;
	char		*a;
	static int	i = 1;
	static int	c = 0;

	fd = open(map, O_RDONLY);
	a = get_next_line(fd);
	ifnull(0, a, 0, 0);
	len = ft_strlen(a);
	while (a != NULL)
	{
		free(a);
		a = get_next_line(fd);
		ifnull(0, a, 0, 0);
		if (isnull(a) == 0)
			c = 1;
		ifnull(len, a, c, 1);
		i++;
		if (isnull(a) == 0)
			break ;
	}
	free(a);
	close(fd);
	placemap(data, map, i - 1, len - 2);
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
	findplayer(data);
	accessablemap(data, data->playerrow, data->playercolumn);
	tempmapcontrol(data);
	data->accessexit = 0;
	accessableexit(data, data->playerrow, data->playercolumn);
	if (data->accessexit != 1)
		errorfunc();
}
