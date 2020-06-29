/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:14:48 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/29 04:23:35 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_conn(t_graph *graph, char *line)
{
		t_hash *parent;
		t_hash *child;
		t_child *new;
		t_child *c_list;
		int i;
		i = 0;
		
		if (!line)
			err_exit();
		while(line[i] != '-' && line[i])	
			i++;
		if (!line[i])
			err_exit();
		line[i] = 0;
		parent = hash_query(graph->h_table, line);
		child = hash_query(graph->h_table, &line[i + 1]);
		line[i] = '-';
		if (parent && child)
		{
			MFAIL((new = malloc(sizeof(t_child)))); 
			new->next = NULL;
			new->c_node = child;
			
			if (parent->child == NULL)
				parent->child = new;
			else
			{
			c_list = parent->child;
			while(c_list->next)
				c_list = c_list->next;
			c_list->next = new;
			}
			// printf("%s", line);
			// printf("-%s\n", &line[i + 1]);
		}
		else
			err_exit();
	
}

void	parse_links(t_graph *graph,char *line)
{
		char *str_ret;
		parse_conn(graph, line);
		while ((str_ret = gnl(graph->map_buf)) != NULL) // FAIL?
		{
			if (str_ret[0] == '#')
			{
				// printf("%s\n", str_ret);
				continue ;
			}
			parse_conn(graph, str_ret);
		}
}

void	parse_rooms(t_graph *graph)
{
	char 	*str_ret;
	t_hash 	*node_ret;
	

	while ((str_ret = gnl(graph->map_buf)) != NULL)
	{
		if (str_ret[0] == '#')
		{
			parse_comments(str_ret, graph);
			continue ;
		}
		if ((node_ret = parse_node_name(str_ret, graph->h_table)))
			continue ;
		else
			break;
	}
	if (graph->start && graph->end)
		parse_links(graph, str_ret);
	else
		err_exit();
}


void	err_exit()
{
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(1);
}

void parse_comments(char *line, t_graph *graph)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (parse_start_node(line, graph))
			return ;
		else if (parse_end_node(line, graph))
			return ;
		else
			err_exit();
	}
}

void 	parse_ants_number(t_graph *graph)
{
	char	*ret;
	int		ants_num = 0;
	
	if ((ret = gnl(graph->map_buf)) != NULL)
		{
			ants_num = ft_atoi_validate_pos(ret);
			if (ants_num > 0)
				{
					// printf("%d\n", ants_num);
					graph->ants_num = ants_num;
				}
			else
				err_exit();
		}
	else 
		err_exit();
		
}

t_hash	*parse_node_name(char *line, t_hash **h_table)
{
	int i;
	t_hash *node;
	char	*strdup;
	
	i = 0;
	node = NULL;

	if (!line[i] || line[i] == ' ')
			err_exit();
	while(line[i] != ' ' && line[i])	
			i++;
	if (line[i] == ' ')
	{
		line[i] = 0;
		if (!hash_query(h_table, line))
			{
				MFAIL((strdup = ft_strdup(line)));
				node = assign_to_table(h_table, strdup);
			}
		else
			err_exit();
		// printf("%s", line);
		// printf(" %s\n",&line[i + 1]);
		line[i] = ' ';
		return(node);
	}
	else
		return (NULL);
}

t_graph	*parse_input()
{
	t_graph *graph = NULL;
	graph = graph_init();
	graph->map_buf = read_to_str(0);
	parse_ants_number(graph);
	parse_rooms(graph);
	return (graph);	
}
