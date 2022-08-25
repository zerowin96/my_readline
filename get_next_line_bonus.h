/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:58:22 by yeham             #+#    #+#             */
/*   Updated: 2022/08/21 13:50:13 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

int		gnl_strlen(const char *s);
char	*gnl_strdup(const char *s1);
int		gnl_check(char *storage);
char	*line_maker(int fd, char *buf, char *storage);
char	*namuji(char *line);
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif
