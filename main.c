/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:17:17 by bieldojt          #+#    #+#             */
/*   Updated: 2025/04/13 22:38:59 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{

	t_fractal	*fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) || \
	argc == 3 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal->name = argv[1];
		// INICIAR A APLICAÇÃO
		fractal_init(fractal);
		init_fractal_values(fractal);

		fractal_render(fractal);

		mlx_loop(fractal->mlx_connection); //looping servidor

	}
	else
	{
		write(1,"ERROR MESSAGE",13);
		exit(EXIT_FAILURE);
	}
}
