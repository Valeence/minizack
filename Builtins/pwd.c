/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:43:31 by vandre            #+#    #+#             */
/*   Updated: 2024/04/24 09:11:22 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/MiniShell.h"

int ft_pwd()
{
    char path[1024];

    if (getcwd(path, sizeof(path)) != NULL)
        printf("%sbolose\n", path);
    else
    {
        perror("getcwd() error");
        return 0;
    }
    return 1;
}
