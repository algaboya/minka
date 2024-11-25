/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:33:37 by algaboya          #+#    #+#             */
/*   Updated: 2024/11/24 21:43:32 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin(t_shell *general)
{
	int	status;

	status = SUCCESS_EXIT;
	if (!general->tok_lst->next || !general->tok_lst->next->next)
		status = change_home(general);
	else if (general->tok_lst->next && ft_strcmp(general->tok_lst->next->next, "-") == 0)
		status = change_old_pwd(general);
	else if (general->tok_lst->next && general->tok_lst->next->next)
		status = change_dir(general, general->tok_lst->next->next);
	return (status);
}

int	change_home(t_shell *general)
{
	char	*home;

	home = get_value(general, "HOME");
	if (chdir(home) != 0)
	{
		printf(" cd: %s: No such file or directory", home);
		return (FAILURE_EXIT);
	}
}

char *get_value(t_shell *general, char *keyik)
{
	t_env	*tmp;

	tmp = general->env_lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, keyik) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
