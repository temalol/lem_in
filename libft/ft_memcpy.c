/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:33:59 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 21:41:01 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int		cnt;
	char	*d;
	char	*s;

	cnt = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char*)(dst);
	s = (char*)(src);
	while (n)
	{
		d[cnt] = s[cnt];
		cnt++;
		n--;
	}
	return (dst);
}
