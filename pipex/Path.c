/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:14:50 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/16 11:14:51 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

char	*full_path(char *cmd)
{
	if (access(cmd, F_OK) != -1)
	{
		if (access(cmd, X_OK) != -1)
		{
			return (cmd);
		}
	}
	return (0);
}

char	*relative_path(char **path, char **path_join, char *cmd1)
{
	int		i;
	char	*pp;

	i = 0;
	while (path[i])
	{
		path_join[i] = ft_strjoin(path[i], cmd1);
		if (access(path_join[i], F_OK) != -1)
		{
			if (access(path_join[i], X_OK) != -1)
			{
				pp = path_join[i];
				ft_free1(path);
				ft_free1(path_join);
				return (pp);
			}
		}
		i++;
	}
	return (0);
}

void	check_env(char **env, char *cmd)
{
	int	i;

	i = 6;
	if (ft_strncmp(env[i], "PATH=", 5))
		msg_cmd_not_found(cmd);
}

char	*the_path(char **env, char *cmd)
{
	int		i;
	char	**path;
	char	**path_join;
	char	*final_str;
	char	*cmd1;

	i = 0;
	cmd1 = ft_strjoin("/", cmd);
	check_env(env, cmd);
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	path = ft_split(&env[i][5], ':');
	i = 0;
	while (path[i])
		i++;
	path_join = ft_calloc(i, sizeof(char *));
	final_str = relative_path(path, path_join, cmd1);
	free(cmd1);
	if (final_str == NULL)
		msg_cmd_not_found(cmd);
	return (final_str);
}
