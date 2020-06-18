/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:58:00 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/19 15:50:37 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getend(char const *s)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	len--;
	while ((s[len] == ' ') || (s[len] == '\n') || (s[len] == '\t'))
		len--;
	return (len + 1);
}

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		n;
	char		*new;
	size_t		stind;
	size_t		endind;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = 0;
	stind = 0;
	endind = getend(s);
	if (endind == 0)
		return (ft_strdup("\0"));
	while ((s[stind] == ' ') || (s[stind] == '\n') || (s[stind] == '\t'))
		stind++;
	new = (char*)malloc((1 + (endind - stind)) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (stind < endind)
		new[n++] = s[stind++];
	new[n] = '\0';
	return (new);
}
