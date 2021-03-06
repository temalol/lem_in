/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:28:00 by nmustach          #+#    #+#             */
/*   Updated: 2020/09/14 02:03:18 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TABLE_SIZE 10000
# define HASH_MULT 37

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

struct s_hash;

extern unsigned long ml;
extern unsigned long fr;
extern unsigned long nodes_num;
extern unsigned long edges_num;

# define FCNT(x) x; fr++
# define MFAIL(x) if (!x) err_exit(); else ml++;

typedef	struct		s_child 
{
	struct s_hash	*c_node; //  Указатель на вершину t_hash
	int				flow;
	size_t			weight;
	struct s_child	*next; // Указатель списка на следующую вершину
}					t_child;

typedef struct	s_path
{
		struct s_hash	*node;
		struct s_path	*next;
} 				t_path;

typedef struct	s_vis
{
	struct s_hash	*node;
	struct s_vis	*next;
}
				t_vis;

typedef	struct				s_hash
{
	char		*node_name; 
	int		x;
	int		y;
	struct		s_hash *next; // Тут хранятся коллизии хэш таблицы (Список)
	size_t			visit;
	size_t 		mark;
	size_t		bfs_level;
	t_child		*child; // Тут хранятся связи для данной ноды (Список) 
	struct s_hash 	*prev; 
}					t_hash;

typedef struct		s_graph
{
	t_hash			**h_table; // Указатель на хэш таблицу
	t_hash			*start; 
	t_hash			*end;
	int				ants_num;
	char			*map_buf;
	t_path			*paths_list;
}					t_graph;

typedef struct	s_q
{
		struct s_hash	*q_node;
		struct s_q		*next;
}				t_q;

/*
** -------------------------- Hash table functions ----------------------------
*/

t_hash				*hash_query(t_hash **h_table, char *node_name);
unsigned int		calc_hash(char *str);
t_hash				**hash_table_init();
t_hash				*assign_to_table(t_hash **table, char *node_name);
void				free_hash_table(t_hash **h_table);
t_graph				*graph_init();
void				add_link(t_hash *parent, t_hash *child);
void				check_if_already_linked(t_hash *haystack, t_hash *needle);

/*
** -------------------------- Parsing functions --------------------------------
*/

void				parse_comments(char *line, t_graph *graph);
int					parse_start_node(char *line, t_graph *graph);
int					parse_end_node(char *line, t_graph *graph);
t_graph				*parse_input();
int					ft_atoi_validate_pos(const char *str);
t_hash				*parse_node_name(char *line, t_hash **h_table);
char				*read_to_str(int fd);
char				*gnl(char *text);
void				err_exit();

/*
** -------------------------- Bfs functions --------------------------------
*/

t_hash				*bfs(t_graph *graph);
void				q_push(t_hash *node, t_q **queue);
t_hash				*q_pop(t_q **queue);
void				*get_shortest_path(t_hash *end_node);
t_path				*path_init(t_hash *start);
t_path				*clone_path(t_path *path);
void				append_to_path(t_path **path, t_hash *node);
void				free_path(t_path *path);
void				free_queue(t_q *queue);

/*
** -------------------------- Debug functions --------------------------------
*/
void				print_hash_table_child(t_hash **h_table);
void				print_hash_table(t_hash **h_table);
void				print_queue(t_q *queue);

int dijkstra(t_graph *graph);
void dijkstra_shortest_reverse(t_graph *graph);
t_child		*get_edge(t_child *haystack, t_hash *needle);
void	get_paths(t_graph *graph);

#endif
