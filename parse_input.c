/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:14:48 by nmustach          #+#    #+#             */
/*   Updated: 2020/06/22 01:12:34 by nmustach         ###   ########.fr       */
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
		

		if (!line[0])
			err_exit();
		while(line[i] != '-' && line[i])	
			i++;
		if (!line[i])
			err_exit();
		line[i] = 0;
		parent = hash_query(graph->h_table, line);
		child = hash_query(graph->h_table, &line[i + 1]);
		if (parent && child)
		{
			new = malloc(sizeof(t_child));
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
			printf("%s", line);
			printf("-%s\n", &line[i + 1]);
		}
		else
			err_exit();
	
}

void	parse_links(t_graph *graph,char *line)
{
		
		parse_conn(graph, line);
		free(line);
		//print_hash_table_child(graph->h_table);
		while (get_next_line(0, &line) > 0)
		{
			if (line[0] == '#')
			{
				printf("%s\n", line);
				continue ;
			}
			parse_conn(graph, line);
			free(line);	
		}
		print_hash_table_child(graph->h_table);

		//printf("%s", line);
		//free(line);
		
}

void	parse_rooms(t_graph *graph)
{
	char 	*line;
	t_hash 	*node_ret;
	
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			parse_comments(line, graph);
			continue;
		}
		if ((node_ret = parse_node_name(line, graph->h_table)))
			free(line);
		else
			break;
	}
	if (graph->start && graph->end)
		parse_links(graph, line);
	
		//return (line);
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
	
	if (line[0] == '#')
		{
			printf("%s\n", line);
			free(line);
		}
}

int	parse_ants_number()
{
	char	*line;
	int		ants_num = 0;
	
	if (get_next_line(0, &line) > 0)
		{
			ants_num = ft_atoi_validate_pos(line);
			free(line);
			if (ants_num > 0)
				printf("%d\n", ants_num);
			else
				err_exit();
		}
	else 
		err_exit();
	return (ants_num);	
}

t_hash	*parse_node_name(char *line, t_hash **h_table)
{
	int i;
	t_hash *node;
	
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
			node = assign_to_table(h_table, ft_strdup(line));
		else
			err_exit();
		printf("%s", line);
		printf(" %s\n",&line[i + 1]);
		return(node);
	}
	else
		return (NULL);
}

int	parse_input()
{
	t_graph *graph = NULL;
	graph = graph_init();
	if ((graph->ants_num = parse_ants_number()) < 1)
		err_exit();
	parse_rooms(graph);
	//parse_links(graph);
	return 0;	
}
