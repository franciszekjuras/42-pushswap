#include <stdio.h>
#include <stdlib.h>
#include <libft/libft.h>
#include "stack.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ilog2(int n)
{
	int	r;

	r = 0;
	while (n > 1)
	{
		n = n >> 1;
		++r;
	}
	return (r);
}

void	stk_print(t_stack *top, char *head)
{
	t_stack	*n;
	
	if (head != 0)
		printf("%s", head);
	n = top;
	if (top != 0)
	{
		while (1)
		{
			printf("%2d ", n->v);
			n = stk_rot(n);
			if (n == top)
				break ;
		}
	}
	printf("\n");
}
