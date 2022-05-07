/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:20:32 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/07 22:20:33 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ilist.h"

t_ilist	*ilst_pop(t_ilist *front)
{
	t_ilist	*next;

	next = front->next;
	free(front);
	return (next);
}

t_ilist	*ilst_add(t_ilist *front, int v)
{
	t_ilist	*n;

	n = malloc(sizeof(t_ilist));
	n->next = front;
	n->v = v;
	return (n);
}

t_ilist	*ilst_clear(t_ilist *front)
{
	t_ilist	*next;

	while (front != 0)
	{
		next = front->next;
		free(front);
		front = next;
	}
	return (0);
}
