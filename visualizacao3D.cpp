
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/Glut.h>

//--------------------------------- Definir cores
#define BLUE     0.0, 0.0, 1.0, 1.0
#define RED		 1.0, 0.0, 0.0, 1.0
#define YELLOW	 1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define ORANGE   1.0, 0.5, 0.1, 1.0
#define CYAN     0.0, 1.0, 1.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.3, 0.3, 0.3, 1.0
#define PI		 3.14159

//================================================================================
//===========================================================Variaveis e constantes
GLint     msec = 10;
char      texto[30];						//.. texto a ser escrito no ecran


//-------------------- Porta
static GLfloat vertices[] = {
	//  base
	-1.8, 0, 0.3,  	// 0 
	-1.8, 0, -0.3, 	// 1 
	1.8, 0, -0.3,	// 2 
	1.8, 0, 0.3,	// 3 
	// esquerda
	-1.8, 0, 0.3, 	// 4 
	-1.8, 0, -0.3, 	// 5 
	-1.8, 8.0, -0.3, 	// 6 
	-1.8, 8.0, 0.3,	// 7 
	// direita
	1.8, 0, 0.3,	// 8 
	1.8, 0, -0.3,	// 9 
	1.8, 8.0, -0.3,	// 10 
	1.8, 8.0, 0.3,	// 11 

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
	-0.8, 6.5, 0.3, //21
	-0.8, 6.9, 0.3,		//22
	-1.8, 6.9, 0.3,		//23

	//pedaço esquerda trás

	-1.8, 6.5, -0.3, //24
	-0.8, 6.5, -0.3, //25
	-0.8, 6.9, -0.3,		//26
	-1.8, 6.9, -0.3,		//27

	//pedaço direita frente

	0.8, 6.5, 0.3, //28
	1.8, 6.5, 0.3, //29
	1.8, 6.9, 0.3, //30
	0.8, 6.9, 0.3, //31

	//pedaço direita tras

	0.8, 6.5, -0.3, //32
	1.8, 6.5, -0.3, //33
	1.8, 6.9, -0.3, //34
	0.8, 6.9, -0.3, //35

	//frente topo

	-1.8, 6.9, 0.3, //36
	1.8, 6.9, 0.3, //37
	1.8, 8.0, 0.3, //38
	-1.8, 8.0, 0.3, //39

	//trás topo
	-1.8, 6.9, -0.3, //40
	1.8, 6.9, -0.3, //41
	1.8, 8.0, -0.3, //42
	-1.8, 8.0, -0.3, //43

	//topo
	-1.8, 8, 0.3,  //44
	1.8, 8, 0.3, //45
	1.8, 8, -0.3,  //46
	-1.8, 8, -0.3,	//47

	//int dir
	0.8, 6.5, 0.3,  //48
	0.8, 6.9, 0.3,
	0.8, 6.9, -0.3,
	0.8, 6.5, -0.3,

	//int esquerda
	-0.8, 6.5, 0.3,  //52
	-0.8, 6.9, 0.3,
	-0.8, 6.9, -0.3,
	-0.8, 6.5, -0.3,

	//int baixo
	-0.8, 6.5, 0.3, //56
	0.8, 6.5, 0.3,
	0.8, 6.5, -0.3,
	-0.8, 6.5, -0.3,

	//int cima

	-0.8, 6.9, -0.3,	//60
	0.8, 6.9, -0.3,
	0.8, 6.9, 0.3,
	-0.8, 6.9, 0.3,
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

		 0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

		0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

		0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

		 0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

		0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

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

   1.0,  0.0,  0.0,
	1.0,  0.0,  0.0,
   1.0,  0.0,  0.0,
   1.0,  0.0,  0.0,

	  1.0,  0.0,  0.0,
	1.0,  0.0,  0.0,
   1.0,  0.0,  0.0,
   1.0,  0.0,  0.0,

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
		0.0,  1.0,  0.0,// x=tam (Direita)
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		// y=tam (Cima)
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
};

static GLuint     direita[] = { 8, 9, 10,  11 };   // regra da mao direita
static GLuint     esquerda[] = { 0,1,2,3 };
static GLuint	  baixo[] = { 5, 4, 7, 6 };
static GLuint	  tras[] = { 15, 14, 13, 12 };
static GLuint	  frente[] = { 16, 17, 18, 19 };
static GLuint	frenteesq[] = { 20, 21, 22, 23 };
static GLuint	trasesq[] = { 27, 26, 25, 24 };
static GLuint	frentedir[] = { 28, 29, 30, 31 };
static GLuint	trasdir[] = { 35, 34, 33, 32 };
static GLuint	frentecima[] = { 36, 37, 38, 39 };
static GLuint	trascima[] = { 43,42,41,40 };
static GLuint	topo[] = {44,45,46,47 };
static GLuint	intdir[] = { 48,49,50,51 };
static GLuint	intesq[] = { 55, 54, 53, 52};
static GLuint	intbaixo[] = { 56, 57, 58, 59};
static GLuint	intcima[] = { 60, 61, 62, 63 };

void drawScene() {

	glPushMatrix();
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, baixo);   // desenhar uma das faces da mesa
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, tras);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frenteesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frentedir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trasesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trasdir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frentecima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trascima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, topo);

	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intdir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intbaixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intcima);
	glPopMatrix();
}
//------------------------------------------------------------ Sistema Coordenadas + objectos
GLint		wScreen = 600, hScreen = 500;		//.. janela
GLfloat		yC = 100.0;	//.. Mundo

