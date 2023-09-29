/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpressfunc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:02 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/20 16:25:09 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ifpressw(t_mlxlist *m, t_list *data)
{
	if (data->map[data->playerrow - 1][data->playercolumn] != '1')
	{
		if ((data->map[data->playerrow - 1][data->playercolumn] == 'E'
			&& data->collectablecount == 0) ||
			(data->map[data->playerrow - 1][data->playercolumn] != 'E'))
		{
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64, data->playerrow * 64);
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64, data->playerrow * 64 - 64);
			mlx_put_image_to_window(m, m->screen, m->manback,
				data->playercolumn * 64, data->playerrow * 64 - 64);
			data->playerrow--;
			printstep(m);
			if (data->map[data->playerrow][data->playercolumn] == 'N')
				enemyjob();
			if (data->map[data->playerrow][data->playercolumn] == 'C')
			{
				data->collectablecount--;
				data->map[data->playerrow][data->playercolumn] = '0';
			}
			ifexitandcharacter(data);
		}
	}
	return (0);
}

int	ifpressa(t_mlxlist *m, t_list *data)
{
	if (data->map[data->playerrow][data->playercolumn - 1] != '1')
	{
		if ((data->map[data->playerrow][data->playercolumn - 1] == 'E'
			&& data->collectablecount == 0) ||
			(data->map[data->playerrow][data->playercolumn - 1] != 'E'))
		{
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64 - 64, data->playerrow * 64);
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64, data->playerrow * 64);
			mlx_put_image_to_window(m, m->screen, m->manl,
				data->playercolumn * 64 - 64, data->playerrow * 64);
			data->playercolumn--;
			printstep(m);
			if (data->map[data->playerrow][data->playercolumn] == 'N')
				enemyjob();
			if (data->map[data->playerrow][data->playercolumn] == 'C')
			{
				data->collectablecount--;
				data->map[data->playerrow][data->playercolumn] = '0';
			}
			ifexitandcharacter(data);
		}
	}
	return (0);
}

int	ifpressd(t_mlxlist *m, t_list *data)
{
	if (data->map[data->playerrow][data->playercolumn + 1] != '1')
	{
		if ((data->map[data->playerrow][data->playercolumn + 1] == 'E'
			&& data->collectablecount == 0) ||
			(data->map[data->playerrow][data->playercolumn + 1] != 'E'))
		{
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64 + 64, data->playerrow * 64);
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64, data->playerrow * 64);
			mlx_put_image_to_window(m, m->screen, m->manr,
				data->playercolumn * 64 + 64, data->playerrow * 64);
			data->playercolumn++;
			printstep(m);
			if (data->map[data->playerrow][data->playercolumn] == 'N')
				enemyjob();
			if (data->map[data->playerrow][data->playercolumn] == 'C')
			{
				data->collectablecount--;
				data->map[data->playerrow][data->playercolumn] = '0';
			}
			ifexitandcharacter(data);
		}
	}
	return (0);
}

int	ifpresss(t_mlxlist *m, t_list *data)
{
	if (data->map[data->playerrow + 1][data->playercolumn] != '1')
	{
		if ((data->map[data->playerrow + 1][data->playercolumn] == 'E'
			&& data->collectablecount == 0) ||
			(data->map[data->playerrow + 1][data->playercolumn] != 'E'))
		{
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64, data->playerrow * 64 + 64);
			mlx_put_image_to_window(m, m->screen, m->zero,
				data->playercolumn * 64, data->playerrow * 64);
			mlx_put_image_to_window(m, m->screen, m->manfront,
				data->playercolumn * 64, data->playerrow * 64 + 64);
			data->playerrow++;
			printstep(m);
			if (data->map[data->playerrow][data->playercolumn] == 'N')
				enemyjob();
			if (data->map[data->playerrow][data->playercolumn] == 'C')
			{
				data->collectablecount--;
				data->map[data->playerrow][data->playercolumn] = '0';
			}
			ifexitandcharacter(data);
		}
	}
	return (0);
}

int	ifpressesc(t_mlxlist *m)
{
	mlx_destroy_image(m->mlxinit, m->zero);
	mlx_destroy_image(m->mlxinit, m->coin1);
	mlx_destroy_image(m->mlxinit, m->coin2);
	mlx_destroy_image(m->mlxinit, m->coin3);
	mlx_destroy_image(m->mlxinit, m->coin4);
	mlx_destroy_image(m->mlxinit, m->coin5);
	mlx_destroy_image(m->mlxinit, m->coin6);
	mlx_destroy_image(m->mlxinit, m->coin7);
	mlx_destroy_image(m->mlxinit, m->coin8);
	mlx_destroy_image(m->mlxinit, m->exit);
	mlx_destroy_image(m->mlxinit, m->manback);
	mlx_destroy_image(m->mlxinit, m->manfront);
	mlx_destroy_image(m->mlxinit, m->manl);
	mlx_destroy_image(m->mlxinit, m->manr);
	mlx_destroy_image(m->mlxinit, m->enemy);
	mlx_destroy_image(m->mlxinit, m->one);
	mlx_destroy_window(m->mlxinit, m->screen);
	print("Game ended!\n");
	exit(0);
}
