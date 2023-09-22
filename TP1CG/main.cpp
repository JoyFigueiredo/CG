#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

//variáveis para controle da translação
GLfloat posicaoX=0, posicaoY=0;
//variável para controle da escala
GLfloat escala = 1;
GLfloat angulo= 0;

static void resize(int width, int height)
{

    // Especifica as dimensões da Viewport
    glViewport(0, 0, width, height);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (esquerda, direita, inferior,
    // superior) mantendo a proporção com a janela de visualização
    if (width <= height)
        gluOrtho2D (-40.0f, 40.0f, -40.0f*height/width, 40.0f*height/width);
    else
        gluOrtho2D (-40.0f*width/height, 40.0f*width/height, -40.0f, 40.0f);
}

void quadrado(){
    glBegin(GL_QUADS); // modo desenho dos pontos iniciada
        glVertex2f(-20,-20);
        glVertex2f(20,-20);
        glVertex2f(20,20);
        glVertex2f(-20,20);
    glEnd();
}

void losangulo(){
    glBegin(GL_POLYGON); // modo desenho dos pontos iniciada
        glVertex2f(-20,-20);
        glVertex2f(10,-10);
        glVertex2f(20,20);
        glVertex2f(-10,10);
    glEnd();
}

void triangulo(){
    glBegin(GL_TRIANGLES); // modo desenho dos pontos iniciada
        glVertex2f(-20,-20);
        glVertex2f(0,0);
        glVertex2f(-20,20);
    glEnd();
}


void quadradoPrincipal(){
    glBegin(GL_LINE_LOOP); // modo desenho dos pontos iniciada
        glVertex2f(-20,-20);
        glVertex2f(20,-20);
        glVertex2f(20,20);
        glVertex2f(-20,20);
    glEnd();
}

static void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslated(posicaoX, posicaoY,0);

    glPushMatrix();
        //QUADRADO MAIOR
        glColor3f(0, 0, 0);
        glTranslatef(0.0f ,0.0f, 0.0f);
        glScalef(posicaoX+escala,posicaoY+escala,0);
        quadradoPrincipal();
    glPopMatrix();

    glPushMatrix();
        //Triangulo GRANDE1
        glColor3f(0, 0, 1);
        glTranslatef(0.0f ,0.0f, 0.0f);
        glScalef(posicaoX+escala,posicaoY+escala,0);
        triangulo();
    glPopMatrix();

    glPushMatrix();
        //Triangulo GRANDE2
        glColor3f(0, 1, 0);
        glTranslatef(0.0f ,0.0f, 0.0f);
        glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(posicaoX+escala,posicaoY+escala,0);
        triangulo();
    glPopMatrix();

    glPushMatrix();
        //Triangulo Medio2
        glColor3f(0, 1, 1);
        glTranslatef(20.0f ,-20.0f, 0.0f);
        glRotatef(-225.0f, 0.0f, 0.0f, 1.0f);
         glScalef(-1.0f, 1.0f, 1.0f);
        glScalef((posicaoX+escala)*0.73,(posicaoY+escala)*0.73,0);
        triangulo();
    glPopMatrix();


    glPushMatrix();
        //Triangulo pequeno1
        glColor3f(1, 0, 0);
        glTranslatef(-10.0f ,-10.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef((posicaoX+escala)*0.5,(posicaoY+escala)*0.5,0);
        triangulo();
    glPopMatrix();

    glPushMatrix();
        //Triangulo pequeno2
        glColor3f(1, 0, 1);
        glTranslatef(0.0f ,0.0f, 0.0f);
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
        glScalef((posicaoX+escala)*0.5,(posicaoY+escala)*0.5,0);
        triangulo();
    glPopMatrix();

    glPushMatrix();
        //Quadrado
        glColor3f(1, 1, 0);
        glTranslatef(0.0f ,-10.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glScalef((posicaoX+escala)*0.35,(posicaoY+escala)*0.35,0);
        quadrado();
    glPopMatrix();

        glPushMatrix();
        //Losangulo
        glColor3f(1, 1, 1);
        glTranslatef(10.0f ,10.0f, 0.0f);
        glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
         glScalef(-1.0f, 1.0f, 1.0f);
        glScalef((posicaoX+escala)*0.5,(posicaoY+escala)*0.5,0);
        losangulo();
    glPopMatrix();

    glFlush();

}

static void key(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

// função para tratar os eventos do teclado para teclas Especiais
static void specialkey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        posicaoX--;
        angulo = angulo + 45;
        break;
    case GLUT_KEY_RIGHT:
        posicaoX++;
        angulo = angulo - 45;
        break;
    case GLUT_KEY_UP:
        posicaoY++;
        angulo = angulo - 45;
        break;
    case GLUT_KEY_DOWN:
        posicaoY--;
        angulo = angulo + 45;
        break;
    case GLUT_KEY_HOME:
        escala += 0.3;
        break;
    case GLUT_KEY_END:
        escala -= 0.3;
        break;
    }

    display();
}

void setup(void)
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 400, 400);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-40.0f, 40.0f, -40.0f, 40.0f);
}

int main(int argc, char *argv[])
{
    // utilizada para inicializar a biblioteca GLUT
    glutInit(&argc, argv);

    // define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(400, 400);

    // especifica a posição inicial da janela GLUT
    glutInitWindowPosition(100, 100);

    // cria a janela passando como título como argumento
    glutCreateWindow("Projeto 03");

    // registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(display);

    // registra a função callback para tratar os eventos do teclado
    glutKeyboardFunc(key);

    // registra a função callback de redimensionamento da janela de visualização
    glutReshapeFunc(resize);

    // Registra a função callback para tratamento das teclas Especiais
    glutSpecialFunc(specialkey);

    // chama a função responsável por fazer as inicializações
    setup();

    // inicia o processamento e aguarda interações do usuário
    glutMainLoop();

    return 0;
}
