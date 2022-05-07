/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:20:51 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/07 22:20:52 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ilist.h"
#include "sort.h"
#include "psops.h"

char	*ps_push(t_pile *a, t_pile *b, char *instr)
{
	a->t = stk_push(a->t, stk_pop(&b->t));
	*instr = PA + a->idx;
	return (instr + 1);
}

char	*ps_swap(t_pile *a, char *instr)
{
	a->t = stk_swap(a->t);
	*instr = SA + a->idx;
	return (instr + 1);
}

char	*ps_rot(t_pile *a, char *instr)
{
	a->t = stk_rot(a->t);
	*instr = RA + a->idx;
	return (instr + 1);
}

char	*ps_rrot(t_pile *a, char *instr)
{
	a->t = stk_rrot(a->t);
	*instr = RRA + a->idx;
	return (instr + 1);
}
