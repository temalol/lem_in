/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:21:53 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/06 03:31:09 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*gnl(char *text)
{
	static int i; // Static переменная для сохранения индекса между запусками функции
	int b;
	
	b = 0; 
	if ((i == 0 && (!text[0])) || (i < 0))
		return NULL;
	if (i > 0) // Тут возвращаем \n на место после предыдущего запуска функции
	{
		text[i] = '\n'; 
		text = &text[i + 1]; // Двигаем указатель на +1 символ
		i += 1; 
	}
	if (!text[0]) // После сдвига указателя проверить, не является ли это концом строки
		return NULL;
	while(text[b] != '\n' && text[b]) // Двигаем указатель до ближайшего \n или \0
	{
		b += 1;
		i += 1;
	}
		if (!text[b]) // Если в предыдущем цикле дошли до \0, это означает, что строка закончилась, в следующий запуск функция должна вернуть NULL
			i = -1; 
	text[b] = '\0';
 	return (text);
}

char	*enlarge_buffer(char *old_buf, size_t *mem_buf)
{
	char *new_buf;

	*mem_buf = *mem_buf * 2; // Увеличиваем размер буфера в 2 раза
	MFAIL((new_buf = malloc(sizeof(char) * *mem_buf)));
	new_buf[0] = 0;
	ft_strcat(new_buf,old_buf); // Копируем из старого в новый
	FCNT(free(old_buf)); // Удаляем старый
	return(new_buf);
}

char 	*read_to_str(fd)
{
	char read_buf[1001];
	char *buf;
 	int ret; 
	size_t buf_s = 0; // Переменная для хранения размера заполненности буфера
	size_t mem_buf = 5000; // Стартовый буфер в 5000 байт
	
	MFAIL((buf = malloc(sizeof(char) * mem_buf)));
	buf[0] = '\0';
	while ((ret = read(fd, read_buf, 1000)) > 0)
	{
		if (buf_s + ret >= mem_buf) // Тут проверяем, требуется ли увелечение буфера.
			buf = enlarge_buffer(buf,&mem_buf);
		read_buf[ret] = '\0';
	  	ft_strcat(buf, read_buf);
		buf_s += 1000; // Увеличиваем размер заполненности буфера
	}
	return (buf);
 }