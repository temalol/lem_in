/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:28:00 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/21 17:58:32 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
	#define LEM_IN_H

# define TABLE_SIZE 10000
# define HASH_MULT 37

typedef struct s_hash
{
	char *node_name;
	int x;
	int y;
	struct s_hash *next;
	struct s_hash *ver;
	
	
} t_hash;

typedef struct s_graph
{
	t_hash **h_table;
	t_hash *start;
	t_hash *end;
	int ants_num;
	
} t_graph ;

# include "get_next_line.h"
# include <stdio.h>


/*
** -------------------------- Hash table functions --------------------------------
*/

t_hash				*hash_query(t_hash **h_table, char *node_name);
unsigned int		calc_hash(char *str);
t_hash 				**hash_table_init();
void				err_exit();
t_hash				*assign_to_table(t_hash **table, char *node_name);
void				print_hash_table(t_hash **h_table);
void				free_hash_table(t_hash **h_table);

/*
** -------------------------- Parsing functions --------------------------------
*/

int					parse_start_node(char *line, t_graph *graph);
int					parse_end_node(char *line, t_graph *graph);
int					parse_input();
int					ft_atoi_validate_pos(const char *str);
t_hash				*parse_node_name(char *line, t_hash **h_table);



#endif