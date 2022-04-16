#include <stdlib.h>
#include "utils.h"
#include "stack.h"
#include "sort.h"

int	main(int argc, char **argv)
{
	t_stack	*top;
	char	*instr;

	top = stk_parse(argv + 1, argc - 1);
	instr = malloc(2 * argc * (ilog2(argc - 2) + 1));
	*instr = 'x';
	top = stk_sort(top, argc - 1, instr + 1);
	if (stk_check_rep_sorted(top))
		error_exit();
	instr_print(instr);
}
