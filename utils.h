/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:22:37 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/07 22:22:38 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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