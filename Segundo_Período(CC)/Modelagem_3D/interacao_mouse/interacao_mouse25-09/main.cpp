#include <GL/glut.h>
#include <stdlib.h>
#include<GL/freeglut.h>
#include<iostream>

float r, g, b, x, y;
bool check = true;

GLfloat escalaX = 1;
GLfloat escalaY = 1;
GLfloat TranslateX = 1;
GLfloat TranslateY = 1;
GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;
GLfloat angulo = 0.0;

//o mouse trabaçlha com coordenadas de tela(aplicacoes grficas), diferentemente da opengl q usa coordenadas de computacao grafica
void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON)
        //if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        check=true;
        x = mousex;
        y = 600-mousey; //o 600 eh a quantidade de linhas
        r=(rand()%10)/10.0;
        g=(rand()%10)/10.0;
        b=(rand()%10)/10.0;
    }
    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        glClearColor(1,1,1,0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
    }
    glutPostRedisplay();
}

void display(void){
    glColor3f(r,g,b);
    glPointSize(50);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); //parametros da tela declaradas no main
    if(check){
        glBegin(GL_POINTS);
          glVertex2i(x,y);
        glEnd();
    }
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // inicializa
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); //inicializa o display
    glutInitWindowSize(800,600);
    glutCreateWindow("Hello World :P");
    glClearColor( 0, 0, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
