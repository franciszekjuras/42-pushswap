/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:22:13 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/07 22:22:14 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"
# include "ilist.h"

typedef struct s_pile
{
	t_stack	*t;
	t_ilist	*i;
	char	idx;
}	t_pile;

t_stack	*stk_sort(t_stack *top, int n, char *instr);
char	*stk_sort_merge(t_pile *a, t_pile *b, char *instr);

#endif