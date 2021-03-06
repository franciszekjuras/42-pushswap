/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:21:54 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/11 19:39:53 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		top = stk_clear(top);
		free(instr);
		error_exit();
	}
	top = stk_clear(top);
	instr_print(instr);
	free(instr);
}
