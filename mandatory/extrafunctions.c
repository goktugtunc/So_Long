/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:52:33 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/20 16:28:01 by gotunc           ###   ########.fr       */
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

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

void	printstep(void)
{
	static int	i = 0;

	print("Step : ");
	print(ft_itoa(i));
	print("\n");
	i++;
}
