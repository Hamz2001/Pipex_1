/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:35:07 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/11 16:35:09 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	infile(char **av)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		msg_err("bash");
	return (infile);
}

int	outfile(char **av, int ac)
{
	int	outfile;

	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		msg_error("bash");
	return (outfile);
}

void	ft_other(char **env, char **av, int ac, int fd[2])
{
	int	in;
	int	out;
	int	id[2];

	in = infile(av);
	out = outfile(av, ac);
	if (pipe(fd) == -1)
		msg_error("Error pipe :");
	id[0] = fork();
	if (id[0] == -1)
		msg_error("Error fork :");
	if (id[0] == 0)
		first_child(env, &av[2], in, fd);
	id[1] = fork();
	if (id[1] == -1)
		msg_error("Error fork2 :");
	if (id[1] == 0)
		seconde_child(env, &av[3], out, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];

	if (ac == 5)
	{
		ft_other(env, av, ac, fd);
	}
	else
		msg_error("Invalid Number of Argument\n");
	return (0);
}
