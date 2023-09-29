/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:24:24 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/21 13:09:42 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode(int code, t_mlxlist *mlxdata)
{
	if (code == 13)
		ifpressw(mlxdata, mlxdata->data);
	else if (code == 1)
		ifpresss(mlxdata, mlxdata->data);
	else if (code == 2)
		ifpressd(mlxdata, mlxdata->data);
	else if (code == 0)
		ifpressa(mlxdata, mlxdata->data);
	else if (code == 53 || code == 17)
		ifpressesc(mlxdata);
	return (0);
}

void	drawmap(t_mlxlist *mlxdata, t_list *data)
{
	drawoneandzero(mlxdata, data);
	drawextras(mlxdata, data);
}

void	mlxinitialize(t_mlxlist *mlxdata, t_list *data)
{
	mlxdata->mlxinit = mlx_init();
	mlxdata->screen = mlx_new_window(mlxdata->mlxinit,
			(data->mapcolumn + 1) * 64, (data->maprow + 1) * 64,
			"Ali Cabbar Game");
}

void	mlxoperations(t_list *data)
{
	t_mlxlist	*mlxdata;

	mlxdata = malloc(sizeof(t_mlxlist));
	mlxinitialize(mlxdata, data);
	mlximages(mlxdata);
	drawmap(mlxdata, data);
	printstep();
	mlxdata->data = data;
	mlx_hook(mlxdata->screen, 2, 0, keycode, mlxdata);
	mlx_hook(mlxdata->screen, 17, 0, ifpressesc, mlxdata);
	mlx_loop(mlxdata->mlxinit);
}

void	ifexitandcharacter(t_list *data)
{
	if (data->map[data->playerrow][data->playercolumn] == 'E'
		&& data->collectablecount == 0)
	{
		print("Well Done! Happy ending!\n");
		exit(0);
	}
}
