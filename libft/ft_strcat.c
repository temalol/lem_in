/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:04:08 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 22:13:17 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*str2;
	int		cnt;
	int		len;

	cnt = 0;
	len = 0;
	str2 = (char*)(s2);
	while (s1[len])
		len++;
	while (str2[cnt])
	{
		s1[len] = str2[cnt];
		len++;
		cnt++;
	}
	s1[len] = '\0';
	return (s1);
}
