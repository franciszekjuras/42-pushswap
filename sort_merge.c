/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:22:02 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/11 16:12:51 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ilist.h"
#include "stack.h"
#include "psops.h"
#include "sort.h"

int	stk_sort_rewind(t_pile *a, int btop, int s, char **instr)
{
	int	ia;

	ia = a->i->v;
	if (a->i->next == 0 || a->i->next->v == 0)
	{
		return (0);
	}
	while (ia > 0 && s * a->t->v < s * btop)
	{
		*instr = ps_rot(a, *instr);
		--ia;
	}
	return (ia);
}

char	*stk_sort_merge_to_from(t_pile *a, t_pile *b, int s, char *instr)
{
	int	ia;
	int	ib;

	ia = stk_sort_rewind(a, b->t->v, s, &instr);
	ib = b->i->v;
	while (ia < a->i->v || ib > 0)
	{
		if (ib == 0)
			instr = ps_rrot(a, instr);
		else if (ia == a->i->v || s * a->t->prev->v < s * b->t->v)
		{
			instr = ps_push(a, b, instr);
			--ib;
			--ia;
		}
		else
			instr = ps_rrot(a, instr);
		++ia;
	}
	a->i->v += b->i->v;
	b->i = ilst_pop(b->i);
	return (instr);
}

char	*stk_sort_push_to_from(t_pile *b, t_pile *a, char *instr)
{
	int	i;

	b->i = ilst_add(b->i, a->i->v);
	a->i = ilst_pop(a->i);
	i = 0;
	while (i < b->i->v)
	{
		instr = ps_push(b, a, instr);
		++i;
	}
	return (instr);
}

char	*stk_sort_merge(t_pile *a, t_pile *b, char *instr)
{
	if (a->i->next == 0 || a->i->next->v == 0)
		return (stk_sort_merge_to_from(a, b, 1, instr));
	else if (b->i == 0)
		return (stk_sort_push_to_from(b, a, instr));
	else if (b->i->next == 0)
		return (stk_sort_merge_to_from(b, a, -1, instr));
	else if ((a->i->v + b->i->v) >= b->i->next->v)
		return (stk_sort_merge_to_from(a, b, 1, instr));
	else if (a->i->v < b->i->v )
		return (stk_sort_push_to_from(b, a, instr));
	else
		return (stk_sort_merge_to_from(b, a, -1, instr));
}
