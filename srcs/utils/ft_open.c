/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:12:38 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:17 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_open(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY, 0600);
	if (fd < 0)
	{
		ft_write(2, "Error\n");
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
