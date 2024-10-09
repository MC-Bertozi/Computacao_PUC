//Página1de 2
#include<GL/glut.h>
#include<stdio.h>
#include <math.h>
#define PI 3.1415926535898
GLfloat escala = 1;
int i = 0;
void desenha(void)
{
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60, 60, -60, 60);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 0, 0);
    glLineWidth(6);
    //em vezde usarmos as operações dentro do for podemos usar:
    glTranslatef(-2, -1, 0);
    glScalef(2, 3, 1);
    float ang, x, y;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 360; i++)
    {
//angle = 2*PI*i/circle_points;
        ang = (i * PI) / 180.0;
        x = 20 + (cos(ang) * 8);
        y = 20 + (sin(ang) * 8);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void listeningKey (unsigned char tecla,
                   GLint x, GLint y)
{
    switch(tecla)
    {
    case '+':
        escala=escala+0.25;
        break;
    case '-':
        escala=escala-0.25;
        break;
    }
    desenha();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Ola Glut");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}
