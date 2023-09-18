/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:57:56 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/17 22:40:05 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

void	clearcount(t_mlxlist *mlx)
{
	mlx_put_image_to_window(mlx->mlxinit, mlx->screen, mlx->one, 0, 0);
	mlx_put_image_to_window(mlx->mlxinit, mlx->screen, mlx->one, 64, 0);
}

void	printstep(t_mlxlist *mlx)
{
	static int	i = 0;
	char		*a;

	clearcount(mlx);
	a = ft_itoa(i);
	mlx_string_put(mlx->mlxinit, mlx->screen, 5, 20, 0xf5fffa, "step: ");
	mlx_string_put(mlx->mlxinit, mlx->screen, 64, 20, 0xf5fffa, a);
	free(a);
	i++;
}

void	enemyjob(void)
{
	print("Oh, no! Game Over...\n");
	exit(0);
}

void	moveenemy0(t_mlxlist *mlx, t_list *data)
{
	static int	m = 0;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (m % 10000 == 0 && m != 90000 && m != 0)
	{
		while (++i < data->maprow)
		{
			while (j < data->mapcolumn)
			{
				if (data->map[i][j] == 'N')
				{
					moveenemy1(mlx, data, i, j);
					j++;
				}
				j++;
			}
			j = 0;
		}
	}
	else if (m == 90000)
		m = 0;
	m++;
}
