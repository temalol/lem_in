/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:19:16 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/24 23:03:25 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);
int	validate(char **tmp, char **line, int fd);

# define MFAIL(x) if (!x) return (-1);
# define BUFF_SIZE 2000
#endif
