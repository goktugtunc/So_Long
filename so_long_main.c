/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:49:58 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/12 16:10:16 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_list));
		ishavemap(argv[1], data);
	}
	else
		errorfunc();
	return (0);
}
