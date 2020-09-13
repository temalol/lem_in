/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:08:45 by nmustach          #+#    #+#             */
/*   Updated: 2020/09/14 01:22:17 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph	*graph_init(void)
{
	t_graph	*graph;

	MFAIL((graph = malloc(sizeof(t_graph))));
	graph->start = NULL;
	graph->end = NULL;
	graph->h_table = hash_table_init();
	return (graph);
}

int	parse_start_node(char *line, t_graph *graph)
{
	t_hash	*node;
	char	*str_ret;

	if (ft_strequ("##start", line))
	{
		if (graph->start)
			err_exit();
		if (((str_ret = gnl(graph->map_buf)) != NULL)
		&& (node = parse_node_name(str_ret, graph->h_table)))
		{
			graph->start = node;
			return (1);
		}
		else
			err_exit();
	}
	return (0);
}

int	parse_end_node(char *line, t_graph *graph)
{
	t_hash	*node;
	char	*str_ret;

	if (ft_strequ("##end", line))
	{
		if (graph->end)
			err_exit();
		if (((str_ret = gnl(graph->map_buf)) != NULL)
		&& (node = parse_node_name(str_ret, graph->h_table)))
		{
			graph->end = node;
			return (1);
		}
		else
			err_exit();
	}
	return (0);
}

void	check_if_already_linked(t_hash *haystack, t_hash *needle)
{
	t_child	*c_node_hay;

	c_node_hay = haystack->child;
	while (c_node_hay)
	{
		if (c_node_hay->c_node == needle)
			err_exit();
		c_node_hay = c_node_hay->next;
	}
}

void	add_link(t_hash *parent, t_hash *child)
{
	t_child *new;
	t_child *c_list;

	MFAIL((new = malloc(sizeof(t_child))));
	new->next = NULL;
	new->c_node = child;
	new->flow = 1;
	new->weight = 1;
	if (parent->child == NULL)
		parent->child = new;
	else
	{
		c_list = parent->child;
		while (c_list->next)
			c_list = c_list->next;
		c_list->next = new;
	}
}
