/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:10:20 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 15:50:08 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*ft_malloc(size_t size)
{
	void	*bass;

	bass = malloc(size);
	if (bass == NULL)
	{
		ft_write(2, "Error\n");
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (bass);
}
