/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_file_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:22:14 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 14:40:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*ft_xpm_file_to_image(void *mlx_ptr, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, path, w, h);
	if (img == NULL)
	{
		printf("Error\n");
		printf("mlx_xpm_file_to_image: %s not exist\n", path);
		exit(EXIT_FAILURE);
	}
	return (img);
}
