#include "monty.h"

char **tokenizer(char *input, char *delim)
{
	char *token, *input_aux, **token_arr;
	int tokens = 0, index = 0, readchars = strlen(input);

	if (!input)
		return (NULL);

	input_aux = malloc(sizeof(char) * (readchars + 1));
	if (!input_aux)
		return (NULL);
	memset(input_aux, 0, sizeof(char) * (readchars + 1));
	strcpy(input_aux, input);

	token = strtok(input, delim);
	while (token)
	{
		tokens++;
		token = strtok(NULL, delim);
	}

	token_arr = malloc(sizeof(char *) * (tokens + 1));

	token = strtok(input_aux, delim);

	while (token)
	{
		token_arr[index] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!token_arr[index])
			return (NULL);
		strcpy(token_arr[index], token);
		token = strtok(NULL, delim);
		index++;
	}
	token_arr[index] = NULL;

	free(input_aux);

	return (token_arr);
}