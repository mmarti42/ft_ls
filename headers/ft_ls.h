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
# define badFlag "ls: illegal option -- \n"
# define usage "\nusage: ls [-Ralrt] [file ...]\n"

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
#include <time.h>

# include <stdlib.h>
# include "../libft/libft.h"

int	a;
int	l;
int	R;
int	r;
int	t;

typedef struct			s_object
{
	unsigned short		mod;
	int					links;
	unsigned int		master;
	unsigned int		group;
	long 				size;
	long				time;
	char 				*path;
	char				*name;
	u_int8_t			type;
	struct s_object		*left;
	struct s_object		*right;
}						t_obj;

long					lstcmpt(t_obj *lst1, t_obj *lst2);
int						lstcmpn(t_obj *lst1, t_obj *lst2);
int						lstcmpnrev(t_obj *lst1, t_obj*lst2);
long					lstcmptrev(t_obj *lst1, t_obj *lst2);
t_obj					*new_obj(struct dirent *dirent, char *str, struct stat *stbuf);
void					free_obj(t_obj *lst);
t_obj					*get_last(t_obj *lst);
//void					show_obj(t_obj *lst, t_flags *flags);
char					*ft_namejoin(char const *s1, char const *s2);
//t_obj					*search(t_flags *flags);
int 					error(char c);
void					*objcpy(t_obj *lst);
void					by_name(t_obj *lbegin, t_obj* lcurr);
void					by_time(t_obj *lbegin, t_obj* lcurr);

#endif
