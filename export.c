/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:35:06 by algaboya          #+#    #+#             */
/*   Updated: 2024/11/15 20:29:12 by algaboya         ###   ########.fr       */
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
		// int j = 0;
		i = ft_strchr(general->tok_lst->next->next->context, '=');
		add_to_env_lst(*general->tok_lst->next->next, &general->env_lst, i);
		// while (general->env_lst)
		// {
		// 	printf("new = %s", general->env_lst->key);
		// 	printf("%s\n", general->env_lst->value);
		// 	general->env_lst = general->env_lst->next;
		// }
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

void	add_to_env_lst(t_token cur_node, t_env **env_lst, int i)
{
	char	*value;
	char	*key;
	// (void)env_lst;
	t_env	env_node; 
	char	**new;
	// int j = 0;

	new = NULL;
	int u = 0;
	while (u < 2)
	{
	key = my_substr(cur_node.context, 0, i + 1);
	value = my_substr(cur_node.context, i + 1, ft_strlen(cur_node.context) - i);
	env_node.key = key;
	env_node.value = value;
	env_node.next = NULL;
	// printf("key / %s\n", key);
	// printf("value / %s\n", value);
	ft_lstadd_back(env_lst, &env_node);
	// while (env_lst)
	// {
	// 	tmp = env_lst;
	// 	env_lst = env_lst->next;
	// 	free(tmp->key);
	// 	free(tmp->value);
	// 	free(tmp);
    // }
	u++;}
	// new = sort_env(list_to_array(env_lst));
	// env_lst = init_env_nodes(new);
	// init_env_nodes(char **env);
	// quick_sort(char **arr, int low, int high)
	// env_node.value = value;

	// while(new[j])
	// {
	// 	printf("new = %s\n", new[j]);
	// 	j++;
	// }
	// while (env_lst)
	// 	{
	// 		printf("new = %s", env_lst->key);
	// 		printf("%s\n", env_lst->value);
	// 		env_lst = env_lst->next;
	// 	}
	// return(*init_env_nodes(new));
}

char	**list_to_array(t_env *env)
{
	int		i;
	int		len;
	char	*tmp;
	char	**str;
	t_env	*env_temp;

	len = count_lst_len(env);
	str = (char **)malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	env_temp = env;
	while (env_temp)
	{
		tmp = ft_strjoin(env_temp->key, "=");
		str[i] = ft_strjoin(tmp, env_temp->value);
		free(tmp);
		// printf("%s\n", str[i]);
		if (!str[i])
			return (free_array(str), NULL);
		i++;
		env_temp = env_temp->next;
	}
	str[i] = NULL;
	return (str);
}

int	count_lst_len(t_env *env_lst)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env_lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
