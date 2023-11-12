#include <stdlib.h>

char	*ft_new_string(char *str);
char	**ft_string_allocate(char *str)
{
	char **dict_string;
	int  string_count;
	int	i;

	string_count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			string_count++;
		i++;
	}
	dict_string = (char **)malloc(sizeof(char *) * (string_count + 1));
	i = 0;
	while (*str)
	{
        while (*str != ':')
			str++;
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			dict_string[i] = ft_new_string(str);
            i++;
			while (*str != '\n')
				str++;
		}
	}
    dict_string[i] = NULL;
    return (dict_string);
}

char	*ft_new_string(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}