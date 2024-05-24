/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_file_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:22:14 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 15:50:59 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*ft_xpm_file_to_image(void *mlx_ptr, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, path, w, h);
	if (img == NULL)
	{
		ft_write(2, "Error\n");
		ft_write(2, "mlx_xpm_file_to_image: ");
		ft_write(2, path);
		ft_write(2, "not exist\n");
		exit(EXIT_FAILURE);
	}
	return (img);
}
