/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:44:31 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/11 16:44:32 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/errno.h>

//The Paths:
char	*full_path(char *cmd);
char	*relative_path(char **path, char **path_join, char *cmd1);
char	*the_path(char **env, char *cmd);
void	ft_free1(char **str);
void	check_env(char **env, char *cmd);

//Child Fun:
void	first_child(char **env, char **av, int infile, int fd[2]);
void	seconde_child(char **env, char **av, int outfile, int fd[2]);

//outil
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy1(char *dst, char *src);
char	*ft_strjoin(char const *s1, char const *s2);

//split Fun
char	**ft_split(char *s, char c);
char	*ft_all_str(char const *s, int bg, char c);
int		ft_countstr(char const *s, char c);
void	ft_free(char **str, int i);
int		ft_separa(char const *str, char c, int in);

//msgErr
size_t	ft_strlen(const char *s);
void	msg_err(char *err);
void	msg_error(char *err);
void	msg_cmd_not_found(char *cmd);
#endif