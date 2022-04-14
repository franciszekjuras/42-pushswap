#ifndef UTILS_H
# define UTILS_H

# include "stack.h"
# include "ilist.h"

typedef struct s_pile
{
	t_stack	*t;
	t_ilist *i;
}	t_pile;

void	error_exit(void);
void	stk_print(t_stack *top, char *head);

#endif