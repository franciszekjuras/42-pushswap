#include <stdlib.h>
#include "stack.h"

t_stack	*stk_new(int v)
{
	t_stack	*n;

	n = malloc(sizeof(t_stack));
	n->v = v;
	return (n);
}

t_stack	*stk_clear(t_stack *top)
{
	t_stack	*n;

	if (top == 0)
		return (0);
	n = top;
	while(n->next != top)
	{
		n = n->next;
		free(n->prev);
	}
	free(n);
	return (0);
}

t_stack	*stk_push(t_stack *top, t_stack *n)
{
	if (top == 0)
	{
		n->next = n;
		n->prev = n;
		return (n);
	}
	n->prev = top->prev;
	n->next = top;
	top->prev->next = n;
	top->prev = n;
	return (n);
}

t_stack	*stk_pushbck(t_stack *top, t_stack *n)
{
	return (stk_push(top, n)->next);
}

t_stack	*stk_pop(t_stack **topp)
{
	t_stack	*top;

	top = *topp;
	if (top->next == top)
		*topp = 0;
	else
	{
		top->prev->next = top->next;
		top->next->prev = top->prev;
		*topp = top->next;
	}
	return (top);
}
