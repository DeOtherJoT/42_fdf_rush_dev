#include "../includes/fdf.h"

void	print_coord(t_matrix *coords)
{
	printf("---\n");
	printf("x : %f\n", ft_matrix_get(coords, 0, 0));
	printf("y : %f\n", ft_matrix_get(coords, 1, 0));
	printf("z : %f\n", ft_matrix_get(coords, 2, 0));
	printf("w : %f\n", ft_matrix_get(coords, 3, 0));
}

/* ------- Actual test functions ------- */

void	test_row_get(char *file)
{
	size_t	res = ft_row_get(file);

	if (res == 9)
		printf("ft_row_get :\tSuccess!\n");
	else
		err_msg("ft_row_get : KO");
}

void	test_col_get(char *file)
{
	size_t	res = ft_col_get(file);

	if (res == 11)
		printf("ft_col_get :\tSuccess!\n");
	else
		err_msg("ft_col_get : KO");
}

void	test_map_new(char *file)
{
	t_map	*ret = parse_map(file);
	size_t	i = 0;

	while (i < (ret->col * ret->row))
	{
		print_coord(ret->coord[i]);
		i++;
	}
	printf("done");
}

int	main(int argc, char **argv)
{
	(void)argc;
	//test_row_get(argv[1]);
	//test_col_get(argv[1]);
	test_map_new(argv[1]);
}