/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:34:34 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/19 14:46:10 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillarray(char *str, int len, int n)
{
	int flag;
	int	b;

	if (n < 0)
	{
		n = n * (-1);
		flag = 1;
	}
	while (n > 0)
	{
		b = n % 10;
		str[--len] = b + '0';
		n = n / 10;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}

static char	*zero_case(void)
{
	char	*str;

	str = ft_strdup("0");
	return (str);
}

static char	*min_int(void)
{
	char	*str;

	str = ft_strdup("-2147483648");
	return (str);
}

static	int	count_numbers(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n = n * (-1);
	}
	while (n >= 10)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt + 1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (min_int());
	if (n == 0)
		return (zero_case());
	len = count_numbers(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (fillarray(str, len, n));
}
