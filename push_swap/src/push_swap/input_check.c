/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:50:54 by eschwart          #+#    #+#             */
/*   Updated: 2025/02/04 13:15:04 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static int	ft_count_args(char **argv)
{
	int		count;
	int		i;
	char	**split;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				return (-1);
			count += ft_count_split(split);
			ft_free_tab(split);
		}
		else
			count++;
		i++;
	}
	return (count);
}

static int	ft_add_split(char **split, char **args, int *j)
{
	int	i;

	i = 0;
	while (split[i])
	{
		args[*j] = ft_strdup(split[i]);
		if (!args[*j])
		{
			ft_free_tab(args);
			return (-1);
		}
		(*j)++;
		i++;
	}
	return (0);
}

static int	ft_add_split_args(char *arg, char **args, int *j)
{
	char	**split;

	split = ft_split(arg, ' ');
	if (!split)
		return (-1);
	if (ft_add_split(split, args, j) == -1)
		return (ft_free_tab(split), -1);
	ft_free_tab(split);
	return (0);
}

char	**ft_get_args(char **argv)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(char *) * (ft_count_args(argv) + 1));
	if (!args)
		return (NULL);
	i = 1;
	j = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (ft_add_split_args(argv[i], args, &j) == -1)
				return (ft_free_tab(args), NULL);
		}
		else
		{
			args[j] = ft_strdup(argv[i]);
			if (!args[j++])
				return (ft_free_tab(args), NULL);
		}
		i++;
	}
	return (args[j] = NULL, args);
}

// char	**ft_get_args(char **argv)
// {
// 	char	**args;
// 	char	**split;
// 	int		i;
// 	int		j;

// 	args = malloc(sizeof(char *) * (ft_count_args(argv) + 1));
// 	if (!args)
// 		return (NULL);
// 	i = 1;
// 	j = 0;
// 	while (argv[i])
// 	{
// 		if (ft_strchr(argv[i], ' '))
// 		{
// 			split = ft_split(argv[i], ' ');
// 			if (!split)
// 				return (ft_free_tab(args), NULL);
// 			if (ft_add_split(split, args, &j) == -1)
// 				return (ft_free_tab(args), NULL);
// 			ft_free_tab(split);
// 		}
// 		else
// 		{
// 			args[j] = ft_strdup(argv[i]);
// 			if (!args[j++])
// 				return (ft_free_tab(args), NULL);
// 		}
// 		i++;
// 	}
// 	args[j] = NULL;
// 	return (args);
// }
