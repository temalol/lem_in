/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:21:53 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/28 20:35:51 by nmustach         ###   ########.fr       */
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
	int buf_s = 0;
	int mem_buf = 5000;
	
	MFAIL((buf = (char*)malloc(sizeof(char) * mem_buf)));
	
	buf[0] = 0;
		
	while ((ret = read(fd, read_buf, 1000)) > 0)
	{
		if (buf_s + ret >= mem_buf)
			{
			mem_buf = mem_buf * 2;
			char *new;
			MFAIL((new = (char*)malloc(sizeof(char) * mem_buf)));
				new[0] = 0;
				ft_strcat(new,buf);
				FCNT(free(buf));
				buf = new;
			}
		read_buf[ret] = '\0';
	  	ft_strcat(buf, read_buf);
		buf_s += 1000;
	}
	return (buf);
 }