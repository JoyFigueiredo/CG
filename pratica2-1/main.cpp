#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
#include <iostream>
static void resize(int width, int height)
{
}
static void display()
{
//desenha o primeiro ponto
    glPointSize(7.0f);
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glEnd();
    glFlush();
}
static void key(unsigned char key, int x, int y){
    if (key == 27)
        exit(0);
}
// fun��o para tratar os eventos do mouse
static void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN){
                float auxX = (x/20) -10;
                float auxY = (-y/20) +10;
                //float auxX = -10 + ((20/400)*x);
                //float auxY = 10 - ((20/400)*y);
                glBegin(GL_POINTS);
                glVertex2i(auxX,auxY);
                glEnd();
                glFlush();
            cout << "x; " << x << "y: " << y  << endl;
        }
    }
}
// fun��o respons�vel por fazer as inicializa��es
void setup(void)
{
// Define a cor de fundo da janela de visualiza��o como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);
//define a cor preta como inicial
    glColor3f(0.0f, 0.0f, 0.0f);

    gluOrtho2D(-10,10,-10,10);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exerc�cio 1");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
// registra a fun��o callback para tratar os eventos do mouse
    glutMouseFunc(mouse);
    glutReshapeFunc(resize);
    setup();
    glutMainLoop();
    return 0;
}
