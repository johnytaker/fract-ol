#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <curses.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_complex{
	double	re;
	double	im;
}				t_complex;

typedef struct s_data{
	void	*img;
	char	*adr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->line_len + x * (data->pixel_bits / 8));
	*(unsigned int*)dst = color;
}
// int	main()
// {
// 	int A, B, i;
// 	double a, b, x, y,t,n = 15;
// 	B = 0;
// 	while (B < 4*n)
// 	{
// 		b = 2 - (B/n);
// 		A = 0;
// 		while (A <= 4 * n)
// 		{
// 			a = -2 + (A/n);
// 			x = 0;
// 			y = 0;
// 			i = 1;
// 			while (i <= 1000)
// 			{
// 				t = x;
// 				x = (x*x) - (y*y) + a; //а это х0  
// 				y = (2*t*y) + b; // b это у0
// 				if((x*x) + (y*y)>4)
// 					break;
// 				i++;
// 			}
// 			if (i == 1001)
// 				printf(".");
// 			else
// 				printf(" ");
// 			A++;
// 		}
// 		printf("\n");
// 		B++;
// 	}
// 	// getch();
// 	return (0);
// }

int	main()
{
	int A, B, i;
	double a, b, x, y,t,n = 100;

	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int			max_iteration;
	int			width;
	int			height;
	int			iteration;
	double		temp;

	width = 1000;
	height = 1000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world");
	// img = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_new_image(mlx, width, height);
	img.adr = mlx_get_data_addr(img.img,  &img.pixel_bits, &img.line_len, &img.endian);
	
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	// mlx_loop(mlx);


	B = 0;
	while (B < 4*n)
	{
		b = 2 - (B/n);
		A = 0;
		while (A <= 4 * n)
		{
			a = -2 + (A/n);
			x = 0;
			y = 0;
			i = 1;
			while (i <= 1000)
			{
				t = x;
				x = (x*x) - (y*y) + a; //а это х0  
				y = (2*t*y) + b; // b это у0
				if((x*x) + (y*y)>4)
					break;
				i++;
			}
			if (i == 1001)
				my_mlx_pixel_put(&img, A, B, 0x00FF0000);	
			A++;
		}
		// printf("\n");
		B++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, A, B);
	mlx_loop(mlx);

	// getch();
	return (0);
}