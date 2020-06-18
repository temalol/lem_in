/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:42:15 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 21:44:05 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	occ;
	int		cnt;

	cnt = 0;
	str = (char*)(s);
	occ = (unsigned char)(c);
	while (n)
	{
		if (str[cnt] == occ)
			return (str + cnt);
		cnt++;
		n--;
	}
	return (NULL);
}
