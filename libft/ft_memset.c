/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:19:02 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/12 19:31:14 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char*)b;
	while (len)
	{
		ptr[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
