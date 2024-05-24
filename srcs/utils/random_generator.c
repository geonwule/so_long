/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:03:07 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 14:40:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	random_generator(int frequency)
{
	struct timeval		tv;
	unsigned long long	milliseconds;
	int					ret;

	gettimeofday(&tv, NULL);
	milliseconds = (unsigned long long)(tv.tv_usec);
	srand((unsigned int)milliseconds);
	ret = rand();
	if (ret % frequency == 0)
		return (1);
	return (0);
}
