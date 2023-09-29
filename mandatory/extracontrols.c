/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracontrols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:44:12 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/18 02:44:49 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isnull(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		return (1);
	else
		return (0);
	return (0);
}

void	ifnull(int len, char *a, int c, int d)
{
	if (a == NULL && d == 0)
		errorfunc();
	if (len != (ft_strlen(a) + c) && d == 1)
		errorfunc();
}
