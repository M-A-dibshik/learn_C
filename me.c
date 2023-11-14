#include "main.h"

int main(void)
{
	int i, a, j;
	pid_t pid;
	size_t n;
	char *l;
	char **arr;
	char *token;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
		a = getline(&l, &n, stdin);
		if (a == -1)
			return (0);
		
		arr = malloc(sizeof(char *) * 1111);
		token = strtok(l, " \n\t");
		while (token != NULL)
		{
			token = strtok(NULL, " \n\t");
		}

		//arr = malloc(sizeof(char *) * 1111);
		pid = fork();

		if (pid == 0)
		{
			execve(l, arr, NULL);
		}
		else
		{
			wait(&i);
		}
	}
	free(l);
	return (0);
}
