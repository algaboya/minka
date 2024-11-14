/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:35:06 by algaboya          #+#    #+#             */
/*   Updated: 2024/11/14 21:25:52 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_builtin(t_shell *general)
{
	int	i;
		// printf("***\n");
	// while (general->tok_lst->next->type == 9)
	// {	printf("##\n");
	// 	general->tok_lst = general->tok_lst->next;
	// }
	// warning with "export       " case
	if (!general->tok_lst->next)
		return (print_env(general->sorted_env_lst, 1), 0);
	if (export_valid(general->tok_lst->next->next) == FAILURE_EXIT)
		return (FAILURE_EXIT);
	else if (ft_strchr(general->tok_lst->next->next->context, '=') >= 0)
	{
		i = ft_strchr(general->tok_lst->next->next->context, '=');
		add_to_env_lst(*general->tok_lst->next->next, *general->env_lst, i);
	}
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

void	add_to_env_lst(t_token current_node, t_env env_lst, int i)
{
	// char	*value;
	char	*key;
	(void)env_lst;
	t_env	env_node; 

	key = my_substr(current_node.context, 0, i + 1);
	// value = my_substr(current_node.context, i + 1, ft_strlen(current_node.context) - i);
	// env_node = malloc(sizeof(t_env));
	env_node.key = key;
	env_node.value = NULL;
	env_node.next = NULL;
	// quick_sort(char **arr, int low, int high)
	// env_node.value = value;
	// printf("key = %s\n", key);
	// printf("value = %s\n", value);
	
	
}
char	**list_to_array(struct t_env_export *env)
{
	char	**matrix;
	struct t_env_export *temp;
	int	i;
	int	len;
	char	*tmp;

	len = count_env_len(env);
	matrix = (char **)malloc(sizeof(char *) * (len + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	temp = env;
	while (temp)
	{
		tmp = ft_strjoin(temp->key, "=");
		matrix[i] = ft_strjoin(tmp, temp->value);
		free(tmp);
		// printf("%s\n", matrix[i]);
		if (!matrix[i])
			return (free_array(matrix), NULL);
		i++;
		temp = temp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
