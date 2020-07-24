/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:59:44 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/25 01:54:19 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hash	*find_smallest_bfs(t_child *node)
{
	t_hash *smallest;
	size_t smallest_bfs;
	
	smallest = node->c_node;
	smallest_bfs = node->c_node->bfs_level;

	while (node)
	{
		if (node->c_node->bfs_level < smallest_bfs)
		{
			smallest = node->c_node;
			smallest_bfs = node->c_node->bfs_level;
		}
		node = node->next;
	}
	return (smallest);
}


void *get_shortest_path(t_hash *end_node)
{
	t_hash *curr_node;
			
	curr_node = end_node;
	while (curr_node->bfs_level > 0)
	{
		printf("%s=>",curr_node->node_name);
		//curr_node->visit = INT_MAX;
		//curr_node->bfs_level = INT_MAX;
		curr_node = find_smallest_bfs(curr_node->child);
	}
	printf("%s", curr_node->node_name);
	return NULL;
}

void	add_nodes_to_queue(t_hash *working_node, t_q **queue, size_t bfscnt, size_t vis)
{	
	t_child *conns;

	conns = working_node->child;
	while (conns)
	{
		if (conns->c_node->visit < vis && conns->flow > 0)
		{
			q_push(conns->c_node, queue);
			conns->c_node->visit = vis;
			conns->c_node->bfs_level = bfscnt;
		}
		conns = conns->next;
	}
}


t_hash	*q_pop(t_q **queue)
{
	t_hash *ret_node;
	t_q *pop_node;

	pop_node = *queue;
	*queue = pop_node->next;
	ret_node = pop_node->q_node;	
	FCNT(free(pop_node));
	return (ret_node);
}

void	free_queue(t_q *queue)
{
	t_q *tmp;
		
	while (queue)
	{
		tmp = queue->next;
		FCNT(free(queue));
		queue = tmp;
	}
	
}


void	q_push(t_hash *node, t_q **queue)
{
	t_q *new;
	t_q *q_end;
	
	q_end = *queue;
	MFAIL((new = malloc(sizeof(t_q))));
	new->q_node = node;
	new->next = NULL;
	if (!*queue)
	{
		*queue = new;
		new->next = NULL;
		return ;
	}
	while (q_end->next)
		q_end = q_end->next;
	q_end->next = new;
	
	
}

t_hash	*bfs(t_graph *graph)
{
	size_t bfscnt;
	t_q *queue;
	t_hash *working_node;
	t_hash *ret;
	static size_t vis;
 	
	bfscnt = 0;
	queue = NULL;
	ret = NULL;
	
	vis++;
	q_push(graph->start, &queue);
	graph->start->visit = vis;
	graph->start->bfs_level = bfscnt;
	while (queue)
	{
		working_node = q_pop(&queue);
		if (working_node == graph->end)
		{
			//printf("\n%s BFS level:%lu", working_node->node_name, working_node->bfs_level);
			//free_queue(queue);
			ret = working_node;
		}
		bfscnt =  working_node->bfs_level;
		printf("\n%s Bfs Level:%lu", working_node->node_name, working_node->bfs_level);
		add_nodes_to_queue(working_node, &queue, bfscnt + 1,vis);
	}
	return ret;
}