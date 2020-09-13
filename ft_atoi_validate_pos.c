/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_validate_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 23:49:12 by nmustach          #+#    #+#             */
/*   Updated: 2020/09/14 01:37:50 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_atoi_validate_pos(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!str[i])
		return (-1);
	while (str[i])
		if (ft_isdigit(str[i]))
			num = num * 10 + (str[i++] - '0');
		else
			return (-1);
	return (num);
}
