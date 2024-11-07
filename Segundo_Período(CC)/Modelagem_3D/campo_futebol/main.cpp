#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    float x, y, z;
} Ponto;

Ponto pEsfera = {0, -0.75f, 0};
Ponto pGoleiro = {3.5f, -0.75f, 1.0f};
Ponto pGoleiro2 = {-3.5f, 0.75f, -1.0f};
int gols = 0;
int erros = 0;
int chuteEmProgresso = 0;
int direcaoGoleiro = 1;

float alpha = 0;
float beta = 0;
float delta = 1;

GLfloat escalaX = 1;
GLfloat escalaY = 1;
GLfloat TranslateX = 1;
GLfloat TranslateY = 1;
GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;
GLfloat angulo = 0.0;

void DesenhaTextoStroke(char *aux)
{
    char *p;
    p = aux;
    while(*p)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,*p++);
}

void inicializa()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);

    pEsfera.x = 0;
    pEsfera.y = -0.75f;
    pEsfera.z = 0;
    chuteEmProgresso = 0;
}

void desenhaGol(float xPos)
{
    glPushMatrix();
    glTranslatef(xPos, -1.0f, 0);
    glColor3f(1, 1, 1);

    glBegin(GL_LINES);
    glVertex3f(0, 0, -1.5f);
    glVertex3f(0, 1.0f, -1.5f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 0, 1.5f);
    glVertex3f(0, 1.0f, 1.5f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 1.0f, -1.5f);
    glVertex3f(0, 1.0f, 1.5f);
    glEnd();

    glPopMatrix();
}

void desenhaLinhasCampo()
{
    glColor3f(1, 1, 1);
    glLineWidth(3);

    glBegin(GL_LINES);
    glVertex3f(0, -0.95f, -2.0f);
    glVertex3f(0, -0.95f, 2.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-3.5f, -0.95f, -2.0f);
    glVertex3f(-3.5f, -0.95f, 2.0f);

    glVertex3f(3.5f, -0.95f, -2.0f);
    glVertex3f(3.5f, -0.95f, 2.0f);
    glEnd();
}

void exibe()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //placar
    char textoPlacar[50];
    sprintf(textoPlacar, "Gols: %d | Erros: %d", gols, erros);
    glColor3f(1, 1, 1);
    glRasterPos3f(-3.0f, 3.5f, 0);
    for (char* c = textoPlacar; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
    glPopMatrix();

    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);

    // Campo
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glScalef(7, 0.1f, 4);
    glColor3f(0, 1, 0);
    glutSolidCube(1.0f);
    glPopMatrix();

    desenhaLinhasCampo();
    desenhaGol(-3.5f);
    desenhaGol(3.5f);

    // Bola de Futebol
    glPushMatrix();
    glTranslatef(pEsfera.x, pEsfera.y, pEsfera.z);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

    // Goleiro
    glPushMatrix();
    glTranslatef(pGoleiro.x, pGoleiro.y, pGoleiro.z);
    glColor3f(1, 0, 1);
    glutSolidSphere(0.3f, 40, 20);
    glPopMatrix();

    //glColor3f(0,0,0);
    glTranslatef(240,180,0);
    glScalef(0.2, 0.2, 0);
    glLineWidth(2);
    glPushMatrix();

    glTranslatef(pGoleiro2.x, pGoleiro2.y, pGoleiro2.z);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.3f, 40, 20);
    glPopMatrix();

    //glColor3f(0,0,0);
    glTranslatef(240,180,0);
    glScalef(0.2, 0.2, 0);
    glLineWidth(2);


    glFlush();
}

void anima(int valor)
{
    if (chuteEmProgresso)
    {
        pEsfera.x += 0.1f;
        if (pEsfera.x > 3.5f)
        {
            chuteEmProgresso = 0;
            if (pEsfera.z >= pGoleiro.z - 0.3f && pEsfera.z <= pGoleiro.z + 0.3f)
            {
                erros++;
            }
            else
            {
                gols++;
            }
            pEsfera.x = 0;
            pEsfera.y = -0.75f;
            pEsfera.z = 0;
        }
    }

    pGoleiro.z += 0.05f * direcaoGoleiro;
    if (pGoleiro.z > 1.5f || pGoleiro.z < -1.5f)
    {
        direcaoGoleiro = -direcaoGoleiro;
    }

    glutPostRedisplay();
    glutTimerFunc(20, anima, 0);
}

void teclado(unsigned char tecla, int x, int y)
{
    //Espaco e ' '
    if (tecla == ' ')
    {
        if (!chuteEmProgresso)
        {
            chuteEmProgresso = 1;
        }
    }
    if (tecla == 'r')
    {
        gols = 0;
        erros = 0;
    }


    if (tecla == 27)
        exit(0);


    if(tecla == 'c')
            system("C:\\Users\\1519529\\Downloads\\Tarefa1-Lab_Mod3D\\Tarefa1-Lab_Mod3D\\interacao_teclado\\bin\\Debug\\interacao_teclado");

    glutPostRedisplay();
}

void escutaTeclasEspeciais(GLint tecla, GLint x, GLint y)
{
    switch (tecla)
    {
    case GLUT_KEY_UP:
        alpha -= 1;
        break;
    case GLUT_KEY_DOWN:
        alpha += 1;
        break;
    case GLUT_KEY_LEFT:
        beta += 1;
        break;
    case GLUT_KEY_RIGHT:
        beta -= 1;
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
    glutCreateWindow("Fiutebolis Joguineo");
    gluOrtho2D(0.0, 400, 0.0, 600);
    inicializa();
    glutKeyboardFunc(teclado);
    glutSpecialFunc(escutaTeclasEspeciais);
    glutDisplayFunc(exibe);
    glutTimerFunc(20, anima, 0);
    glutMainLoop();
}
