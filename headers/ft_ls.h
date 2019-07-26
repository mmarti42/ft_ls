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

int	g_a;
int	g_l;
int	g_R;
int	g_r;
int	g_t;

typedef struct s_dirs
{
	char			*dir;
	struct s_dirs	*next;
}					t_dirs;

typedef struct			s_object
{
	unsigned short		mod;
	int					links;
	int					blocks;
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

t_obj					*new_obj(struct dirent *dirent, char *str);
void					free_obj(t_obj *lst);
char					*ft_namejoin(char *s1, char *s2);
void					search(char *dir_name, void(*sort)(t_obj*, t_obj*), void(*show)(t_obj*));
int 					error(char c);
void					by_name(t_obj *lbegin, t_obj* lcurr);
void					by_time(t_obj *lbegin, t_obj* lcurr);
void					show_obj(t_obj *lst);
void					show_objrev(t_obj *lst);
int						setFlags(char *av);
void					get_pointers(void(**sort)(t_obj*, t_obj*), void(**show)(t_obj*));

#endif
