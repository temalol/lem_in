/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:32:37 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/19 17:43:12 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fillstr(char const *s1, char const *s2, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1len;
	int		s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char*)malloc((1 + s1len + s2len) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[s1len + s2len] = '\0';
	fillstr(s1, s2, new);
	return (new);
}
