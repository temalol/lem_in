/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:44:58 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 21:47:07 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*str1;
	unsigned char	*str2;

	cnt = 0;
	str1 = (unsigned char*)(s1);
	str2 = (unsigned char*)(s2);
	while (n)
	{
		if (str1[cnt] != str2[cnt])
			return (str1[cnt] - str2[cnt]);
		n--;
		cnt++;
	}
	return (0);
}
