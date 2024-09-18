#include <GL/glut.h>
#include <stdlib.h>
#include<GL/freeglut.h>
#include<iostream>

void desenha(void)
{
    glClear( GL_COLOR_BUFFER_BIT );

    //Seta dfinicao da matriz de trasformacao da camera
    glMatrixMode(GL_PROJECTION);
    //Atribui a matriz de transformacao da camera a matriz de identidade
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20); // define a �rea de enquadramento da cena

    glMatrixMode(GL_MODELVIEW); //Seta definicao da matriz de trasformacao de modelos camera
    glLoadIdentity(); //Atribui a matriz de transformacao de modelo da cena a matriz identidade

    glTranslatef(0.0f, 0.0f, 0.0f);//define a transformacao de translacao (mudar de lugar)
    glScalef(escala, escala, 0); //muda a escala do desenho
    glRotatef(45.0f, 1.0f, 1.0f, 0.0f); //rotaciona em angulo

    glLineWidth(5);
    glColor3f(1.0f,0.5f,0.5f);
    glBegin(GL_LINES);
    /*plano cartesiano
     glVertex2f(0, 0);
     glVertex2f(-20, 0);*/

//letra M

    glVertex2f(-12, 8); //linha reta / vertical
    glVertex2f(-12, 0);

    glVertex2f(-12, 8); //perna 1 do M / diagonal
    glVertex2f(-10, 0);

    glVertex2f(-8,8); //perna 2 do M ao contrario /diagonal
    glVertex2f(-10,0);

    glVertex2f(-8,8); //linha reta da direita / vertical
    glVertex2f(-8,0);

    //letra a
    glVertex2f(-2, 8); //linha reta da direita / vertical
    glVertex2f(-2, 0);

    glVertex2f(-6, 8); //linha de cima / horizontal
    glVertex2f(-2, 8);

    glVertex2f(-6, 4); //linha do meio (tra�o) / horizontal
    glVertex2f(-2, 4);

    glVertex2f(-6, 8); //linha reta da esquerda / vertical
    glVertex2f(-6, 0);

    //letra r
    glVertex2f(4, 8); //linha reta da direita / vertical
    glVertex2f(4, 4);

    glVertex2f(0, 8); //linha de cima / horizontal
    glVertex2f(4, 8);

    glVertex2f(0, 4); //linha do meio (tra�o) / horizontal
    glVertex2f(4, 4);

    glVertex2f(0, 8); //linha reta da esquerda / vertical
    glVertex2f(0, 0);

    glVertex2f(0, 4); //"perna" do R / diagonal
    glVertex2f(4, 1);

    //letra i
    glVertex2f(5, 8); //linha reta
    glVertex2f(5, 0);

    //letra a
    glVertex2f(6, 8); //linha reta da direita / vertical
    glVertex2f(6, 0);

    glVertex2f(10, 8); //linha de cima / horizontal
    glVertex2f(6, 8);

    glVertex2f(10, 4); //linha do meio (tra�o) / horizontal
    glVertex2f(6, 4);

    glVertex2f(10, 8); //linha reta da esquerda / vertical
    glVertex2f(10, 0);
    glEnd();

    glFlush();
}

void listeningkey(unsigned char tecla, GLint x, GLint y)
{
    switch(tecla)
    {
        case '+': escala++;
        break;

        case '-': escala--;
        break;
    }

    desenha();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // inicializa
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); //inicializa o display
    glutInitWindowSize(800,600);
    glutCreateWindow("Hello World :P");
    glutKeyboardFunc(listeningkey);
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}
