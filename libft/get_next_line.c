/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:08:37 by evila-ro          #+#    #+#             */
/*   Updated: 2020/11/06 19:09:59 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_endretro(char **line, char **last, int bwr)
{
	char	*tmp;
	char	*tmp2;

	if (bwr < 0)
		return (-1);
	if (!bwr && !*last)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((tmp = ft_strchr(*last, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*last);
		tmp2 = ft_strdup(++tmp);
		free(*last);
		*last = tmp2;
	}
	else
	{
		*line = *last;
		*last = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int				bwr;
	char			buf[BUFFER_SIZE + 1];
	static char		*last[MAX_SIZE];
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	while ((bwr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bwr] = '\0';
		if (last[fd] == NULL)
			last[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(last[fd], buf);
			free(last[fd]);
			last[fd] = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_endretro(line, &last[fd], bwr));
}
