#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(10.0);

int x1=0,y1=0,x2=64,y2=0,x3=64,y3=64,x4=0,y4=64;
int colorR=0,colorG=0,colorB=0;

for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(i%2==0){
            if(j%2==0){
                colorR=0,colorG=0,colorB=0;
            }
            else{
                colorR=255,colorG=255,colorB=255;
            }
        }
        else{
            if(j%2==0){
                colorR=255,colorG=255,colorB=255;
            }
            else{
                colorR=0,colorG=0,colorB=0;
            }
        }


            glColor3ub (colorR, colorG, colorB);
            glBegin(GL_QUADS);
            glVertex2i(x1, y1);
            glVertex2i(x2, y2);
            glVertex2i(x3,y3);
            glVertex2i(x4, y4);
            glEnd();

            x1+=64;
            x2+=64;
            x3+=64;
            x4+=64;

    }
    if(i%2==0){
        x1=0,x2=64,x3=64,x4=0;
        y1+=64;
        y2+=64;
        y3+=64;
        y4+=64;
    }
    else{
        x1=0,x2=64,x3=64,x4=0;
        y1+=64;
        y2+=64;
        y3+=64;
        y4+=64;
    }


}

glFlush();
}

void myInit(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700, 640);
glutInitWindowPosition (400, 150);
glutCreateWindow ("Welcome To Chess!");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
}
