/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:47:09 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/22 19:47:38 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		freemem(char **col, size_t colcnt)
{
	if (colcnt > 0)
		colcnt--;
	while (colcnt != (size_t)(-1))
	{
		free(col[colcnt]);
		colcnt--;
	}
}

static size_t		rowfill(char **col, const char *s, int i, char c)
{
	char	*row;
	size_t	rowind;
	size_t	wlen;
	size_t	fillind;

	wlen = 0;
	rowind = 0;
	while (s[i] == c)
		i++;
	if (s[i] != c)
		fillind = i;
	while (s[i] != c && s[i])
	{
		i++;
		wlen++;
	}
	row = (char*)malloc((1 + wlen) * sizeof(char));
	if (row == NULL)
		return (-1);
	while (wlen--)
		row[rowind++] = s[fillind++];
	row[rowind] = '\0';
	*col = row;
	return (i);
}

static int			wc(const char *s, char c)
{
	size_t i;
	size_t wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			wc++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (wc);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	wordsnum;
	size_t	colcnt;
	size_t	wordind;
	char	**col;

	if (s == NULL)
		return (NULL);
	colcnt = 0;
	wordind = 0;
	wordsnum = wc(s, c);
	if (!(col = (char**)malloc((1 + wordsnum) * sizeof(char*))))
		return (NULL);
	while (wordsnum--)
	{
		wordind = rowfill(&col[colcnt], s, wordind, c);
		if (wordind == (size_t)(-1))
		{
			freemem(col, colcnt);
			free(col);
			return (NULL);
		}
		colcnt++;
	}
	col[colcnt] = NULL;
	return (col);
}
