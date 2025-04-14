#include "fractol.h"

static void malloc_error(void)
{
	perror("problems with malloc");
	exit(EXIT_FAILURE);
}

void	init_img(t_fractal *fractal)
{
	fractal->img = malloc(sizeof(t_img));
	if (fractal->img == NULL)
		malloc_error();
	fractal->img->img_ptr = NULL;
	fractal->img->pixels_ptr = NULL;
	fractal->img->bpp = 0;
	fractal->img->line_len = 0;
	fractal->img->endian = 0;

	fractal->img->img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGTH);
	fractal->img->pixels_ptr = mlx_get_data_addr(fractal->img->img_ptr, &fractal->img->bpp,\
		&fractal->img->line_len,  &fractal->img->endian );
}

void	fractal_init(t_fractal *fractal)
{
	t_fractal	*a;

	a = malloc(sizeof(t_fractal));
	if (a == NULL)
		malloc_error();
	fractal = a;
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_connection,WIDTH, HEIGTH, fractal->name);
	if(fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	init_img(fractal);
	if(fractal->img->img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
}

void	init_fractal_values(t_fractal *fractal)
{
	//delimita o espaco do plano complexo na tela
	fractal->shift_x = 0;
	fractal->shift_y = 0;

	fractal->a_max = 2.0;
	fractal->a_min = -2.0;
	fractal->b_max = 2.0;
	fractal->b_min = -2.0;

	fractal->zoom = 1;
	fractal->julia_x = 0.285;
	fractal->julia_y = 0.01;
	fractal->iterations_defintion = 100;
	fractal->escape_value = 2;
}
