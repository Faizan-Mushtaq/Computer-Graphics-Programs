#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
float house[11][2]={ { 100,200 },{ 200,250 },{ 300,200 },{ 100,200 },{ 100,100 },{ 175,100 },{ 175,150 },{ 225,150 },{ 225,100 },{ 300,100 },{ 300,200 } };
int angle;
float m,c,theta;
void display(){
  glClearColor(1,1,1,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-450,450,-450,450);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //normal
  glColor3f(1,0,0);
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<11;i++)
    glVertex2fv(house[i]);
  glEnd();
  glFlush();
  //rotated
  glPushMatrix();
  glTranslatef(100,100,0);
  glRotatef(angle,0,0,1);
  glTranslatef(-100,-100,0);
  glColor3f(1,1,0);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<11;i++)
      glVertex2fv(house[i]);
  glEnd();
  glPopMatrix();
  glFlush();
}
void display2(){
  glClearColor(1,1,1,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-450,450,-450,450);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //normal
  glColor3f(1,0,0);
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<11;i++)
    glVertex2fv(house[i]);
  glEnd();
  glFlush();
  float x1=0,x2=500;
  float y1=m*x1+c;
  float y2=m*x2+c;
  glColor3f(1,1,0);
  glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
  glEnd();
  glFlush();
  //reflected
  glPushMatrix();
  glTranslatef(0,c,0);
  theta=atan(m);
  theta=theta*180/3.14;
  glRotatef(theta,0,0,1);
  glScalef(1,-1,1);
  glRotatef(-theta,0,0,1);
  glTranslatef(0,-c,0);
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<11;i++)
      glVertex2fv(house[i]);
  glEnd();
  glPopMatrix();
  glFlush();
}
void myinit(){
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
  glLineWidth(2.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-450,450,-450,450);
}
void mouse(int btn,int st,int x,int y){
  if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN) display();
  else if(btn==GLUT_RIGHT_BUTTON && st==GLUT_DOWN) display2();
}
int main(int argc,char **argv){
  printf("Enter angle slp(m) and intercept c");
  scanf("%d%f%f",&angle,&m,&c);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("rot and refl");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  myinit();
  glutMainLoop();
}
