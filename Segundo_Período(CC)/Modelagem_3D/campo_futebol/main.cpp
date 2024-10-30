
#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float alpha = 0;
float beta = 0;
float delta = 1;

typedef struct{
    int x, y, z;
}Ponto;

Ponto pEsfera2;

void inicializaVars(){
    pEsfera2.x = 2;
    pEsfera2.y = 2;
    pEsfera2.z = 0;
}

void init() {
     glClearColor(0, 0, 0, 0);
     glEnable(GL_DEPTH_TEST);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-4, 4, -4, 4, -4, 4);
 }

void display() {
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glRotatef(beta, 0, 1, 0);
     glRotatef(alpha, 1, 0, 0);
     glScalef(delta, delta, delta);
     //bola
     glColor3f(1, 1, 1);
     glutSolidSphere(0.2f, 20, 20);


     //campo
     glPushMatrix();
     glTranslatef(0, -1, 0);
     glScalef(4, 0.1f, 2);
     glColor3f(0, 1, 0);
     //glLoadIdentity();
     glutSolidCube(2.0f);
     glPopMatrix();

     //gol
     glLineWidth(3);
     glColor3f(1,1,1);
     glTranslatef(-3.5f, -0.1f, 0.0f);
     glScalef(1, 0.2f, 2);
     glutWireCube(1.0f);
     glTranslatef(7.0f, 0.0f, 0.0f);
     glutWireCube(1.0f);



     glutSwapBuffers();
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
                    GLint x, GLint y) {
	switch(tecla) {
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
     glutInitWindowSize(800, 600);
     glutCreateWindow("Exemplo Esfera 3D Transformação");
     gluOrtho2D(0.0, 400, 0.0, 600);
     init();
     inicializaVars();
     glutKeyboardFunc(keyboard);
     glutSpecialFunc(listeningSpKey);
     glutDisplayFunc(display);
     glutMainLoop();
 }
