/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:59:44 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/07 17:43:22 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_nodes_to_queue(t_hash *working_node, t_q **queue, size_t bfscnt)
{	
	t_child *conns;

	conns = working_node->child;
	while (conns)
	{
		if (!conns->c_node->visit)
		{
			q_push(conns->c_node, queue);
			conns->c_node->visit = 1;
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

void	q_push(t_hash *node, t_q **queue)
{
	t_q *new;
	static t_q *q_end;
	
	MFAIL((new = malloc(sizeof(t_q))));
	if (!(*queue))
		(*queue) = new;
	new->q_node = node;
	if (q_end)
	q_end->next = new;
	new->next = NULL;
	q_end = new;	
}


void	bfs(t_graph *graph)
{
	size_t bfscnt;
	t_q *queue;
	t_hash *working_node;
	
	bfscnt = 0;
	queue = NULL;
		
	q_push(graph->start, &queue);
	graph->start->visit = 1;
	graph->start->bfs_level = bfscnt;
	while (queue)
	{
		if (working_node == graph->end)
		{
			q_pop(&queue); //to do free queue
			return ;
		}
		// print_queue(queue);
		working_node = q_pop(&queue);
		bfscnt =  working_node->bfs_level;
		// printf("\n%s Bfs Level:%lu", working_node->node_name, working_node->bfs_level);
		add_nodes_to_queue(working_node, &queue, bfscnt + 1);
	}
	err_exit();
}