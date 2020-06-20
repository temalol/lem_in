/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:28:00 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/20 16:12:43 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
	#define LEM_IN_H


# define TABLE_SIZE 100


typedef struct s_hash
{
	char *node_name;
	int x;
	int y;
	struct s_hash *next;
	
} t_hash;


# include "get_next_line.h"
# include <stdio.h>
//# include "./libft/libft.h"

int					parse_input();
int					ft_atoi_validate_pos(const char *str);
unsigned int		calc_hash(char *str);
t_hash 				**hash_table_init();
void				err_exit();
void				assign_to_table(t_hash **table, char *node_name);
void				print_hash_table(t_hash **h_table);




#endif