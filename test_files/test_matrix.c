#include "../includes/fdf.h"
#include <stdio.h>

/* ------- Tester utils ------- */

// Compares the two matrices passed as parameters. Returns 0 if equal, 1 otherwise.
int	cmp_matrix(t_matrix *matA, t_matrix *matB)
{
	size_t	i;

	if (matA->row != matB->row || matA->col != matB->col)
		return (1);
	i = 0;
	while (i < (matA->row * matA->col))
	{
		if (matA->matrix[i] != matB->matrix[i])
			return (1);
		i++;
	}
	return (0);
}

// Prints the matrix passed as the parameter.
void	print_matrix(t_matrix *matrix)
{
	size_t	i;

	i = 0;

	printf("Row = %zu\n", matrix->row);
	printf("Col = %zu\n", matrix->col);
	while (i < (matrix->row * matrix->col))
	{
		printf("%f", matrix->matrix[i]);
		if ((i + 1)%(matrix->col) == 0)
			write(1, "\n", 1);
		else
			write(1, "\t", 1);
		i++;
	}
}

/* ------- Actual test functions ------- */

void	test_matrix_new(void)
{
	t_matrix    *matrix;
	size_t      test_row = 4;
	size_t      test_col = 4;
	size_t      i = 0;

	matrix = ft_matrix_new(test_row, test_col);

	if (matrix->row != test_row || matrix->col != test_col)
	{
		printf("ft_matrix_new : KO!\n");
		return ;
	}
	while (i < (test_row * test_col))
	{
		if (matrix->matrix[i] != 0)
		{
			printf("ft_matrix_new : KO!\n");
			return ;
		}
		i++;
	}
	printf("ft_matrix_new :\t\tSuccess!\n");
	ft_matrix_del(matrix);
}

void	test_matrix_get(void)
{
	t_matrix    *matrix;
	size_t      i = 0;
	size_t      j;

	matrix = ft_matrix_new(3, 3);
	while (i < matrix->row)
	{
		j = 0;
		while (j < matrix->col)
		{
			if (ft_matrix_get(matrix, i, j) != 0)
			{
				printf("ft_matrix_get : KO!\n");
				return ;
			}
			j++;
		}
		i++;
	}
	printf("ft_matrix_get :\t\tSuccess!\n");
	ft_matrix_del(matrix);
}

void	test_matrix_set(void)
{
	t_matrix    *matrix;
	float       val = 100;

	matrix = ft_matrix_new(5, 5);
	ft_matrix_set(matrix, 2, 2, val);
	if (ft_matrix_get(matrix, 2, 2) != val)
	{
		printf("ft_matrix_set : KO!\n");
		return ;
	}
	printf("ft_matrix_set :\t\tSuccess!\n");
	ft_matrix_del(matrix);
}

void	test_matrix_create(void)
{
	t_matrix    *matA;
	t_matrix    *matB;
	double      data_A[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
	size_t      i = 0;

	matA = ft_matrix_create(3, 3, data_A);
	matB = ft_matrix_new(3, 3);

	while (i < 9)
	{
		ft_matrix_set(matB, i / 3, i % 3, i + 1);
		i++;
	}

	int j = cmp_matrix(matA, matB);

	if (j == 1)
	{
		printf("ft_matrix_create : KO!\n");
		return ;
	}
	printf("ft_matrix_create :\tSuccess!\n");
	ft_matrix_del(matA);
	ft_matrix_del(matB);
}

void	test_matrix_mult(void)
{
	t_matrix    *matA;
	t_matrix    *matB;
	t_matrix    *result;
	double      data_A[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	double      data_B[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	double      data_ans[] = {22.0, 28.0, 49.0, 64.0};

	matA = ft_matrix_create(2, 3, data_A);
	matB = ft_matrix_create(3, 2, data_B);

	result = ft_matrix_mult(matA, matB);

	t_matrix    *ans = ft_matrix_create(2, 2, data_ans);

	int j = cmp_matrix(ans, result);

	if (j == 1)
	{
		printf("ft_matrix_mult : KO!\n");
		return ;
	}
	printf("ft_matrix_mult :\tSuccess!\n");
	ft_matrix_del(matA);
	ft_matrix_del(matB);
	ft_matrix_del(result);
	ft_matrix_del(ans);
}

void    test_matrix_ident(void)
{
	t_matrix    *matA;
	t_matrix    *matB;
	double      data[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

	matA = ft_matrix_ident(3);
	matB = ft_matrix_create(3, 3, data);

	if (cmp_matrix(matA, matB) == 0)
		printf("ft_matrix_ident :\tSuccess!\n");
	else
		printf("ft_matrix_ident : KO!\n");
	ft_matrix_del(matA);
	ft_matrix_del(matB);
}

void    test_matrix_swap(void)
{
	t_matrix    *matA;
	t_matrix    *matB;
	t_matrix    *matC;
	t_matrix    *matD;
	double      data_A[] = {1.0, 2.0, 3.0, 4.0};
	double      data_B[] = {1.0, 2.0, 3.0, 4.0};
	double      data_C[] = {5.0, 6.0, 7.0, 8.0};
	double      data_D[] = {5.0, 6.0, 7.0, 8.0};

	matA = ft_matrix_create(2, 2, data_A);
	matB = ft_matrix_create(2, 2, data_B);
	matC = ft_matrix_create(2, 2, data_C);
	matD = ft_matrix_create(2, 2, data_D);

	ft_matrix_swap(matA, matC);

	if (cmp_matrix(matA, matD) == 0 && cmp_matrix(matB, matC) == 0)
		printf("ft_matrix_swap :\tSuccess!\n");
	else
		printf("ft_matrix_swap : KO!\n");

	ft_matrix_del(matA);
	ft_matrix_del(matB);
	ft_matrix_del(matC);
	ft_matrix_del(matD);
}

void    test_matrix_mult_swp(void)
{
	t_matrix    *res_mult;
	t_matrix    *matA;
	t_matrix    *matB;
	double      data_A[] = {1.0, 2.0, 3.0, 4.0};
	double      data_B[] = {4.0, 3.0, 2.0, 1.0};

	matA = ft_matrix_create(2, 2, data_A);
	matB = ft_matrix_create(2, 2, data_B);

	res_mult = ft_matrix_mult(matA, matB);

	ft_matrix_mult_swp(matA, matB);

	if (cmp_matrix(res_mult, matA) == 0)
		printf("ft_matrix_mult_swp :\tSuccess!\n");
	else
		printf("ft_matrix_mult_swp : KO!\n");

	ft_matrix_del(res_mult);
	ft_matrix_del(matA);
	ft_matrix_del(matB);
}

void	test_matrix_cp(void)
{
	t_matrix	*matA = ft_matrix_ident(5);
	t_matrix	*matB;

	matB = ft_matrix_cp(matA);
	if (cmp_matrix(matA, matB) == 0)
		printf("ft_matrix_cp :\t\tSuccess!\n");
	else
		printf("ft_matrix_cp : KO!\n");
	ft_matrix_del(matA);
	ft_matrix_del(matB);
}

void	test_transform_theory(void)
{
	t_matrix	*matA = ft_matrix_ident(4);

	ft_matrix_rotate_z(matA, 45);
	print_matrix(matA);
}

int main(void)
{
	// test_matrix_new();
	// test_matrix_get();
	// test_matrix_set();
	// test_matrix_create();
	// test_matrix_ident();
	// test_matrix_mult();
	// test_matrix_swap();
	// test_matrix_mult_swp();
	// test_matrix_cp();
	test_transform_theory();
}
