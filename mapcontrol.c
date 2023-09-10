/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:51:27 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/09 16:16:02 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charcontrol(t_list *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		data->playercount++;
	else if (data->map[i][j] == 'E')
		data->exitcount++;
	else if (data->map[i][j] == 'C')
		data->collectablecount++;
	else if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i][j] != '\n' && data->map[i][j] != '\0')
		errorfunc();
}

void	mapcontrol2(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->maprow)
	{
		if (data->map[i][0] != '1' || data->map[i][data->mapcolumn - 1] != '1')
			errorfunc();
		while (j < data->mapcolumn)
		{
			if (data->map[0][j] != '1' || data->map[data->maprow - 1][j] != '1')
				errorfunc();
			j++;
		}
		j = 0;
		i++;
	}
}

void	mapcontrol(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->collectablecount = 0;
	data->exitcount = 0;
	data->playercount = 0;
	mapcontrol2(data);
	while (i < data->maprow)
	{
		while (j < data->mapcolumn)
		{
			charcontrol(data, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (data->playercount != 1 || data->collectablecount < 1 
		|| data->exitcount != 1)
		errorfunc();
}
