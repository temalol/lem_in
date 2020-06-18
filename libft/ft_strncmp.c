/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:16:39 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/14 22:18:54 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*str1;
	unsigned char	*str2;

	cnt = 0;
	str1 = (unsigned char*)(s1);
	str2 = (unsigned char*)(s2);
	while (n--)
	{
		if (str1[cnt] == str2[cnt] && str1[cnt] && str2[cnt])
			cnt++;
		else
			return (str1[cnt] - str2[cnt]);
	}
	return (0);
}
