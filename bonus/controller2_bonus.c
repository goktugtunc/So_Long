/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:17:12 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/21 13:15:36 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	accessablemap(t_list *data, int i, int j)
{
	data->tempmap[i][j] = '*';
	if (data->tempmap[i - 1][j] != '1' && data->tempmap[i - 1][j] != '*')
		accessablemap(data, i - 1, j);
	if (data->tempmap[i][j + 1] != '1' && data->tempmap[i][j + 1] != '*')
		accessablemap(data, i, j + 1);
	if (data->tempmap[i + 1][j] != '1' && data->tempmap[i + 1][j] != '*')
		accessablemap(data, i + 1, j);
	if (data->tempmap[i][j - 1] != '1' && data->tempmap[i][j - 1] != '*')
		accessablemap(data, i, j - 1);
}

void	tempmapcontrol(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->maprow)
	{
		while (j < data->mapcolumn)
		{
			if (data->tempmap[i][j] == 'C' || data->tempmap[i][j] == 'P'
				|| data->tempmap[i][j] == 'E')
				errorfunc();
			j++;
		}
		j = 0;
		i++;
	}
	data->accessexit = 1;
}

void	findplayer(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->maprow)
	{
		while (j < data->mapcolumn)
		{
			if (data->map[i][j] == 'P')
			{
				data->playerrow = i;
				data->playercolumn = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
