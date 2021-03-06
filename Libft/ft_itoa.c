/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seucho <seucho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:05:06 by seucho            #+#    #+#             */
/*   Updated: 2022/01/05 23:44:04 by seucho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_num(int n)
{
	if (n == 0)
		return (0);
	while (n != 0)
		return (1 + cnt_num(n / 10));
	return (0);
}

static void	get_num(int *sign, long *i, int *num)
{
	if (*i == 0)
		*num = 1;
	else if (*i < 0)
	{
		*sign = -1;
		*i *= -1;
		*num = cnt_num(*i) + 1;
	}
	else
		*num = cnt_num(*i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		num;
	int		sign;
	long	i;

	i = n;
	sign = 1;
	get_num(&sign, &i, &num);
	ret = (char *)malloc(num + 1);
	if (ret == NULL)
		return (0);
	ret[num] = 0;
	num--;
	while (num >= 0)
	{
		ret[num] = '0' + i % 10;
		i /= 10;
		num--;
	}
	if (sign == -1)
		ret[num + 1] = '-';
	return (ret);
}
