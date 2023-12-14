#include "main.h"

void exit_shell()
{
    exit(status);
}
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t bytesRead;
	size_t tokenCount = 0;
	char *tokens[MAX_TOKENS];

	while (1)
	{
		bytesRead = getline(&input, &len, stdin);
		if (bytesRead == -1)
	       	{
			free(input);
			exit(status);
		}

		input[bytesRead - 1] = '\0';
		tokenCount = 0;
		tokens[tokenCount] = strtok(input, " \n");

		while (tokens[tokenCount] != NULL && tokenCount < MAX_TOKENS - 1)
	       	{
			tokenCount++;
			tokens[tokenCount] = strtok(NULL, " \n");
		}

		if (strcmp(input, "exit") == 0)
	       	{
			free(input);
			exit_shell();
		}

                if (tokens[0] == NULL)
                {
                        continue;
                }
		executeCommand(tokens, env);
	}
	free(input);
}

