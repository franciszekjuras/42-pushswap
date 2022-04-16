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