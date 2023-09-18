/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:52:33 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/17 15:02:04 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(char *a)
{
	int	i;

	i = -1;
	while (a[++i])
		write(1, &a[i], 1);
}

void	errorfunc(void)
{
	print("Error!\n");
	exit(-1);
}

void	placecoin(t_mlxlist *mlx)
{
	static int	i = 0;
	static int	j = 0;

	if (i % 10000 == 0 && i != 90000)
		placecoin2(mlx, mlx->data, i);
	else if (i == 90000)
		i = 0;
	i++;
	j = 1;
}

int	animations(t_mlxlist *mlx)
{
	placecoin(mlx);
	moveenemy0(mlx, mlx->data);
	return (0);
}

void	mlximages2(t_mlxlist *mlxdata)
{
	mlxdata->coin1 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin1.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin2 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin2.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin3 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin3.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin4 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin4.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin5 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin5.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin6 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin6.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin7 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin7.xpm", &mlxdata->width, &mlxdata->height);
	mlxdata->coin8 = mlx_xpm_file_to_image(mlxdata->mlxinit,
			"textures/coin8.xpm", &mlxdata->width, &mlxdata->height);
}
