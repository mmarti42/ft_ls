/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:09:38 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/11 11:09:39 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <dirent.h>

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define CUR_DIR "."
# define PREV_DIR ".."

typedef struct			s_flags
{
	int 				R;
	int 				r;
	int 				a;
	int 				t;
	int 				l;
}						t_flags;

typedef struct			s_object
{
	char 				*path;
	char				*name;
	u_int8_t			type;
	struct s_object		*next;
	struct s_object		*content;
}						t_obj;

int						set_options(char **argv, t_flags *flags);
int						ft_ls_main(int dir, char **argv, t_flags *flags);
t_obj					*new_obj(struct dirent *dirent, const char *str);
void					free_obj(t_obj *lst);
t_obj					*get_last(t_obj *lst);
void					show_obj(t_obj *lst, t_flags *flags);
char					*ft_namejoin(char const *s1, char const *s2);
t_obj					*search(int dir, char **argv, t_flags *flags);

#endif
