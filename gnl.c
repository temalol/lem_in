/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:21:53 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/27 18:20:59 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*gnl(char *text)
{
	static int i;
	
	if (i == 0 && (!text[0]))
		return NULL;
	if (i < 0)
		return NULL;
	if (i > 0)
	{
		text[i] = '\n';
		text = &text[i + 1];
		i += 1;
	}
	
	int b = 0;
	if (!text[0])
		return NULL;
	while(text[b] != '\n' && text[b])
	{
		b += 1;
		i += 1;
	}
		if (!text[b])
	{
			i = -1;
			return text;
	}
	text[b] = 0;
 	return (text);
}

char 	*read_to_str(fd)
{
	 char read_buf[1001];
	 char *buf;
	int ret;
	
	buf = malloc((sizeof(char) * 100000));
	
	while ((ret = read(fd, read_buf, 1000)) > 0)
	{
		read_buf[ret] = '\0';
		ft_strcat(buf, read_buf);
	}
	return (buf);
 }