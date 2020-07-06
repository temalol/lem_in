/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:59:44 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/07 02:21:47 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	size_t bfs_l;
	t_q *queue;
	
	bfs_l = 0;
	queue = NULL;
		
	
	q_push(graph->start,&queue);
	q_push(graph->end,&queue);
	print_queue(queue);
	while(queue)
	q_pop(&queue);

	
	print_queue(queue);
	
}