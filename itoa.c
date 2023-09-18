/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:18:53 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/16 21:20:19 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	numberlen(int n)
{
	long	a;
	int		i;

	i = 0;
	a = n;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	putstring(char *string, int a, int numlen)
{
	long	n;

	n = a;
	if (n < 0)
	{
		string[0] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		putstring(string, n / 10, numlen - 1);
		putstring(string, n % 10, numlen);
	}
	if (n < 10)
		string[numlen] = n + 48;
}

char	*ft_itoa(int n)
{
	int		numlen;
	char	*string;

	numlen = numberlen(n);
	string = malloc((sizeof(char) * numlen) + 1);
	if (!string)
		return (0);
	putstring(string, n, numlen - 1);
	string[numlen] = '\0';
	return (string);
}
