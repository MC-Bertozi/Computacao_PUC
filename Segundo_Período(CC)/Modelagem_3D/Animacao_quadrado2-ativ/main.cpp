#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

//quadrado vermelho
GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;

//quadrado verde
GLfloat x2 = 200.0f;
GLfloat y2 = 250.0f;

GLfloat TranslateX = 1;
GLfloat TranslateY = 1;

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
GLfloat windowWidth;
GLfloat windowHeight;

void Texto(char *aux)
{
    char *p;
    p = aux;
    while(*p)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,*p++);
}

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    //quadrado vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2i(x1,y1+rsize);
    glVertex2i(x1,y1);
    glVertex2i(x1+rsize,y1);
    glVertex2i(x1+rsize,y1+rsize);
    glEnd();

    //quadrado verde
    glTranslatef(TranslateX, TranslateY, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(x2,y2+rsize);
    glVertex2i(x2,y2);
    glVertex2i(x2+rsize,y2);
    glVertex2i(x2+rsize,y2+rsize);


    glEnd();
    glutSwapBuffers();
}

void Timer(int value)
{
// Muda a direcao quando chega na borda esquerda ou direita��
    if(x1 > windowWidth-rsize || x1 < 0)
        xstep = -xstep;
// Muda a direcao quando chega na borda superior ou inferior��
    if(y1 > windowHeight-rsize || y1 < 0)
        ystep = -ystep;
// Verifica o de bordas. Se a window for menor e o quadrado sair do volume de visualizacao
    if(x1 > windowWidth-rsize)
        x1 = windowWidth-rsize-1;
    if(y1 > windowHeight-rsize)
        y1 = windowHeight-rsize-1;

    x1 += xstep; /*->para o horizontal*/
    y1 += ystep; /*->para o vertical*/
    glutPostRedisplay();
    glutTimerFunc(5,Timer, 0);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    printf("\n w: %d h: %d ", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    windowWidth = w;
    windowHeight = h;
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

void moveQuadVerde(unsigned char tecla, GLint x, GLint y)
{
    switch(tecla)
    {
    case 'w':
        TranslateY+= 10;
        break;

    case 's':
        TranslateY-= 10;
        break;

    case 'd':
        TranslateX+= 10;
        break;

    case 'a':
        TranslateX-= 10;
        break;
    }
    Desenha();
}

void colisao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    if(x1 == x2)
    {
        glTranslatef(320,470,0);
        glScalef(0.2, 0.2, 0);
        glLineWidth(2);
        glColor3f(0,0,0);
        Texto("Colisao feita, reiniciando...\n");
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Animacao");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutTimerFunc(5, Timer, 0);
    glutKeyboardFunc(moveQuadVerde);
    glutMainLoop();
}
