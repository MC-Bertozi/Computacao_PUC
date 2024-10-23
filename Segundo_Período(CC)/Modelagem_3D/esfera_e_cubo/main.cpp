#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float alpha = 0;
float beta = 0;
float delta = 1;

void init()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);
    glColor3f(1, 1, 0);
    glutWireSphere(1.0f, 40, 20);


    glTranslatef(0, -1, 0);
    glScalef(4, 0.1f, 4);
    glColor3f(0, 0, 1);
    //glLoadIdentity();
    glutSolidCube(1.0f);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 'q')
        delta = delta * 1.1f;
    if(key == 'w')
        delta = delta * 0.9f;
    glutPostRedisplay();
}

void  listeningSpKey (GLint tecla,
                      GLint x, GLint y)
{
    switch(tecla)
    {
    case GLUT_KEY_UP:
        alpha = alpha - 1;
        break;
    case GLUT_KEY_DOWN:
        alpha = alpha + 1;
        break;
    case GLUT_KEY_LEFT:
        beta = beta + 1;
        break;
    case GLUT_KEY_RIGHT:
        beta = beta - 1;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Exemplo Esfera 3D Transformação");
    gluOrtho2D(0.0, 400, 0.0, 600);
    init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glutDisplayFunc(display);
    glutMainLoop();
}
