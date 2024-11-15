/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:42:13 by etamazya          #+#    #+#             */
/*   Updated: 2024/11/15 18:48:29 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ************************
// *** WARNING *** FULL ***
// ************************

int main(int argc, char **argv, char **env)
{
    (void)argv;
    t_shell *general;
    char    *input;

    input = NULL;
    general = malloc(sizeof(t_shell));
    if (!general)
        return (1);
    if (argc == 1)
    {
        if (init_input(input, general, env)) // if 1 error
            return (free(general), 1);
    }
    return (free(general), 0);
}