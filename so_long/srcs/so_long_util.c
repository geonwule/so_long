/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:38:42 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/17 19:53:17 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_error(void)
{
	write(2, "dynamic allocation Error\n", 25);
	exit(1);
}

static int	digit_check(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static void	insert_int(char *ret, int n, int len)
{
	len--;
	while (len >= 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

static char	*ft_strdup_so(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(const char) * ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		ret_len;

	if (n == -2147483648)
	{
		ret = ft_strdup_so("-2147483648");
		return (ret);
	}
	if (n < 0)
		ret_len = digit_check(-n) + 1;
	else
		ret_len = digit_check(n);
	ret = (char *)malloc(sizeof(char) * ret_len + 1);
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		insert_int(ret + 1, -n, ret_len - 1);
	}
	else
		insert_int(ret, n, ret_len);
	return (ret);
}
