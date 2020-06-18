/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:14:06 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 22:18:21 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int len;
	int cnt;

	len = 0;
	cnt = 0;
	len = ft_strlen(s1);
	while (n && s2[cnt])
	{
		s1[len] = s2[cnt];
		len++;
		cnt++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
