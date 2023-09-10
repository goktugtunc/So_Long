/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:50:11 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/09 16:02:53 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_list{
	char	*mapname;
	char	**map;
	int		maprow;
	int		mapcolumn;
	int		collectablecount;
	int		exitcount;
	int		playercount;
}	t_list;

void	print(char *a);
void	ishavemap(char *map, t_list *data);
void	errorfunc(void);
void	mapcontrol(t_list *data);

#endif