/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafuncs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:58:53 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/17 22:39:36 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	placecoin3(t_mlxlist *mlx, int i, int j, int m)
{
	if (m == 80000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin1, j * 64, i * 64);
	else if (m == 10000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin2, j * 64, i * 64);
	else if (m == 20000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin3, j * 64, i * 64);
	else if (m == 30000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin4, j * 64, i * 64);
	else if (m == 40000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin5, j * 64, i * 64);
	else if (m == 50000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin6, j * 64, i * 64);
	else if (m == 60000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin7, j * 64, i * 64);
	else if (m == 70000)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->coin8, j * 64, i * 64);
}

void	placecoin4(t_mlxlist *mlx, int i, int j, int m)
{
	if (m % 10000 == 0 && m != 0)
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->zero, j * 64, i * 64);
}

void	placecoin2(t_mlxlist *mlx, t_list *data, int m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->maprow)
	{
		while (j < data->mapcolumn)
		{
			if (data->map[i][j] == 'C')
			{
				placecoin4(mlx, i, j, m);
				placecoin3(mlx, i, j, m);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	moveenemy2(t_mlxlist *mlx, t_list *data, int i, int j)
{
	if (data->map[i][j + 2] != '0')
		data->move = 1;
	else
		data->move = 0;
	mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
		mlx->zero, j * 64, i * 64);
	mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
		mlx->enemy, j * 64 + 64, i * 64);
	data->map[i][j] = '0';
	if (i == data->playerrow && (j + 1) == data->playercolumn)
		enemyjob();
	data->map[i][j + 1] = 'N';
}

void	moveenemy1(t_mlxlist *mlx, t_list *data, int i, int j)
{
	if ((data->map[i][j + 1] == '0' && data->move == 0)
		|| (data->map[i][j + 1] == '0' && data->move == 2))
		moveenemy2(mlx, data, i, j);
	else if ((data->map[i][j - 1] == '0' && data->move == 1)
		|| (data->map[i][j - 1] == '0' && data->move == 2))
	{
		if (data->map[i][j - 2] != '0')
			data->move = 0;
		else
			data->move = 1;
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->zero, j * 64, i * 64);
		mlx_put_image_to_window(mlx->mlxinit, mlx->screen,
			mlx->enemy, j * 64 - 64, i * 64);
		data->map[i][j] = '0';
		if (i == data->playerrow && (j - 1) == data->playercolumn)
			enemyjob();
		data->map[i][j - 1] = 'N';
	}
}
