/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:19:00 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 14:40:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_get_data_addr(void *img_ptr, int *bits, int *size, int *end)
{
	char	*data;

	data = mlx_get_data_addr(img_ptr, bits, size, end);
	if (data == NULL)
	{
		printf("Error\n");
		printf("mlx_get_data_addr: img_ptr not exist\n");
		exit(EXIT_FAILURE);
	}
	return (data);
}
