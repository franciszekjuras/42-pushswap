#ifndef STACK_H
# define STACK_H

typedef struct s_stack	t_stack;

struct s_stack
{
	int		v;
	t_stack	*prev;
	t_stack	*next;
};

t_stack	*stk_new(int v);
t_stack	*stk_clear(t_stack *top);
t_stack	*stk_push(t_stack *top, t_stack *n);
t_stack	*stk_pushbck(t_stack *top, t_stack *n);
t_stack	*stk_pop(t_stack **topp);
t_stack	*stk_swap(t_stack *top);
t_stack	*stk_rot(t_stack *top);
t_stack	*stk_rrot(t_stack *top);

#endif