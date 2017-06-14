#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void Bresenham(int x1,int y1,int x2,int y2);
main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");  
   

   Bresenham(200,200,350,01);
   Bresenham(200,200,300,01);
   Bresenham(200,200,250,01);
   Bresenham(200,200,200,01);
   Bresenham(200,200,180,01);
   Bresenham(200,200,160,01);
   Bresenham(200,200,140,01);
   Bresenham(200,200,120,01);
   Bresenham(200,200,90,01);
   Bresenham(200,200,80,01);
   Bresenham(200,200,70,01);
     
   
   
     
   Bresenham(200,200,210,01);
   Bresenham(200,200,330,20);
   Bresenham(200,200,330,30);
   Bresenham(200,200,330,60);
   
   
   Bresenham(200,200,330,90);
   Bresenham(200,200,330,122);
   Bresenham(200,200,330,152);
   Bresenham(200,200,330,182);
   Bresenham(200,200,330,210);
   
   
   
   //trai
   Bresenham(200,200,0,1);
   Bresenham(200,200,0,20);
   Bresenham(200,200,0,30);
   Bresenham(200,200,0,60);
   Bresenham(200,200,0,90);
   Bresenham(200,200,0,122);
   Bresenham(200,200,0,152);
   Bresenham(200,200,0,182);
   Bresenham(200,200,0,210);
   Bresenham(200,200,0,230);
   Bresenham(200,200,0,250);
   Bresenham(200,200,0,280);
   Bresenham(200,200,0,300);
   Bresenham(200,200,0,325);
   
   
   
   Bresenham(200,200,0,400);
   Bresenham(200,200,0,500);
   Bresenham(200,200,0,600);
   Bresenham(200,200,0,800);
   Bresenham(200,200,0,1000);
   Bresenham(200,200,0,9000);
   
	
   Bresenham(200,200,330,100);
   Bresenham(200,200,330,200);
   Bresenham(200,200,330,300);   
   Bresenham(200,200,330,400);
   Bresenham(200,200,330,500);
   Bresenham(200,200,330,600);
   Bresenham(200,200,330,700);
   Bresenham(200,200,330,800);
   
    
    
   getch();
   closegraph();
}
void Bresenham(int x1,int y1,int x2,int y2)
{
	int Dx=x2-x1;
	int Dy=y2-y1;
	int x=x1,y=y1;
	int dx=(Dx<0)? -1:1;
	int dy=(Dy<0)? -1:1;
	Dx=abs(Dx);
	Dy=abs(Dy);
	putpixel(x,y,WHITE);
	if(Dx>Dy)
	{
		int p=2*Dy-Dx;
		int const1=2*Dy,const2=2*(Dy-Dx);
		while(x!=x2)
		{
			if(p<0)
			{
				p+=const1;
			}
			else
			{
				p+=const2;
				y+=dy;
			}
			x+=dx;
			putpixel(x,y,RED);
		}
	}
	else
	{
		putpixel(x,y,BLUE);
		int p=2*Dy-Dx;
		int const1=2*Dx,const2=2*(Dx-Dy);
		while(y!=y2)
		{
			if(p<0)
			{
				p+=const1;
			}
			else
			{
				p+=const2;
				x+=dx;
			}
			y+=dy;
			putpixel(x,y,WHITE);
	
		}
	}
	
	
}
