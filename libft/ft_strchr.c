/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:02:30 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/14 22:04:28 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	occ;
	char	*src;
	int		cnt;

	cnt = 0;
	occ = (char)(c);
	src = (char*)(s);
	while (src[cnt])
	{
		if (src[cnt] == occ)
			return (src + cnt);
		cnt++;
	}
	if (occ == '\0')
		return (src + cnt);
	return (NULL);
}
