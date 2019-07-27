/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 03:32:26 by abartole          #+#    #+#             */
/*   Updated: 2019/07/18 17:31:34 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "double.h"

typedef struct	s_printf
{
	int				plus;
	int				minus;
	int				hash;
	int				space;
	int				zero;
	long int		precision;
	int				width;
	int				size;
	int				total;
	char			conversion;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				lld;
	int				j;
	int				z;
}				t_printf;

/*
**make int work
*/
void			flags_for_int4(char **str, t_printf **flags);
void			flags_for_int3(char **str, t_printf **flags);
void			flags_for_int2(char **str, t_printf **flags);
void			flags_for_int1(char **str, t_printf **flags);

/*
**unordinary flags
*/
char			*do_zero_plus_int(char *str, t_printf *flags);
char			*do_hash_for_x(char *str, t_printf *flags);
char			*do_zero_plus(char *str, t_printf *flags, int len);
char			*do_hash_zero(char *str, t_printf *flags);
char			*add_for_x(char *str, t_printf *flags, int i);

/*
**flags
*/
char			*do_zero_int(char *str, t_printf *flags);
char			*do_space_int(char *str);
char			*do_hash(char *str, t_printf *flags);
char			*do_space(char *str, t_printf *flags);
char			*do_zero(char *str, t_printf *flags);
char			*do_plus(char *str, t_printf *flags);
char			*do_width(char *str, t_printf *flags);

/*
**for help
*/
void			make_up(char *str);
char			*work_with_negative(char *str);
intmax_t		parse_len(va_list args, t_printf *flags);
char			*precision(char *str, t_printf *flags);
uintmax_t		parse_unsigned_len(va_list args, t_printf *flags);
int				count_flags(char *str);
char			*precision_string(char *temp, t_printf *flags);
char			*return_null(t_printf *flags);
int				count_digits(char *str);
char			*do_width(char *str, t_printf *flags);
char			*negative_precision(char *str);

/*
**for_help2
*/
char			*join_plus(char *str);
char			*join_space(char *str);
char			*join_zero(char *str);

/*
**conversion
*/
char			*conversion_percent(void);
char			*conversion_hex(va_list args, t_printf *flags);
char			*conversion_octal(va_list args, t_printf *flags);
char			*conversion_int(va_list args, t_printf *flags);
char			*conversion_decimal(va_list args, t_printf *flags);
char			*conversion_string(va_list args, t_printf *flags);
char			*conversion_address(va_list args, t_printf *flags);
char			*conversion_char(va_list args, t_printf *flags);
char			*conversion_float(va_list args, t_printf *flags);

/*
**lets_work
*/
char			*flags_for_int(char *str, t_printf *flags);
char			*invalid_format(char **format, t_printf *flags);
char			*do_flag(char *str, t_printf *flags);
char			*do_conversion(va_list args, t_printf *flags);
char			*lets_work(va_list args, t_printf *flags);

/*
**check format
*/
void			check_length2(char **format, t_printf *flags);
void			check_conversion(t_printf *flags);
void			check_length(char **format, t_printf *flags);
void			check_flags(char **format, t_printf *flags);
void			check_precision(char **format, va_list args, t_printf *flags);
void			check_field_width(char **format, va_list args, t_printf *flags);
int				check_specifier(char**format, t_printf *flags);
char			*check_format(char **format, va_list args, t_printf *flags);

/*
**main function
*/
void			initialize_flags(t_printf *flags);
int				print_format(char **format, va_list args, t_printf *flags);
int				read_format(char **format, va_list args);
int				ft_printf(const char *format, ...);

char			*double_main(long double p, t_printf *flags);

#endif
