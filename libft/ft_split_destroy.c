/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:36:52 by mfirdous          #+#    #+#             */
/*   Updated: 2023/04/27 12:36:53 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_destroy(char **a)
{
	int	i;

	i = -1;
	if (a)
	{
		while (a[++i])
			free(a[i]);
		free(a);
	}
}
