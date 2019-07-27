/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:39:05 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/12 10:39:06 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_H
# define DOUBLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

# define LONG_DOUBLE 10

typedef struct			s_number
{
	int					num;
	struct s_number		*next;
}						t_number;

int						is_nan(char *str);
t_number				*new_num(int num);
void					free_num(t_number **lst);
int						get_exp(long double exp);
char					*get_frac(long double num);
t_number				*ft_big_pow(int a);
t_number				*get_integral_part(int exp, char *frac);
int						get_lst_len(t_number *lst);
t_number				*get_fractional_part(int exp, char *frac);
int						get_sign(long double sign);
void					sum_tmp(t_number *lst, int tmp);
void					set_int(char *str, t_number *integral);
char					*make_double(long double p, unsigned int precision);
char					*is_nan_or_inf(long double p, char *frac);
char					*make_dot(char *str);
void					norme(t_number **lst, t_number **tmp, int *i);

#endif
