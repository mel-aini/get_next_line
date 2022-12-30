/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:16:27 by mel-aini          #+#    #+#             */
/*   Updated: 2022/11/22 20:36:45 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	int				bytes;
	static char		*holder[OPEN_MAX];
	char			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !check_line(holder[fd], '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(holder[fd]), (NULL));
		buffer[bytes] = '\0';
		holder[fd] = join(holder[fd], buffer);
	}
	tmp = holder[fd];
	line = save(tmp, '\n');
	holder[fd] = remain(holder[fd], '\n');
	return (free(tmp), free(buffer), line);
}
