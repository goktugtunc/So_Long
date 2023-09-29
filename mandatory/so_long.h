/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:50:11 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/30 00:19:08 by gotunc           ###   ########.fr       */
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
# include "../minilibx/mlx.h"

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
	int		move;
}	t_list;

typedef struct s_mlxlist{
	void	*data;
	void	*mlxinit;
	void	*screen;
	void	*coin1;
	void	*manl;
	void	*manr;
	void	*manfront;
	void	*manback;
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
void	printstep(void);
void	ifexitandcharacter(t_list *data);
char	*ft_itoa(int n);
int		isnull(char *a);
void	ifnull(int len, char *a, int c, int d);

#endif