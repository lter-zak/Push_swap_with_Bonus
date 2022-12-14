/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:46:58 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/24 21:04:17 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_firs_join(char *str)
{	
	int		len ;
	char	*arr;
	int		j;

	j = 0;
	len = ft_strlen(str);
	arr = malloc(len + 2);
	while (str[j])
	{
		arr[j] = str[j];
		j++;
	}
	arr[len] = ' ';
	arr[len + 1] = '\0';
	return (arr);
}

char	*ft_join_str(char **str)
{
	int		i;
	char	*arr;

	i = 1;
	arr = ft_firs_join(str[i]);
	i++;
	while (str[i])
	{
		arr = ft_strjoin(arr, str[i]);
		i++;
	}
	i = 0;
	return (arr);
}

int	*char_to_int(int len, char **map)
{
	int	i;
	int	j;
	int	*arr;
	int	count;

	count = 0;
	i = 0;
	arr = malloc(sizeof(int) * len + 1);
	while (map[i])
	{
		j = 0;
		count = 0;
		while (map[i][j] != '\0' && map[i][j] == '0')
			j++;
		while (map[i][j++] != '\0')
			count++;
		if (count > 16)
			print_error();
		arr[i] = ft_atoi(map[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void	free_leakc(t_list **list)
{
	t_list	*next;

	while ((*list) != NULL)
	{
		next = (*list)->next;
		free((*list));
		(*list) = next;
	}
}
