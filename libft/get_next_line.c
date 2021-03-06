/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:26 by sthitiku          #+#    #+#             */
/*   Updated: 2022/06/14 15:09:46 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	bsn_pos(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_file(int fd, char *str)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	int		fbyte;

	fbyte = read(fd, buf, BUFFER_SIZE);
	if (fbyte <= 0 || str == NULL)
	{
		if (str == NULL || str[0] != '\0')
			return (str);
		free(str);
		return (NULL);
	}
	while (fbyte > 0)
	{
		tmp = (char *)malloc(ft_strlen(str) + fbyte + 1);
		tmp[0] = '\0';
		gnl_strlcpy(tmp, str, ft_strlen(str) + 1);
		gnl_strlcpy(&tmp[ft_strlen(str)], buf, fbyte + 1);
		free(str);
		if (bsn_pos(tmp) != -1)
			break ;
		str = tmp;
		fbyte = read(fd, buf, BUFFER_SIZE);
	}
	return (tmp);
}

char	*shift_str(char *str)
{
	char	*new;
	size_t	new_len;
	int		pos;

	if (bsn_pos(str) == -1)
	{
		free(str);
		return (NULL);
	}
	pos = bsn_pos(str);
	new_len = ft_strlen(str) - pos;
	new = (char *)malloc(sizeof(char) * new_len);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	gnl_strlcpy(new, &str[pos + 1], new_len);
	free(str);
	return (new);
}

char	*get_ans(char *str)
{
	char	*ans;
	int		pos;

	pos = bsn_pos(str);
	if (pos < 0)
	{
		ans = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!ans)
		{
			free(str);
			return (NULL);
		}
		gnl_strlcpy(ans, str, ft_strlen(str) + 1);
		return (ans);
	}
	ans = (char *)malloc(sizeof(char) * (pos + 2));
	if (!ans)
	{
		free(str);
		return (NULL);
	}
	gnl_strlcpy(ans, str, pos + 2);
	return (ans);
}

char	*get_next_line(int fd)
{
	static t_read	*readf = NULL;
	t_read			*curr;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	curr = check_fd(readf, fd);
	if (!curr)
		return (NULL);
	if (!readf)
		readf = curr;
	curr->str = read_file(fd, curr->str);
	if (!curr->str || *(curr->str) == '\0')
	{
		readf = clear_read(readf, fd);
		return (NULL);
	}
	ret = get_ans(curr->str);
	if (!ret)
	{
		readf = clear_read(readf, fd);
		return (NULL);
	}
	curr->str = shift_str(curr->str);
	return (ret);
}
