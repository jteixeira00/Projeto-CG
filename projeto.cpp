
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>

//--------------------------------- Definir cores
#define BLUE     0.0, 0.0, 1.0, 1.0
#define RED		 1.0, 0.0, 0.0, 1.0
#define YELLOW	 1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define PI		 3.14159

//================================================================================
//===========================================================Variaveis e constantes
GLfloat translate = 0;
//GLfloat tam = 12;
GLfloat alfa = 0;
static GLfloat vertices[] = {
	//  base
		-1.8,  0, 0.3,  	// 0 
		-1.8,   0, -0.3, 	// 1 
		1.8,   0, -0.3,	// 2 
		1.8,  0,  0.3,	// 3 
	// esquerda
		 -1.8,  0, 0.3, 	// 4 
		 -1.8,   0, -0.3, 	// 5 
		 -1.8,   8.0, -0.3, 	// 6 
		 -1.8,  8.0, 0.3,	// 7 
	// direita
		1.8,  0, 0.3,	// 8 
		1.8,  0, -0.3,	// 9 
		 1.8,  8.0, -0.3,	// 10 
		 1.8,  8.0, 0.3,	// 11 

	//trás
		-1.8, 0, -0.3,  //12
		1.8, 0, -0.3,	//13
		1.8, 6.5, -0.3,	//14
		-1.8, 6.5, -0.3,	//15
		
	//frente
		-1.8, 0, 0.3,  //16
		1.8, 0, 0.3,	//17
		1.8, 6.5, 0.3,	//18
		-1.8, 6.5, 0.3,	//19

	//pedaço esquerda frente

		-1.8, 6.5, 0.3, //20
		-1.2, 6.5, 0.3, //21
		-1.2, 6.9, 0.3,		//22
		-1.8, 6.9, 0.3,		//23

	//pedaço esquerda trás

		-1.8, 6.5, -0.3, //24
		-1.2, 6.5, -0.3, //25
		-1.2, 6.9, -0.3,		//26
		-1.8, 6.8, -0.3,		//27

	//pedaço direita frente

		1.2, 6.5, 0.3, //28
		1.8, 6.5, 0.3, //29
		1.8, 6.9, 0.3, //30
		1.2, 6.9, 0.3, //31

	//pedaço direita tras

		1.2, 6.5, -0.3, //32
		1.8, 6.5, -0.3, //33
		1.8, 6.9, -0.3, //34
		1.2, 6.9, -0.3, //35



};

static GLfloat normais[] = {
	// x=tam (Esquerda)
	  -1.0,  0.0,  0.0,
	  -1.0,  0.0,  0.0,
	  -1.0,  0.0,  0.0,
	  -1.0,  0.0,  0.0,
	  // x=tam (Direita)
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		// y=tam (Cima)
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

	   1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		// y=tam (Cima)
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

	   1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		// y=tam (Cima)
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

	   1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		// y=tam (Cima)
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
};
//------------------------------------------------------------ Cores
static GLfloat cor[] = {
	// x=tam (Esquerda)
	  1.0,  0.0,  0.0,
	  1.0,  0.0,  0.0,
	  1.0,  0.0,  0.0,
	  1.0,  0.0,  0.0,
	  // x=tam (Direita)
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		// y=tam (Cima)
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0, 
		// x=tam (Esquerda)
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		 1.0,  0.0,  0.0,
			  // x=tam (Direita)
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,

		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		 1.0,  0.0,  0.0,
		 // x=tam (Direita)
		 1.0,  0.0,  0.0,
		 1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,


		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		 1.0,  0.0,  0.0,
		 // x=tam (Direita)
		 1.0,  0.0,  0.0,
		 1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
};
// nao esta feito !!


//=========================================================== FACES DA MESA
GLboolean   frenteVisivel = 1;
static GLuint     direita[] = { 8, 9, 10,  11 };   // regra da mao direita
static GLuint     esquerda[] = { 0,1,2,3 };
static GLuint	  baixo[] = { 5, 4, 7, 6 };
static GLuint	  tras[] = { 15, 14, 13, 12 };
static GLuint	  frente[] = { 16, 17, 18, 19 };
static GLuint	frenteesq[] = {20, 21, 22, 23};
static GLuint	trasesq[] = { 27, 26, 25, 24 };
static GLuint	frentedir[] = { 28, 29, 30, 31 };
static GLuint	trasdir[] = {35, 34, 33, 32};
//------------------------------------------------------------ Objectos (sistema coordenadas)
GLint		wScreen = 800, hScreen = 600;			//.. janela (pixeis)
GLfloat		xC = 20.0, yC = 20.0, zC = 20.0;		//.. Mundo  (unidades mundo)

