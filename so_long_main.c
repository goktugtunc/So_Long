/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:49:58 by gotunc            #+#    #+#             */
/*   Updated: 2023/09/09 15:12:46 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	*data;

	if (argc == 2)
	{
		data = NULL;
		ishavemap(argv[1], data);
	}
	else
		print("Error!\n");
	return (0);
}
