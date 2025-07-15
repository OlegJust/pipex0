/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:54:02 by gcollet           #+#    #+#             */
/*   Updated: 2025/07/15 16:56:06 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);// Флаг O_RDONLY; 0777 права на файл 
	if (filein == -1)
		error();
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO); //FILENO
	dup2(filein, STDIN_FILENO);
	execute(argv[2], envp);
	close(filein);
	close(fd[1]);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	execute(argv[3], envp);
	close(fileout);
	close(fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1; //раздел "Data pid_t"

	if (argc == 5)
	{
		if (pipe(fd) == -1) //раздел "Func pipe()"
			error();
		pid1 = fork(); //fork
		if (pid1 < 0)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0); //waitpid
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
