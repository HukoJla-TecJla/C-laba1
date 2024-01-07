#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>



enum statusfunc
{
	argument_error = 1
};

int str_cmp(const char*, const char*);
int str_len(const char*);
char* str_reversed(const char*);
char* str_change_registr(const char*);
char* str_sort(const char*);
char* str_concatenation(unsigned int, char* [], unsigned int);
void str_cpy(char*, const char*);

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");

	if (str_cmp("-1", argv[1]) == 0)
	{
		if (argc != 3)
		{
			return argument_error;
		}
		printf("%d", str_len(argv[2]));
	}

	else if (str_cmp("-r", argv[1]) == 0)
	{
		if (argv[2] == NULL)
		{
			return argument_error;
		}
		printf("%s", str_reversed(argv[2]));
	}

	else if (str_cmp("-u", argv[1]) == 0)
	{
		if (argv[2] == NULL)
		{
			return argument_error;
		}
		printf("%s", str_change_registr(argv[2]));
	}

	else if (str_cmp("-n", argv[1]) == 0)
	{
		if (argv[2] == NULL)
		{
			return argument_error;
		}
		printf("%s", str_sort(argv[2]));
	}

	else if (str_cmp("-c", argv[1]) == 0)
	{
		if (argv[2] == NULL)
		{
			return argument_error;
		}
		unsigned int seed = atoi(argv[2]);
		printf("%s\n\n", str_concatenation(argc, argv, seed));
	}
}

str_cmp(const char* flag, const char* argv)
{
	int index = 0;
	if (sizeof(flag) != sizeof(argv))
	{
		return 1;
	}
	do
	{
		if (argv[index] != flag[index])
		{
			return 1;
		}
	} while (argv[index++] != '\0');

	return 0;
}

int str_len(const char* string)
{
	int index = 0;
	int count = 0;
	while (string[index] != '\0')
	{
		count++;
		index++;
	}
	return count;
}

char* str_reversed(const char* old_string)
{
	int index = 0;
	int len_old_string = str_len(old_string);
	char* new_string = (char*)malloc((len_old_string + 1) * sizeof(char));

	if (new_string == NULL)
	{
		return NULL;
	}

	for (int i = len_old_string - 1; i >= 0; i--)
	{
		new_string[index] = old_string[i];
		index++;
	}

	new_string[index] = '\0';

	return new_string;
}

char* str_change_registr(const char* old_string)
{
	int len_old_string = str_len(old_string);
	char* new_string = (char*)malloc((len_old_string + 1) * sizeof(char));

	if (new_string == NULL)
	{
		return NULL;
	}

	/*for (int i = 0; i <= len_old_string; i++)
	{
		if (old_string[i] >= 'a' && old_string[i] <= 'z')
		{
			new_string[i] = old_string[i] - '$';
		}
		else
		{
			new_string[i] = old_string[i];
		}
	}*/

	for (int i = 0; i <= len_old_string; i++)
	{
		if (i % 2 == 0)
		{
			new_string[i] = old_string[i];
		}
		else
		{
			new_string[i] = toupper(old_string[i]);
		}
	}
	new_string[len_old_string + 1] = '\0';

	return new_string;
}

