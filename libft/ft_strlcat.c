/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:59:33 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/14 22:01:38 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	int		cnt;
	size_t	dstlen;
	size_t	srclen;
	int		rem;
	size_t	saved;

	cnt = 0;
	dstlen = 0;
	srclen = 0;
	saved = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size == 0 || size <= dstlen)
		return (srclen + size);
	saved = dstlen;
	rem = size - dstlen - 1;
	while (rem-- && src[cnt])
	{
		dst[dstlen++] = src[cnt++];
	}
	dst[dstlen] = '\0';
	return (saved + srclen);
}
