/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:30:40 by algaboya          #+#    #+#             */
/*   Updated: 2024/11/11 21:29:12 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	builin(t_token *token_list)
// {
// 	if (ft_strcmp(token_list->context, "export") == 0)
// 		export_builtin(token_list->next->next);
// }

void	error_message(char *var)
{
	// while (token_list)
	printf("minishell: export: `%s': not a valid identifier\n", var);
	// return (0);
}

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*p;

// 	p = (char *)s;
// 	if (c == '\0')
// 		return (p + ft_strlen(s));
// 	while (*p)
// 	{
// 		if (*p == (unsigned char)c)
// 			return (p);
// 		p++;
// 	}
// 	return (NULL);
// }

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
