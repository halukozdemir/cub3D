#include "../../lib/cub3d.h"

char    cf_count_checker(t_textures *textures)
{
    int count;
    count = 0;
    while (textures->c[count])
        count++;
    if (count != 3)
        return (EXIT_FAILURE);
    count = 0;
    while (textures->f[count])
        count++;
    if (count != 3)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

char	**ft_realloc(char **array, char *new_element)
{
	char	**new_array;
	int		size;

	if (!array)
	{
		new_array = ft_calloc(2, sizeof(char *));
		if (!new_array)
			return (NULL);
		new_array[0] = ft_strdup(new_element);
		return (new_array);
	}
	size = 0;
	while (array[size])
		size++;
	new_array = ft_calloc(size + 2, sizeof(char *));
	if (!new_array)
		return (NULL);
	size = 0;
	while (array[size])
	{
		new_array[size] = array[size];
		size++;
	}
	new_array[size] = ft_strdup(new_element);
	return (free(array), new_array);
}

char	ft_is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_strchr(" \t\n\v\f", *line))
			return (EXIT_FAILURE);
		line++;
	}
	return (EXIT_SUCCESS);
}