/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:08:54 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/14 22:11:09 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	size_t	i;
	size_t	j;
	size_t	nlen;

	i = 0;
	j = 0;
	hay = (char*)(haystack);
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return (hay);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (hay + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
