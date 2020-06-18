/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:00:47 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 22:01:17 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cnt;

	cnt = 0;
	while (len && src[cnt])
	{
		dst[cnt] = src[cnt];
		cnt++;
		len--;
	}
	while (len)
	{
		dst[cnt] = '\0';
		cnt++;
		len--;
	}
	return (dst);
}