//------------------------------------------------------------ Visualizacao/Observador 
GLfloat  rVisao = 10, aVisao = 0.5 * PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), 3.0, rVisao * sin(aVisao) };
GLfloat  angZoom = 90;
GLfloat  incZoom = 3;



//================================================================================
//=========================================================================== INIT
void inicializa(void)
{
	glClearColor(BLACK);		//Apagar
	glEnable(GL_DEPTH_TEST);	//Profundidade
	glShadeModel(GL_SMOOTH);	//Interpolacao de cores	

	glVertexPointer(3, GL_FLOAT, 0, vertices); //VertexArrays: vertices + normais + cores
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normais);
	glEnableClientState(GL_NORMAL_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cor);
	glEnableClientState(GL_COLOR_ARRAY);

}



void drawEixos()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo X
	glColor4f(RED);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(10, 0, 0);
	glEnd();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo Y
	glColor4f(GREEN);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 10, 0);
	glEnd();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo Z
	glColor4f(BLUE);
	glBegin(GL_LINES);
	glVertex3i(0, 0, 0);
	glVertex3i(0, 0, 10);
	glEnd();

}



void drawScene() {

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//=================================================== Qual o lado visivel ???
	if (frenteVisivel);
	//falta fazer

   //==================================== MESA	
   // ?? escala, rotacao, translacao ??
	glPushMatrix();
	glTranslatef(0, 0, translate);
	glRotatef(alfa, 1, 0, 0);
	//glScalef(0.5, 0.5, 0.5);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, baixo);   // desenhar uma das faces da mesa
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, tras);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frenteesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frentedir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trasesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trasdir);
	glPopMatrix();

	/*
	//==================================== Chaleira Amarela
	glColor4f(YELLOW);
	glPushMatrix();
	//?? escala, rotacao, translacao ??
	glutWireTeapot(1);
	glPopMatrix();
	*/

}

void display(void) {

	//================================================================= APaga ecran e lida com profundidade (3D)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//================================================================= Nao modificar !!!!!!!!!!!!
	glViewport(0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angZoom, (float)wScreen / hScreen, 0.1, 3 * zC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], 0, 0, 0, 0, 1, 0);
	//================================================================= Nao modificar !!!!!!!!!!!!


	//Objectos
	drawEixos();
	drawScene();

	//. . . . . . . . . . . . . . . . . . . . .  Actualizacao
	glutSwapBuffers();
}

//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y) {


	switch (key) {
	case 'f':
	case 'F':
		// ???
		glutPostRedisplay();
		break;

	case 'A':
	case 'a':
		translate += 2;
		glutPostRedisplay();
		break;

	case 'S':
	case 's':
		translate -= 2;
		glutPostRedisplay();
		break;

	case 'e':
	case 'E':
		alfa += 5;
		glutPostRedisplay();
		break;

	case 'd':
	case 'D':
		alfa -= 5;
		glutPostRedisplay();
		break;

	case 'r':
	case 'R':
		//??
		glutPostRedisplay();
		break;

		//--------------------------- Escape
	case 27:
		exit(0);
		break;
	}

}


void teclasNotAscii(int key, int x, int y) {
	//.. observador pode andar a volda da cena  (setas esquerda / direita)
	//.. observador pode andar para cima e para baixo (setas cima / baixo )

	if (key == GLUT_KEY_UP)   obsP[1] = (obsP[1] + 0.1);
	if (key == GLUT_KEY_DOWN) obsP[1] = (obsP[1] - 0.1);
	if (key == GLUT_KEY_LEFT)  aVisao = (aVisao + 0.1);
	if (key == GLUT_KEY_RIGHT) aVisao = (aVisao - 0.1);

	if (obsP[1] > yC)   obsP[1] = yC;   // limita altura
	if (obsP[1] < -yC)  obsP[1] = -yC;

	obsP[0] = rVisao * cos(aVisao);      // actualiza posicao (X,Z)
	obsP[2] = rVisao * sin(aVisao);

	glutPostRedisplay();
}


//======================================================= MAIN
//======================================================= MAIN
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wScreen, hScreen);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Porta   |Mover/rodar Cima:'r'|   |FaceVisivel:'f'|      |Observador:'SETAS'|        |Andar-'a/s'|        |Rodar -'e/d'| ");

	inicializa();

	glutSpecialFunc(teclasNotAscii);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}