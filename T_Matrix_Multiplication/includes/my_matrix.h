#ifndef MY_MATRIX_H
# define MY_MATRIX_H
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_matrix
{
    size_t  row;
    size_t  col;
    double  *matrix;
}   t_matrix;

/* Basic Utils */
void    *ft_calloc(size_t n_elem, size_t t_size);
void    ft_putnbr(int n);

/* Matrix Functions */
int     ft_init_matrix(size_t rows, size_t col, t_matrix *matrix);
void    ft_del_matrix(t_matrix *matrix);
int     ft_get_elem(size_t row, size_t col, t_matrix *matrix);
void    ft_place_val(size_t row, size_t col, double val, t_matrix *matrix);
void    ft_print_matrix(t_matrix *matrix);
#endif