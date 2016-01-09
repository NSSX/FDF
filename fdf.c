#include "mlx.h"
#include <stdio.h>
#include "libft/libft.h"
//Const fill_rect
#define RECTX 10
#define RECTY 10


void draw_line(void *mlx, void *win, float x1, float y1, float x2, float y2, int color)
{
  float a;
  float newx;
  float newy;
  float b;
  int i;
  int e;
  float xfin;
  float yfin;
  int temp;

  temp = 0;
    if(x2 < x1)
    {
      temp = x1;
      x1 = x2;
      x2 = temp;
      temp = y1;
      y1 = y2;
      y2 = temp;
      }
  xfin = x2;
  yfin = y2;
  e = 0;
  i = 0;
  if(x1 != x2)
    {
      while(e == 0)
	{
	  newx = x1 + 0.5;
	  a = (y1 - y2) / (x1 - x2);
	  b = y2 - (a * x2) ;
	  newy = a * newx + b;
	  mlx_pixel_put(mlx, win, newx, newy, color);
	  if(newx == xfin && newy == yfin)
	    e++;
	  y1 = newy;
	  x1+= 0.5;
	}
    }
  else
    {
      while(e == 0)
        {
          newy = y1 + 0.5;
          a = (x1 - x2) / (y1 - y2);
          b = x2 - (a * y2) ;
          newx = a * newy + b;
          mlx_pixel_put(mlx, win, newx, newy, color);
          if(newx == xfin && newy == yfin)
            e++;
          x1 = newx;
          y1+= 0.5;
        }
    }

}


void fill_rect(void *mlx, void *win, int x, int y, int color)
{ 
  int finaly;
  int finalx;
  int depx;

  depx = x;
  finaly = y + RECTX;
  finalx = x + RECTY;
      while (y < finaly)
	{
	  x = depx;
	  while (x < finalx)
	    {
	      mlx_pixel_put(mlx, win, x, y, color);
	      x++;
	    }
	  y++;
	}
}

void fill_rect_line(void *mlx, void *win, int x, int y, int size,int color)
{
  int depx;
  int depy;
  int i;
  int sizex;
  int sizey;

  sizex = x + size;
  sizey = y + size;
  i = depx;
  depx = x;
  depy = y;

  while(x < sizex)
    {
      mlx_pixel_put(mlx, win, x, y, color);
      x++;
    }
  while(y < sizey - 2)
    {
      mlx_pixel_put(mlx, win, depx, y, color);
      mlx_pixel_put(mlx, win, x, y, color);
      y++;
    }
  x = depx;
  while(x < sizex)
    {
      mlx_pixel_put(mlx, win, x, y, color);
      x++;
    }
}

int close_mlx(int keycode, void *param)
{
  if(keycode == 53)
    exit(1);
  return (0);
}

int main (int argc, char **argv)
{
  void *mlx;
  void *win;
  char *line;
  int x;
  int y;     
  int i;
  char **tab;
  int sizev;
  void **param;

  sizev = 0;
  i = 0;
  //  line = "0 10 0 10 0 \n 10 10 10 0 10 \n 0 0 0 0 0 \n 10 10 10 10 10";
  line = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0 \n 0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0 \n 0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0 \n 0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0 \n 0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0 \n 0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0 \n 0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0";
  x = 80;
  y = 120;/*
    if(argc != 2)
    {
      printf("error");
      return (0);
      }*/
  //initialisation
  mlx = mlx_init();
  //creation de la fenetre
  win = mlx_new_window(mlx, 520, 520, "42");  
  /*tab = ft_strsplit(line, ' ');
  while(tab[i])
    {
      if(tab[i][0] == '\n')
	{
	  y += 21;
	  x = 80;
	  i++;
	}
      if(ft_atoi(tab[i]) == 0)
	{
	  fill_rect_line(mlx, win, x, y, 20, 0x990099);
	  x += 21;
	}
      else if(ft_atoi(tab[i]) == 10)
	{
	  fill_rect_line(mlx, win, x, y, 20, 0x00FFFF);
	  x += 21;
	}
      i++;
      }*/

  // mlx_pixel_put(mlx, win, x, y, color);
    draw_line(mlx, win, 200, 200, 200, 300, 0x00FFFF);
    draw_line(mlx, win, 200, 200, 300, 200, 0x00FFFF);
    draw_line(mlx, win, 300, 200, 300, 300, 0x00FFFF);
    draw_line(mlx, win, 200, 300, 300, 300, 0x00FFFF);
    mlx_key_hook(win, close_mlx, 0);
  //Boucle pour tenir la fenetre
  mlx_loop(mlx);
  return(0);
}
