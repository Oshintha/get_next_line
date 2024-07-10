/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:29:24 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/09 17:07:28 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static void	free_stash(char **stash)
{
	if (*stash != NULL)
	{
		free (*stash);
		*stash = NULL;
	}
	return ;
}

static void	check_validity(ssize_t bytes_read, char **stash)
{
	if (bytes_read < 0)
		free_stash(stash);
	if ((bytes_read == 0 && (*stash == NULL || *stash[0] == '\0')))
		free_stash(stash);
	return ;
}

static void	reader(int fd, char **stash, char **temp)
{
	ssize_t		bytes_read;
	char		buff[BUFFER_SIZE + 1];

	bytes_read = read(fd, buff, BUFFER_SIZE);
	check_validity(bytes_read, stash);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (!*stash)
			*stash = ft_strdup(buff);
		else
		{
			*temp = ft_strjoin(*stash, buff);
			free (*stash);
			*stash = *temp;
		}
		if (ft_strchr(*stash, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader(fd, &stash, &temp);
	if (stash)
	{
		line = extract_line(stash);
		if (!line)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		temp = ft_strdup(stash + ft_strlen(line));
		free(stash);
		stash = temp;
	}
	return (line);
}


#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;
	fd1 = open("tests/test1.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		/*line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);*/
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}