/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:47:41 by algaboya          #+#    #+#             */
/*   Updated: 2024/12/08 20:26:29 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_status = 0;

void	set_exit_status(int status)
{
	exit_status = status;
}

int	get_exit_status(void)
{
	return (exit_status);
}

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (FAILURE_EXIT);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (FAILURE_EXIT);
	while (str[i])
	{
		if (str[i] <= '0' && str[i] >= '9')
			return (FAILURE_EXIT);
		i++;
	}
	return (SUCCESS_EXIT);
}

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count] != NULL)
	{
		count++;
	}
	return (count);
}

int	is_valid(char **args, int count)
{
	// if (!args)
	// 	return (FAILURE_EXIT);
	if (count > 1 && is_num(args[1]) == FAILURE_EXIT)
	{
		write(1, "$\n", 2);
		printf("minishell: exit: %s: numeric argument required", args[1]);
		return (FAILURE_EXIT);
	}
	if (count > 1 && ft_strlen(args[1]) > 20)
	{
		printf("minishell: exit: %s: numeric argument required", args[1]);
		return (FAILURE_EXIT);
	}
	return (SUCCESS_EXIT);
}

long	ft_atol(char *str)
{
	int		sign;
	long	num;
	size_t	i;
	// int		digit;
	i = 0;
	sign = 1;
	num = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// num = str[i] - '0';
	while (str[i])
	{
		// digit = str[i] - '0';
		// if (num > (LONG_MAX - digit) / 10)
		// {
		// 	if (sign == 1)
		// 		return (LONG_MAX);
		// 	else
		// 		return (LONG_MIN);
		// }
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int exit_statusik(char *arg)
{
	int		exit;
	long	num;

	if (arg)
	{
		num = ft_atol(arg);
		printf("longnum = %ld\n", num);
		exit = num % 256;
		if (exit < 0)
			exit += 256;
		return (exit);
	}
	else
		return (exit_status);
}

int	exit_builtin(t_shell *general)
{
	int	exitik;
	int	count;

	count = count_args(general->cmd_lst->args);
	exitik = 1;
	write(STDOUT_FILENO, "exit\n", 6);
	if (is_valid(general->cmd_lst->args, count) == FAILURE_EXIT)
	{
		// write(1, "*\n", 2);
		// free_general(general);
		exit(exitik);
	}
	if (count > 3)
	{
		printf("count = %d", count);
		// write(1, "#\n", 2);
		return (printf("minishell: exit: too many arguments\n"), FAILURE_EXIT);
	}
	exitik = exit_statusik(general->cmd_lst->args[1]);
	// free_general(general);
	exit(exitik);
}
