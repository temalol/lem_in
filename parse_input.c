/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 22:14:48 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/23 00:33:14 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_spaces(char *str, size_t *sp)
{	
	size_t i;

	i = 0;
	while(str[i] != ' ' && str[i])
		i++;
	if (!str[i])
		return (0);
	str[i] = 0;
	sp[0] = i;
	i++;
	while(str[i] != ' ' && str[i])
		i++;
	if (!str[i])
		return (0);
	str[i] = 0;
	sp[1] = i;
	return (1);
}



void	parse_connections(t_graph *graph, char *line)
{
		t_hash *parent;
		t_hash *child;
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
		if ((parent && child) && (parent != child))
		{
			check_if_already_linked(parent, child);
			check_if_already_linked(child, parent);
			add_link(parent, child);
			add_link(child, parent);
			edges_num += 2; 
		}
		else
			err_exit();
	
}

void	parse_links(t_graph *graph,char *line)
{
		char *str_ret;
		parse_connections(graph, line);
		while ((str_ret = gnl(graph->map_buf)) != NULL)
		{
			if (str_ret[0] == '#')
			{
				if (str_ret[0] == '#' && str_ret[1] == '#')
					err_exit();
				continue ;
			}
			parse_connections(graph, str_ret);
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
	write(1, "ERROR\n", 6);
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
					graph->ants_num = ants_num;
			else
				err_exit();
		}
	else 
		err_exit();
		
}

t_hash	*parse_node_name(char *line, t_hash **h_table)
{
	size_t i;
	t_hash *node;
	char	*strdup;
	size_t	sp_ind[2];
	int l_x;
	int l_y;
	
	i = 0;
	node = NULL;

	if (!line || line[i] == ' ' || line[i] == 'L' )
	 		err_exit();
	if (get_spaces(line, sp_ind))
	{
		if (!hash_query(h_table, line))
			{
				MFAIL((strdup = ft_strdup(line)));
				node = assign_to_table(h_table, strdup);
				l_x = ft_atoi_validate_pos(&line[sp_ind[0] + 1]);
				l_y = ft_atoi_validate_pos(&line[sp_ind[1] + 1]);
				if (l_x >=0 && l_y >= 0)
					{
						node->x = l_x;
						node->y = l_y;
					}
					else
						err_exit();
				line[sp_ind[0]] = ' ';
				line[sp_ind[1]] = ' ';
			}
		else
			err_exit();
		nodes_num++;
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
	 if (!graph->start->child || !graph->end->child)
		err_exit();
	return (graph);
}
