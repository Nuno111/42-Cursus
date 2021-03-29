#include <mlx.h>
#include <stdio.h>
typedef struct vars
{
    void    *mlx;
    void    *win;
    void    *img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}               var;


void	my_mlx_pixel_put(var *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_img(var *node, int x)
{
	int i = x;
	int j = 0;
	while (i < 400)
	{
		my_mlx_pixel_put(node, i, j, 0xff55ff);
		i++;
		j++;
	}
}

int render_next_frame(int keycode, var *node)
{
	printf("%s\n", "hello");

	if (keycode == 119)
	{
		mlx_clear_window(node->mlx, node->win);
	}
	if (keycode == 115)
		mlx_put_image_to_window(node->mlx, node->win, node->img, 0, 0);

	return 0;
}

int     main(void)
{
    var node;

    node.mlx = mlx_init();
	node.win = mlx_new_window(node.mlx, 800, 600, "testing");
    node.img = mlx_new_image(node.mlx, 800, 600);
    node.addr = mlx_get_data_addr(node.img, &node.bits_per_pixel, &node.line_length, &node.endian);
	draw_img(&node, 200);
	mlx_put_image_to_window(node.mlx, node.win, node.img, 0, 0);
 	mlx_hook(node.win, 2, 1L<<0, render_next_frame, &node);
    mlx_loop(node.mlx);
}

