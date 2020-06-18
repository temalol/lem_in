/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:05:30 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/14 22:07:38 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	char	occ;
	int		len;

	len = 0;
	len = ft_strlen(s);
	occ = (char)(c);
	src = (char*)(s);
	while (len >= 0)
	{
		if (src[len] == occ)
			return (src + len);
		len--;
	}
	return (NULL);
}
