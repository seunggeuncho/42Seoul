/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seucho <seucho@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:18:09 by seucho            #+#    #+#             */
/*   Updated: 2021/10/13 17:09:54 by seucho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	ft_print_numbers(void)
{
	char	buff;

	buff = '0';
	while (buff <= '9')
	{
		write(1, &buff, 1);
		buff++;
	}
}