/*char* str_sort(const char* old_string)
{
	int count_int = 0;
	int count_char = 0;
	int count_symbol = 0;
	int flag = 0;
	for (int i = 0; i < str_len(old_string); i++)
	{
		if (old_string[i] >= '0' && old_string[i] <= '9')
		{
			count_int++;
		}
		else if ((old_string[i] >= 'A' && old_string[i] <= 'Z') || (old_string[i] >= 'a' && old_string[i] <= 'z'))
		{
			count_char++;
		}
		else
		{
			count_symbol++;
		}
	}
	char* str_int = (char*)malloc(count_int * sizeof(char));
	char* str_char = (char*)malloc(count_char * sizeof(char));
	char* str_symbol = (char*)malloc(count_symbol * sizeof(char));

	int count_res2 = 0;
	int count_res3 = 0;
	int count_res4 = 0;

	for (int i = 0; i < str_len(old_string); i++)
	{
		if (old_string[i] >= '0' && old_string[i] <= '9')
		{
			str_int[count_res2] = old_string[i];
			count_res2++;
		}
		else if ((old_string[i] >= 'A' && old_string[i] <= 'Z') || (old_string[i] >= 'a' && old_string[i] <= 'z'))
		{
			str_char[count_res3] = old_string[i];
			count_res3++;
		}
		else
		{
			str_symbol[count_res4] = old_string[i];
			count_res4++;
		}
	}
	str_int[count_res2++] = '\0';
	str_char[count_res3++] = '\0';
	str_symbol[count_res4++] = '\0';

	int new_str_len = 0;
	if (str_int != NULL)
	{
		new_str_len += str_len(str_int);
	}
	if (str_char != NULL)
	{
		new_str_len += str_len(str_char);
	}
	if (str_int != NULL)
	{
		new_str_len += str_len(str_symbol);
	}
	int count_res = 0;
	char* new_string = (char*)malloc(new_str_len * sizeof(char));

	for (int i = 0; i < count_int; i++)
	{
		new_string[count_res] = str_int[i];
		count_res++;
	}
	for (int j = 0; j < count_char; j++)
	{
		new_string[count_res] = str_char[j];
		count_res++;
	}
	for (int t = 0; t < count_symbol; t++)
	{
		new_string[count_char] = str_symbol[t];
		count_char++;
	}
	new_string[count_char++] = '\0';
	return new_string;
}*/

char* str_sort(const char* old_string)
{
	int lenth = str_len(old_string);
	char* new_str = (char*)malloc(lenth * sizeof(char));
	int count = 0;
	for (int i = 0; i < lenth; ++i)
	{
		if (isdigit(old_string[i]) != 0)
		{
			new_str[count] = old_string[i];
			count++;
		}
	}

	for (int i = 0; i < lenth; ++i)
	{
		if (isalpha(old_string[i]) != 0)
		{
			new_str[count] = old_string[i];
			count++;
		}
	}

	for (int i = 0; i < lenth; ++i)
	{
		if (isalpha(old_string[i]) == 0 && isdigit(old_string[i]) == 0)
		{
			new_str[count] = old_string[i];
			count++;
		}
	}

	new_str[count] = '\0';
	return new_str;
}

void str_cpy(char* destination, const char* source)
{
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}

char* str_concatenation(unsigned int argc, char* argv[], unsigned int seed)
{
	srand(seed);
	unsigned int* array_index_str = (unsigned int*)malloc((argc - 3) * sizeof(unsigned int));
	unsigned int count3 = 0;
	for (unsigned int i = 3; i < (argc - 2); i++)
	{
		array_index_str[count3] = i;
		count3++;
	}

	for (unsigned int i = argc - 4; i >= 0; i--)
	{
		unsigned int new_index = rand() % (i + 1);
		unsigned int temp = array_index_str[i];
		array_index_str[i] = array_index_str[new_index];
		array_index_str[new_index] = temp;
	}
	unsigned int sum_len_strings = 0;
	for (unsigned int i = 0; i < argc - 3; i++)
	{
		sum_len_strings += str_len(argv[array_index_str[i]]);
	}
	char* concatenation_string = (char*)malloc((sum_len_strings + 1) * sizeof(char));
	if (concatenation_string == NULL)
	{
		free(array_index_str);
		return NULL;
	}

	/*unsigned int count = 0;
	unsigned int count2 = 0;
	for (unsigned int i = 0; i < argc; i++)
	{
		char* string = argv[array_index_str[i]];
		for (unsigned int j = count; j < str_len(string); j++)
		{
			concatenation_string[j] = string[j - count];
			count2++;
		}
		count = count2++;
	}


	concatenation_string[count2++] = '\0';*/

	unsigned int current = 0;
	for (unsigned int i = 0; i < (argc - 2); i++)
	{
		unsigned int lenth = str_len(argv[array_index_str[i]]);
		str_cpy(concatenation_string + current, argv[array_index_str[i]]);
		current += lenth;
	}
	return concatenation_string;
}