/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:50:11 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/18 02:45:22 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line_bonus.h"
# include "minilibx/mlx.h"

typedef struct s_list{
	char	*mapname;
	char	**map;
	char	**tempmap;
	int		playerrow;
	int		playercolumn;
	int		accessexit;
	int		maprow;
	int		mapcolumn;
	int		collectablecount;
	int		exitcount;
	int		playercount;
	int		enemycount;
	int		move;
}	t_list;

typedef struct s_mlxlist{
	void	*data;
	void	*mlxinit;
	void	*screen;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*coin7;
	void	*coin8;
	void	*manl;
	void	*manr;
	void	*manfront;
	void	*manback;
	void	*enemy;
	void	*one;
	void	*zero;
	void	*exit;
	int		height;
	int		width;
	long	movecounter;
	long	step;
}	t_mlxlist;

void	print(char *a);
void	ishavemap(char *map, t_list *data);
void	errorfunc(void);
void	mapcontrol(t_list *data);
void	accessableexit(t_list *data, int i, int j);
void	accessablemap(t_list *data, int i, int j);
void	tempmapcontrol(t_list *data);
void	findplayer(t_list *data);
void	mlxoperations(t_list *data);
int		ifpressw(t_mlxlist *m, t_list *data);
int		ifpressa(t_mlxlist *m, t_list *data);
int		ifpressd(t_mlxlist *m, t_list *data);
int		ifpresss(t_mlxlist *m, t_list *data);
int		ifpressesc(t_mlxlist *m);
void	drawextras(t_mlxlist *m, t_list *data);
void	drawoneandzero(t_mlxlist *m, t_list *data);
void	mlximages(t_mlxlist *mlxdata);
void	printstep(t_mlxlist *mlx);
void	ifexitandcharacter(t_list *data);
void	enemyjob(void);
char	*ft_itoa(int n);
void	mlximages2(t_mlxlist *mlxdata);
int		animations(t_mlxlist *mlx);
void	placecoin2(t_mlxlist *mlx, t_list *data, int m);
void	moveenemy0(t_mlxlist *mlx, t_list *data);
void	moveenemy1(t_mlxlist *mlx, t_list *data, int i, int j);
int		isnull(char *a);
void	ifnull(int len, char *a, int c, int d);

#endif