#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
// função de redimensionamento da janela de visualização
static void resize(int width, int height){
}
// função de redesenho da janela de visualização
static void display(){
}
// função para tratar os eventos do teclado
static void key(unsigned char key, int x, int y){
}
// função responsável por fazer as inicializações
void setup(void){
}
// Programa Principal
int main(int argc, char *argv[]){
// utilizada para inicializar a biblioteca GLUT
glutInit(&argc, argv);
// define do modo de operação da GLUT
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// especifica o tamanho inicial em pixels da janela GLUT
glutInitWindowSize(400, 400);
// especifica a posição inicial da janela GLUT
glutInitWindowPosition(100, 100);
// cria a janela passando como título como argumento
glutCreateWindow("Exemplo");
// registra a função callback de redesenho da janela de visualização
glutDisplayFunc(display);
// registra a função callback para tratar os eventos do teclado
glutKeyboardFunc(key);
// registra a função callback de redimensionamento da janela de visualização
glutReshapeFunc(resize);
// chama a função responsável por fazer as inicializações
setup();
// inicia o processamento e aguarda interações do usuário
glutMainLoop();
return 0;
}
