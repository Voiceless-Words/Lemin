/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:05:40 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/27 15:50:51 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "./libft/libft.h"

typedef struct		s_data
{
	char			*data;
	struct s_data	*next;
}					t_data;

typedef struct		s_rooms
{
	struct s_data	*dat_h;
	int				x;
	int				ants;
	int				flag;
	int				y;
	int				count;
	int				nbr_link;
	int				visit;
	char			*name;
	struct s_rooms	**links;
	char			**path;
}					t_rooms;

typedef struct		s_main
{
	int				no_rms;
	t_rooms			**rooms;
}					t_main;

void				ft_free(char **str);
int					ft_get_rooms(t_rooms *ours);
int					ft_strlength(char **str);
int					ft_check_valid(t_rooms *ours, int nbr_rooms);
int					ft_assign(t_rooms *ours, int nbr_rooms, t_main **ptr);
void				ft_store_link(t_rooms *ours, t_main **ptr, t_data *dat);
int					ft_find_path1(t_rooms *ours, t_main **ptr);
int					ft_rooms(char **temp1, int i, t_main **ptr);
char				**ft_find_room(char **temp1, t_data *dat);
int					ft_return_i(t_main **ptr, char **tp, t_data **dat, int *i);
int					ft_return_ie(t_main **ptr, t_data **dat, int *i, char **tp);

#endif