//------------------------------------------------------------ Observador 
GLfloat  rVisao = 13, aVisao = PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), 3.0, rVisao * sin(aVisao) };
GLfloat  obsT[] = { obsP[0] - rVisao * cos(aVisao), obsP[1], obsP[2] - rVisao * sin(aVisao) };

float anguloZ = 95;
int   tipoProjeccao = 0;




//================================================================================
//=========================================================================== INIT
void initialize(void)
{
	glClearColor(BLACK);		//………………………………………………………………………………Apagar
	glEnable(GL_DEPTH_TEST);	//………………………………………………………………………………Profundidade
	glShadeModel(GL_SMOOTH);	//………………………………………………………………………………Interpolacao de cores	

	glEnable(GL_CULL_FACE);		//………………………………………………………………………………Faces visiveis
	glCullFace(GL_BACK);		//………………………………………………………………………………Mostrar so as da frente

	glVertexPointer(3, GL_FLOAT, 0, vertices); //………………………………………Vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normais);
	glEnableClientState(GL_NORMAL_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cor);
	glEnableClientState(GL_COLOR_ARRAY);

	srand(1);
}

float aleatorio(GLint minimo, GLint maximo) {
	GLfloat y;
	y = rand() % 1000;
	return (minimo + 0.001 * y * (maximo - minimo));
}

void desenhaTexto(char* string, GLfloat x, GLfloat y)
{
	glPushMatrix();
	glTranslatef(x, 0, y);
	glRasterPos2f(0, 0);
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);
	glPopMatrix();
}


void drawEixos()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixo
	glColor4f(ORANGE);
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(10, 0, 0);
	glEnd();
	glColor4f(GREEN);
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 10, 0);
	glEnd();
	glColor4f(CYAN);
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, 10);
	glEnd();

}

void drawObservador_Local()
{
	glColor4f(GREEN);
	glPushMatrix();
		glTranslatef(obsP[0], obsP[1], obsP[2]);
	glPopMatrix();
}
void drawObservador_Target()
{
	glColor4f(YELLOW);
	glPushMatrix();
		glTranslatef(obsT[0], obsT[1], obsT[2]);
	glPopMatrix();
}

void draw_Informacao()
{
	if (tipoProjeccao)
		sprintf_s(texto, 30, "Projecao = Ortogonal");
	else
		sprintf_s(texto, 30, "Projecao = Perspectiva");
	desenhaTexto(texto, -15, -15);


}

//======================================





//====================================================== 
//====================================================== 
void display(void) {

	//================================================================= APaga 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//================================================================= Viewport 1 MAPA
	// projecao ortogonal
	glViewport(0, 0, 0.25 * wScreen, 0.25 * hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 30, 0, 0, 0, 0, 0, 0, -1);
	//…………………………………………………………………………………………………………………………………………………………Objectos
	drawEixos();
	drawObservador_Local();
	drawObservador_Target();
	drawScene();
	draw_Informacao();

	//================================================================= Viewport 2
	glViewport(0.25 * wScreen, 0.25 * hScreen, 0.75 * wScreen, 0.75 * hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (tipoProjeccao == 0)
		gluPerspective(anguloZ, (float)wScreen / hScreen, 0.1, 9999);
	if (tipoProjeccao == 1)
		glOrtho(-20, 20, -20, 20, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], obsT[0], obsT[1], obsT[2], 0, 1, 0);

	//…………………………………………………………………………………………………………………………………………………………Objectos
	drawEixos();
	drawScene();


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao
	glutSwapBuffers();
}


void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(msec, Timer, 1);
}

//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y) {


	switch (key) {
	
   //------------------------------ zoom
	case 'z': 	case 'Z':
		
		break;
	case 'x':	case 'X':
		break;

		//------------------------------ projeccao
	case 'p': 	case 'P':
		tipoProjeccao = (tipoProjeccao + 1) % 2;
		glutPostRedisplay();
		break;
	
		//--------------------------- Escape
	case 27:
		exit(0);
		break;
	}

}



void teclasNotAscii(int key, int x, int y) {


	//------------------------------- olhar para a origem
		obsT[0] = 0; obsT[1] = 0; obsT[2] = 0;
		
		if (key == GLUT_KEY_UP)    obsP[1] = obsP[1] + 0.5;
		if (key == GLUT_KEY_DOWN)  obsP[1] = obsP[1] - 0.5;
		if (key == GLUT_KEY_LEFT)  aVisao = aVisao + 0.1;
		if (key == GLUT_KEY_RIGHT) aVisao = aVisao - 0.1;

		if (obsP[1] > yC)   obsP[1] = yC;
		if (obsP[1] < -yC)  obsP[1] = -yC;
		obsP[0] = rVisao * cos(aVisao);
		obsP[2] = rVisao * sin(aVisao);
		   
	    glutPostRedisplay();

}


//======================================================= MAIN
//======================================================= MAIN
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wScreen, hScreen);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("{jh,ct,ep}@dei.uc.pt|    |Observador:'SETAS'|  |Projecao -'p'| ");

	initialize();

	glutSpecialFunc(teclasNotAscii);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}



