#include<iostream>
#include<GL/glut.h>
#include<time.h>
using namespace std;
int x1,y1,x2,y2;
int flag=0;
void draw_pixel(int x,int y)
{
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
void draw_line()
{
	int dx,dy,i,p;
	int incx,incy,p1,p2;
	int x,y;
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0) dx=-dx;
	if(dy<0) dy=-dy;
	incx=1;
	if(x2<x1) incx=-1;
	incy=1;
	if(y2<y1) incy=-1;
	x=x1;
	y=y1;
	if(dx > dy)
	{
		draw_pixel(x,y);
		p=2*dy-dx;
		p1=2*(dy-dx);
		p2=2*dy;
		for(i=0;i<dx;i++)
		{
			if(p>0)
			{
				y+=incy;
				p+=p1;
			}
			else
			{
				p+=p2;
			}
			x+=incx;
			draw_pixel(x,y);
		}
	}
	else
	{
		draw_pixel(x,y);
		p=2*dx - dy;
		p1=2*(dx-dy);
		p2=2*dx;
		for(i=0;i<dy;i++)
		{
			if(p>0)
			{
				x+=incx;
				p+=p1;
			}
			else
			{
				p+=p2;
			}
			y+=incy;
			draw_pixel(x,y);
		}
	}
	glFlush();
}
void myinit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	gluOrtho2D(-250,250,-250,250);
}
void mymouse(int btn,int st,int x,int y)
{
	switch(btn)
	{
			case GLUT_LEFT_BUTTON: if(st==GLUT_DOWN)
															{
																if (flag==0)
																{
																	printf("def x1 y1");
																	x1=x-250;
																	y1=250-y;
																	flag++;
																	cout<<x1<<" "<< y1<< endl;
																}
																else{
																	printf("def x2 y2");
																	x2=x-250;
																	y2=250-y;
																	flag=0;
																	cout<<x2<<" "<< y2<< endl;
																	draw_line();
																}
															}
															break;
	}
}
void display() {}
int main(int argc,char** argv)
{
	// cout<<"Enter x1 y1 x2 y2\n";
	// cin>>x1>>y1>>x2>>y2;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bre Line");
	myinit();
	glutMouseFunc(mymouse); //INCLUDE TO USE MOUSE, REMOVE WHILE USING KEYBOARD
	//draw_line(); //INCLUDE TO USE KEYBOARD, REMOVE WHILE USING MOUSE
	glutDisplayFunc(display);
	glutMainLoop();
}
