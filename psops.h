#ifndef PSOPS_H
# define PSOPS_H

# define PA 'A'
# define PB 'B'
# define SA	'a'
# define SB 'b'
# define RA 'p'
# define RB 'q'
# define RRA 'P'
# define RRB 'Q'
# define SS 's'
# define RR 'r'
# define RRR 'R'

char	*ps_push(t_pile *a, t_pile *b, char *instr);
char	*ps_swap(t_pile *a, char *instr);
char	*ps_rot(t_pile *a, char *instr);
char	*ps_rrot(t_pile *a, char *instr);
char	*ps_swap2(t_pile *a, t_pile *b, char *instr);
char	*ps_rot2(t_pile *a, t_pile *b, char *instr);
char	*ps_rrot2(t_pile *a, t_pile *b, char *instr);

#endif