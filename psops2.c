#include "stack.h"
#include "sort.h"
#include "ilist.h"
#include "psops.h"

char	*ps_swap2(t_pile *a, t_pile *b, char *instr)
{
	a->t = stk_swap(a->t);
	b->t = stk_swap(b->t);
	*instr = SS;
	return (instr + 1);
}

char	*ps_rot2(t_pile *a, t_pile *b, char *instr)
{
	a->t = stk_rot(a->t);
	b->t = stk_rot(b->t);
	*instr = RR;
	return (instr + 1);
}

char	*ps_rrot2(t_pile *a, t_pile *b, char *instr)
{
	a->t = stk_rot(a->t);
	b->t = stk_rot(b->t);
	*instr = RRR;
	return (instr + 1);
}
