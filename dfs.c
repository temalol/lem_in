/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:39:37 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/13 02:07:07 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_visited(t_path *path, t_hash *node)
{
	while (path)
	{
		if (path->node == node)
			return (1);	
		path = path->next;
	}
	return (0);
}


void	free_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		FCNT(free(tmp));
	}
}


void	append_to_path(t_path **path, t_hash *node)
{
	t_path *new;
	
	MFAIL((new = malloc(sizeof(t_path))));
	
	new->node = node;
	new->next = (*path);
	(*path) = new;
}

t_path	*path_init(t_hash *start)
{
	t_path *path;
	
	MFAIL((path = malloc(sizeof(t_path))));
	path->next = NULL;
	path->node = start;
	
	return (path);
}

t_path	*clone_path(t_path *path)
{
	t_path *clone;
	t_path *st;
	
	MFAIL((clone = malloc(sizeof(t_path))));
	clone->node = path->node;
	clone->next = NULL;
	path = path->next;
	st = clone;
	while (path)
	{			
		MFAIL((clone->next = malloc(sizeof(t_path))));
		clone = clone->next;
		clone->node = path->node;		
		clone->next = NULL;
		path = path->next;
	}
	return (st);
}


void dfs(t_graph *graph, t_path *path)
{
	t_child *c_lst;
	int valid_nodes;	
	t_hash *working_node;
	valid_nodes = 0;
	t_path *clone;
	
	working_node = path->node;
	//printf("%s\n",working_node->node_name);
	if (working_node == graph->end)
	{
		t_path *f_path;
		
		f_path = path;
		while (path)
		{
			printf("%s=>", path->node->node_name);
			path = path->next;
		}
		free_path(f_path);
		printf("\n");
		return ;
	}
	
	c_lst = working_node->child;
	
	while (c_lst)
	{
		if (!is_visited(path, c_lst->c_node))
		{
			clone = clone_path(path);
			append_to_path(&clone, c_lst->c_node);
			dfs(graph, clone);
			valid_nodes++;
		}
		c_lst = c_lst->next;
	}
	if (!valid_nodes)	
		{
			free_path(path);
				return ;
		}
		free_path(path);
}
