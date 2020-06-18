/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:11:49 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/21 19:06:24 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	size_t	i;
	size_t	j;
	size_t	nlen;
	size_t	n;

	n = 0;
	i = 0;
	j = 0;
	hay = (char*)(haystack);
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return (hay);
	while (n++ < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && j + i < len)
		{
			if (needle[j + 1] == '\0')
				return (hay + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
