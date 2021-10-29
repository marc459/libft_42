/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:18:04 by marcos            #+#    #+#             */
/*   Updated: 2021/10/29 23:22:07 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_strjoinchar(char *s, char c)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s) + 2);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(s);
	return (dest);
}

int	get_next_line(char **line)
{
	int		ret;
	char	buf[2];

	*line = ft_strdup("");
	if (line == NULL || !*line)
		return (-1);
	ret = read(0, buf, 1);
	while (ret > 0)
	{
		if (buf[0] == '\n')
			break ;
		*line = ft_strjoinchar(*line, buf[0]);
		ret = read(0, buf, 1);
	}
	return (ret);
}