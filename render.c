#include "fractol.h"

void converto_to_complex(t_fractal *fractal, int x, int y)
{
	fractal->shift_x = (x / WIDTH) * (fractal->a_max - fractal->a_min) + fractal->a_min;
	fractal->shift_y = (y / HEIGTH) * (fractal->b_max - fractal->b_min) + fractal->b_min;
}

int	mandelbrot(t_fractal *fractal)
{
	int		iter;
	double	a;
	double	b;
	double	a_temp;

	iter = 0;
	a = fractal->shift_x;
	b = fractal->shift_y;
	while (a * a + b * b <= 4 && iter <= fractal->iterations_defintion)
	{
		a_temp = a * a - b * b + a;
		b = 2 * a * b + fractal->shift_y;
		a = a_temp;
		iter++;
	}
	return (iter);
}
//z = z0² + c

//
//void fractal_render(t_fractal *fractal)
//{
//	int x;
//	int y;
//
//	y = 0;
//	while(y < HEIGTH)
//	{
//		x = 0;
//		while(x < WIDTH)
//		{
//			handle_pixel(x, y , fractal);
//			x++;
//		}
//		y++;
//	}
//	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win, fractal->img->img_ptr, 0, 0)
//}
//
////mudar as coordenadas do plano cartesiano para o plano complexo ok
//
// //com as coodenadas no plano complexo descobrir o numero de iterações no fractal


//(x,y) , (a,bi)
//
