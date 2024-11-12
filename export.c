/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:35:06 by algaboya          #+#    #+#             */
/*   Updated: 2024/11/12 17:47:25 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_builtin(t_shell *general)
{
	if (!general->tok_lst->next)
		return (print_env(general->sorted_env_lst, 1), 0);
	if (export_valid(general->tok_lst->next->next) == FAILURE_EXIT)
		return (FAILURE_EXIT);
	// else if (ft_strchr(general->tok_lst->next->next, '='))
		
	return (SUCCESS_EXIT);
}

int	export_valid(t_token *token_list)
{
	int	i;
	int	exit_status;

	i = 0;
	exit_status = 0;
	while (token_list)
	{
		// printf("###\n");
		while (token_list->next && token_list->type == 9)
			token_list = token_list->next;
		if (!ft_isalpha(token_list->context[0]) || ft_isdigit(token_list->context[0]))  //token_list->context[0] == '_'
		{
			error_message(token_list->context);
			exit_status = 1;
		}
		token_list = token_list->next;
	}
	return (exit_status);
}
