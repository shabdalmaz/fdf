#include "fdf.h"

void    iso(int *x, int *y, int z)
{
        *x = (*x - *y) * cos(1);
        *y = (*x + *y) * sin(0.5) - z;
}

void	switch_projection(t_mx *mx)
{
	if (mx->iso)
		mx->iso = 0;
	else
		mx->iso = 1;
	mlx_clear_window(mx->mlx_ptr, mx->win_ptr);
	get_picture(mx);
}
