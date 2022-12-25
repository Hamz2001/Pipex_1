/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:12:54 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/16 11:12:55 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **env, char **av, int infile, int fd[2])
{
	char	**pp;
	char	*str;

	if (infile < 0)
		exit (0);
	close(fd[0]);
	pp = ft_split(av[0], ' ');
	str = full_path(pp[0]);
	if (str == NULL)
		str = the_path(env, pp[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	if (execve(str, pp, env) == -1)
		msg_error("bash");
	
}

void	seconde_child(char **env, char **av, int outfile, int fd[2])
{
	char	**pp;
	char	*str;

	close(fd[1]);
	pp = ft_split(av[0], ' ');
	str = full_path(pp[0]);
	if (str == NULL)
		str = the_path(env, pp[0]);
	dup2(outfile, 1);
	dup2(fd[0], 0);
	if (execve(str, pp, env) == -1)
		msg_error("bash");
}
