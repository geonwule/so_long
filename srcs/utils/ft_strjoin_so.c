/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_so.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:32:13 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 14:40:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strjoin_so(char const *s1, char const *s2)
{
	char	*map;
	int		s1_len;
	int		s2_len;
	int		i[2];

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2[s2_len - 1] == '\n')
		s2_len -= 1;
	map = (char *)ft_malloc(sizeof(char) * (s1_len + s2_len + 1));
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < s1_len)
		map[i[0]] = s1[i[0]];
	while (++i[1] < s2_len)
		map[i[0] + i[1]] = s2[i[1]];
	map[s1_len + s2_len] = '\0';
	if (s1 != NULL)
		free((void *)s1);
	return (map);
}
