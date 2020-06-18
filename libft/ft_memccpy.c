/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:31:48 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/14 21:35:22 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	char	*s;
	char	*d;
	int		cnt;
	char	occ;

	cnt = 0;
	s = (char*)(src);
	d = (char*)(dst);
	occ = (unsigned char)(c);
	while (n)
	{
		if (occ == s[cnt])
		{
			d[cnt] = s[cnt];
			cnt++;
			return (dst + cnt);
		}
		d[cnt] = s[cnt];
		n--;
		cnt++;
	}
	return (NULL);
}
