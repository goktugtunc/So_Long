/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxoperators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:21:34 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/18 14:22:00 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	drawextras(t_mlxlist *m, t_list *data)
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
				mlx_put_image_to_window(m, m->screen, m->manr, j * 64, i * 64);
				data->map[i][j] = '0';
			}
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(m, m->screen, m->exit, j * 64, i * 64);
			if (data->map[i][j] == 'N')
				mlx_put_image_to_window(m, m->screen, m->enemy, j * 64, i * 64);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(m, m->screen, m->coin1, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

void	drawoneandzero(t_mlxlist *m, t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->maprow)
	{
		while (j <= data->mapcolumn)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(m, m->screen, m->one, j * 64, i * 64);
			else
				mlx_put_image_to_window(m, m->screen, m->zero, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

void	mlximages(t_mlxlist *mlxdata)
{
	mlxdata->zero = mlx_xpm_file_to_image(mlxdata->mlxinit, "textures/back.xpm",
			&mlxdata->width, &mlxdata->height);
	mlxdata->one = mlx_xpm_file_to_image(mlxdata->mlxinit, "textures/wall.xpm",
			&mlxdata->width, &mlxdata->height);
	mlxdata->manl = mlx_xpm_file_to_image(mlxdata->mlxinit, "textures/manl.xpm",
			&mlxdata->width, &mlxdata->height);
	mlxdata->manr = mlx_xpm_file_to_image(mlxdata->mlxinit, "textures/manr.xpm",
			&mlxdata->width, &mlxdata->height);
	mlxdata->exit = mlx_xpm_file_to_image(mlxdata->mlxinit, "textures/exit.xpm",
			&mlxdata->width, &mlxdata->height);
	mlxdata->manfront = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/manf.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->manback = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/manb.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->enemy = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/enemy.xpm", &mlxdata->width, &mlxdata->height);
	mlximages2(mlxdata);
}
