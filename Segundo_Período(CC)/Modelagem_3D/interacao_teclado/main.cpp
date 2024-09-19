#include <GL/glut.h>
#include <stdlib.h>
#include<GL/freeglut.h>
#include<iostream>

GLfloat escalaX = 1;
GLfloat escalaY = 1;
GLfloat TranslateX = 1;
GLfloat TranslateY = 1;
GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;
GLfloat angulo = 0.0;

void desenha(void)
{
    glClear( GL_COLOR_BUFFER_BIT );

    //Seta dfinicao da matriz de trasformacao da camera
    glMatrixMode(GL_PROJECTION);
    //Atribui a matriz de transformacao da camera a matriz de identidade
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20); // define a área de enquadramento da cena

    glMatrixMode(GL_MODELVIEW); //Seta definicao da matriz de trasformacao de modelos camera
    glLoadIdentity(); //Atribui a matriz de transformacao de modelo da cena a matriz identidade

    glTranslatef(TranslateX, TranslateY, 0.0f);//define a transformacao de translacao (mudar de lugar)
    glScalef(escalaX, escalaY, 0); //muda a escala do desenho
    glRotatef(angulo, rotateX, rotateY, 1.0f); //rotaciona em angulo

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

    glVertex2f(-6, 4); //linha do meio (traço) / horizontal
    glVertex2f(-2, 4);

    glVertex2f(-6, 8); //linha reta da esquerda / vertical
    glVertex2f(-6, 0);

    //letra r
    glVertex2f(4, 8); //linha reta da direita / vertical
    glVertex2f(4, 4);

    glVertex2f(0, 8); //linha de cima / horizontal
    glVertex2f(4, 8);

    glVertex2f(0, 4); //linha do meio (traço) / horizontal
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

    glVertex2f(10, 4); //linha do meio (traço) / horizontal
    glVertex2f(6, 4);

    glVertex2f(10, 8); //linha reta da esquerda / vertical
    glVertex2f(10, 0);
    glEnd();

    glFlush();
}

void listeningkey(unsigned char tecla, GLint x, GLint y) //PRECISA ter 3 parametros para ue seja usado de forma correta
{
    switch(tecla)
    {
    case '+': //aumenta as letras

        escalaX+=0.5;
        escalaY+=0.5;
        break;

    case '-': //diminui as letras
        escalaX-=0.5;
        escalaY-=0.5;

        break;

    case '4': //Diminui a escala em x
        escalaX-=0.1;
        break;

    case '6': //Aumenta a escala em x
        escalaX+=0.1;
        break;

    case '2': //Diminui a escala em y
        escalaY-=0.1;
        break;

    case '8': //Aumenta a escala em y
        escalaY+=0.1;
        break;

    case 'w': //Desloca para cima
        TranslateY+=1;
        break;

    case 's': //Desloca para baixo
        TranslateY-=1;
        break;

    case 'a': //Desloca pra esquerda
        TranslateX-=1;
        break;
    case 'd': //Desloca pra direita
        TranslateX+=1;
        break;
    case 'e': //rotate no sentido horario
        angulo-=1;
        break;
    case 'q': //rotate no sentido antihorario
        angulo+=1;
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
