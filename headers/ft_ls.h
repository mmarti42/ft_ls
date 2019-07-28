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
# define BADFLAG "ls: illegal option -- "
# define USAGE "\nusage: ls [-Ralrt] [file ...]\n"

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

int	g_a;
int	g_l;
int	g_rr;
int	g_r;
int	g_t;
int g_f;

typedef struct			s_dirs
{
	char				*dir;
	struct s_dirs		*next;
}						t_dirs;

typedef struct			s_object
{
	long				time;
	int					blocks;
	char				*mod;
	char				*links;
	char				*master;
	char				*group;
	char				*maj;
	char				*min;
	char				*size;
	char				*time_year;
	char				*time_month;
	char				*time_day;
	char				*name;
	char				*linked_file;
	char				*path;
	u_int8_t			type;
	struct s_object		*left;
	struct s_object		*right;
}						t_obj;

typedef struct			s_column
{
	int					links;
	int					master;
	int					group;
	int					maj;
	int					min;
	int					size;
	int					time_year;
	int					time_day;
	int					name;
	int					total;
}						t_column;

typedef	struct			s_variables
{
	int					endfl;
	t_dirs				*dirs;
	void				(*sort)(t_obj*, t_obj*);
	void				(*show)(t_obj*, t_column*);
	t_dirs				*tmp;
}						t_vars;

t_obj					*new_obj(struct dirent *dirent,
		char *str, t_column *col);
void					free_obj(t_obj *lst);
char					*ft_namejoin(char *s1, char *s2);
void					search(char *dir_name, void(*sort)(t_obj*, t_obj*),
		void(*show)(t_obj*, t_column *));
int						error(char c);
void					by_name(t_obj *lbegin, t_obj *lcurr);
void					by_time(t_obj *lbegin, t_obj *lcurr);
void					show_obj(t_obj *lst, t_column *col);
void					show_objrev(t_obj *lst, t_column *col);
int						setflags(char *av);
void					get_pointers(void(**sort)(t_obj*, t_obj*),
		void(**show)(t_obj*, t_column*));
void					show_not_sorted(t_obj *lst, t_column *col);
void					set_columns(t_obj *lst, t_column *col);
t_column				*new_column();
char					*convert_perm(unsigned short mod);
char					*convert_links(int links);
char					*convert_uid(unsigned int uid);
char					*convert_gid(unsigned int gid);
char					*convert_min(dev_t dev);
char					*convert_maj(dev_t dev);
char					*convert_size(long size);
char					*convert_linked_file(char *path);
char					*convert_year(long t);
char					*convert_month(long t);
char					*convert_day(long t);
char					*cut_noyear(char *tmp);
void					sort_dirs(t_dirs *dirs);
void					free_lst(t_dirs *lst);
void					write_long(t_obj *lst, t_column *col);
void					write_name(t_obj *lst, t_column *col);

#endif
