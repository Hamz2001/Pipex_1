/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msgErr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:46:57 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/19 14:46:58 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' )
		i++;
	return (i);
}

void	msg_err(char *err)
{
	perror(err);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	msg_cmd_not_found(char *cmd)
{
	write(2, "Commande not found :", 21);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit (127);
}
