/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:22:27 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/07 22:22:28 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stk_swap(t_stack *top)
{
	t_stack	*swap;

	if (top == 0 || top->next == top)
		return (top);
	swap = top->next;
	top->prev->next = swap;
	swap->prev = top->prev;
	swap->next->prev = top;
	top->next = swap->next;
	swap->next = top;
	top->prev = swap;
	return (swap);
}

t_stack	*stk_rot(t_stack *top)
{
	if (top != 0)
		top = top->next;
	return (top);
}

t_stack	*stk_rrot(t_stack *top)
{
	if (top != 0)
		top = top->prev;
	return (top);
}
