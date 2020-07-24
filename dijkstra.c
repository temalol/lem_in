/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:08:31 by nmustach          #+#    #+#             */
/*   Updated: 2020/07/24 20:53:20 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_graph(t_vis *vis_lst)
{
	t_vis *tmp;
	
	while (vis_lst)
	{
		tmp = vis_lst;
		vis_lst->node->mark = INT_MAX;
		vis_lst->node->visit = 0;
		vis_lst = vis_lst->next;
		FCNT(free(tmp));
	}	
}

void	add_to_vis(t_hash *node, t_vis **vis_lst)
{
	t_vis *vis_node;

	if (!(*vis_lst))
	{
		MFAIL((*vis_lst = malloc(sizeof(t_vis))));
		(*vis_lst)->next = NULL;
		(*vis_lst)->node = node;
		return ;
	}
	MFAIL((vis_node = malloc(sizeof(t_vis))));
	vis_node->node = node;
	vis_node->next = *vis_lst;
	(*vis_lst) = vis_node;
}

void dijkstra_shortest(t_graph *graph)
{
	t_hash *node;

	node = graph->end->prev;
	printf("%s<=", graph->end->node_name);
	while (node != graph->start)
	{
		printf("%s<=", node->node_name);
		node = node->prev;
	}
	printf("%s", node->node_name);
}


t_child		*find_min_edge(t_child *edj_ptr)
{
	size_t minval;
	t_child *min_ptr;
	
	minval = edj_ptr->weight;
	min_ptr = NULL;
	while (edj_ptr)
	{
		if (edj_ptr->weight < minval)
		{
			minval = edj_ptr->weight;
			min_ptr = edj_ptr;
		}
		edj_ptr = edj_ptr->next;
	}
	return (min_ptr);
}


void	sort_edges(t_child *edj_lst)
{
	t_child *smallest;
	int tmp_f;
	size_t tmp_w;
	t_hash *tmp_n;
		
	while (edj_lst->next)
	{
		smallest = find_min_edge(edj_lst);
		if (smallest)
		{
			tmp_f = smallest->flow;
			tmp_w = smallest->weight;
			tmp_n = smallest->c_node;
			smallest->c_node = edj_lst->c_node;
			smallest->flow = edj_lst->flow;
			smallest->weight = edj_lst->weight;
			edj_lst->c_node = tmp_n;
			edj_lst->flow = tmp_f;
			edj_lst->weight = tmp_w;
		}
		edj_lst = edj_lst->next;
	}


}

void	add_to_queue(t_hash *working_node,t_q **queue, t_vis **vis_lst)
{
	t_child *edjs;
	
	edjs = working_node->child;
	sort_edges(edjs);
	
	while (edjs)
	{
		if (!edjs->c_node->visit && edjs->flow > 0)
		{
			q_push(edjs->c_node, queue);
			add_to_vis(edjs->c_node, vis_lst);
			edjs->c_node->visit = 1;
			if (edjs->c_node->mark > working_node->mark + edjs->weight)
				{
					edjs->c_node->mark = working_node->mark + edjs->weight;
					edjs->c_node->prev = working_node;
				}
		}
		edjs = edjs->next;
	}
}

int dijkstra(t_graph *graph)
{
	t_q *queue;
	t_vis *vis_lst;
	t_hash *working_node;
	
	queue = NULL;
	vis_lst = NULL;
	
	q_push(graph->start, &queue);
	graph->start->mark = 0;
	graph->start->visit = 1;
	 while (queue)
 	{
		working_node = q_pop(&queue);
		if (working_node == graph->end)
			{
				reset_graph(vis_lst);
				free_queue(queue);
				return 1;
			}
		add_to_queue(working_node, &queue, &vis_lst);
	}
	reset_graph(vis_lst);
	return 0;
}