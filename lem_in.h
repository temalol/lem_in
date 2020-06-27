/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:28:00 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/27 23:57:05 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
	#define LEM_IN_H

# define TABLE_SIZE 10000
# define HASH_MULT 37

struct s_hash;

extern unsigned long ml;
extern unsigned long fr;

#define FCNT(x) fr++;

typedef struct s_child
{
	struct s_hash *c_node;
	struct s_child *next;

}              t_child;

typedef struct s_hash
{
	char *node_name;
	int x;
	int y;
	struct s_hash *next;
	t_child *child;

} t_hash;

typedef struct s_graph
{
	t_hash **h_table;
	t_hash *start;
	t_hash *end;
	int ants_num;
	char *map_buf;
	
} t_graph ;

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

/*
** -------------------------- Hash table functions --------------------------------
*/

t_hash				*hash_query(t_hash **h_table, char *node_name);
unsigned int		calc_hash(char *str);
t_hash 				**hash_table_init();
void				err_exit();
t_hash				*assign_to_table(t_hash **table, char *node_name);
void				free_hash_table(t_hash **h_table);
t_graph				*graph_init();

/*
** -------------------------- Parsing functions --------------------------------
*/

void 				parse_comments(char *line, t_graph *graph);
int					parse_start_node(char *line, t_graph *graph);
int					parse_end_node(char *line, t_graph *graph);
t_graph				*parse_input();
int					ft_atoi_validate_pos(const char *str);
t_hash				*parse_node_name(char *line, t_hash **h_table);
char 				*read_to_str(int fd);
char				*gnl(char *text);


/*
** -------------------------- Debug functions --------------------------------
*/

void				print_hash_table_child(t_hash **h_table);
void				print_hash_table(t_hash **h_table);

#endif