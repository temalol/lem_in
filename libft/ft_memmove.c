/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:03:57 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/19 16:20:25 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = (unsigned char*)(dst);
	s = (unsigned char*)(src);
	if (src < dst)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	while (len--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
