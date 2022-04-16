#ifndef UTILS_H
# define UTILS_H

# include "stack.h"
# include "ilist.h"

void	error_exit(void);
t_stack	*stk_parse(char **argv, int n);
int		ilog2(int n);
int		stk_check_rep_sorted(t_stack *top);
void	instr_print(char *instr);

#endif