#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

void ft_putstr(char *str);
char *read_dictionary(char *str);
int ft_strcmp(char *string1, char *string2);
char	*ft_new_num(char *str);
int	ft_isspace(char c);
char	**ft_num_allocate(char *str);
char	*ft_new_num(char *str);
char	**ft_string_allocate(char *str);
char	*ft_new_string(char *str);

int main(int argc, char **argv)
{
	char *out;
	char **ref_num;
	char **ref_string;
	int i;

	if((argc < 2) || (argc > 3))
		return (0);
	else
	{
		if ((argc == 2) && !(check_error(argv[1])))
		{
			out = read_dictionary("numbers");
			ref_num = ft_num_allocate(out);
			printf("%s\n",ref_num[30]);
			ref_string = ft_string_allocate(out);
			printf("%s\n",ref_string[30]);
			i = 0;
			printf("ARGV: %s\n",argv[1]);
			while (ref_num[i] != NULL)
			{
				printf("%d\n", (ft_strcmp(argv[1],ref_num[i]) == 0));
				if (ft_strcmp(argv[1],ref_num[i]) == 0)
				{
					ft_putstr(ref_string[i]);
					break ;
				}
				i++;
			}
			return (0);
		}
		else
			ft_putstr("Error\n");
		if ((argc == 3) && (argv[2][0] == '-'))
		{
			ft_putstr("Error\n");
			return (0);
		}
		else
			ft_putstr("Error\n");
	}
	return (0);
}

void ft_putstr(char *str)
{
	while(*str != '\0')
	{
		write(1,&*str,1);
		str++;
	}
}

char *read_dictionary(char *str)
{
	char *result;
	int  fd;
	int	 buffer_total;
	char raw[BUFFER_SIZE + 1];

	result = 0;
	if(ft_strcmp(str,"numbers") == 0)
	{
		fd = open("./dict/numbers.dict", O_RDONLY);
		if (fd > 0)
		{
			buffer_total = read(fd, raw, BUFFER_SIZE);
			raw[buffer_total] = '\0';
		}
		close(fd);
	}
	result = raw;
	return (result);
}

char	**ft_num_allocate(char *str)
{
	char **dict_num;
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
	dict_num = (char **)malloc(sizeof(char *) * (string_count + 1));
	i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			dict_num[i] = ft_new_num(str);
			i++;
			while (*str != '\n')
				str++;
		}
	}
	dict_num[i] = NULL;
	return (dict_num);
}
char	*ft_new_num(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] != '\0' && (!ft_isspace(str[i])) && (str[i] != ':'))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0' && (!ft_isspace(str[i])) && (str[i] != ':'))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

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
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int ft_strcmp(char *string1, char *string2)
{
	int r;
	int i;

	i = 0;
	r = 0;
	while((string1[i] == string2[i]) && (string1[i] != '\0'))
		i++;
	if(string1[i] != string2[i])
		r = string1[i] - string2[i];
	return (r);
}

int	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_convert(char **dict_num, char **dict_string, char *input)
{
	int	nb;

	nb = ft_atoi(input);
	while(nb > 0)
	{

	}
}

int ft_get_zeroes(int nb)
{
	int digits;
	int i;
	int result;
	int count;

	i = 1;
	digits = 0;
	result = 1;
	while ( nb != 0)
	{
		nb /= 10;
		digits++;
	}
	while (i < digits)
	{
		result *= 10;
		i++;
	}
	return result;
}

