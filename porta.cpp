
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/Glut.h>

#include "RgbImage.h"

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
GLfloat alfaPorta = 0;
GLfloat posjanela = 0;
GLfloat alfaTrinco = 0;


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



	//janela frente
	-0.8, 6.5, 0.29,		//64
	0.8, 6.5, 0.29,
	0.8, 6.9,0.29,
	-0.8,6.9, 0.29,

	//janela lado

	0.8, 6.5, 0.3,		//68
	0.8, 6.5, -0.3,
	0.8, 6.9, -0.3,
	0.8, 6.9, 0.3,

	//janela trás
	-0.8, 6.5, -0.29,	//72
	0.8, 6.5, -0.29,
	0.8, 6.9, -0.29,
	-0.8, 6.9, -0.29,


	//fechadura

	1.3, 4, 0.301,	//76
	1.6, 4, 0.301,
	1.6, 4.8, 0.301,
	1.3, 4.8, 0.301,

	//trinco

	1.35, 4.4, 0.3011,  //80
	1.55, 4.4, 0.3011,
	1.55, 5.3, 0.3011,
	1.35, 5.3, 0.3011,

	//frame esquerda lado direito
	-1.8, 0, 0.3, 	// 84 
	-1.8, 0, -0.3, 	// 85 
	-1.8, 8.0, -0.3, 	// 86 
	-1.8, 8.0, 0.3,	// 87 

	//frame esquerda frente

	-1.8, 0, 0.3,		//88
	-1.8, 8, 0.3,
	-10, 8, 0.3,
	-10, 0, 0.3,

	//frame esquerda trás

	-1.8, 0, -0.3,		//92
	-1.8, 8, -0.3,
	-10, 8, -0.3,
	-10, 0, -0.3,

	//frame esquerda esquerda

	-10, 0, 0.3, 		//96
	-10, 0, -0.3,
	-10, 12, -0.3,
	-10, 12, 0.3,



	//frame direita lado esquerdo
	1.8, 0, 0.3, 	// 100
	1.8, 0, -0.3, 	
	1.8, 8.0, -0.3, 	 
	1.8, 8.0, 0.3,	// 103 

	//frame direita frente

	1.8, 0, 0.3,		//104
	1.8, 8, 0.3,
	10, 8, 0.3,
	10, 0, 0.3,

	//frame direita trás

	1.8, 0, -0.3,		//108
	1.8, 8, -0.3,
	10, 8, -0.3,
	10, 0, -0.3,

	//frame direita direita

	10, 0, 0.3, 		//112
	10, 0, -0.3, 	
	10, 12, -0.3, 
	10, 12, 0.3,
	
	
	//frame direita baixo

	1.8, 0, 0.3,	//116
	1.8, 0, -0.3,
	10, 0, -0.3,
	10, 0, 0.3,

	//frame esq baixo

	-1.8, 0, 0.3,		//120
	-10, 0, 0.3,
	-10, 0, -0.3,
	-1.8, 0, -0.3,

	//frame cima frente
	-10, 8, 0.3,			//124
	10, 8, 0.3,
	10, 12, 0.3,
	-10, 12, 0.3,

	//frame cima tras
	-10, 8, -0.3,		//128
	10, 8, -0.3,
	10, 12, -0.3,
	-10, 12, -0.3,

	//frame cima cima
	-10, 12, -0.3,		//132
	-10, 12, 0.3,
	10, 12, 0.3,
	10, 12, -0.3,

	//frame cima baixo
	-10, 8, -0.3,		//136
	-10, 8, 0.3,
	10, 8, 0.3,
	10, 8, -0.3,

		//trinco back

		1.35, 4.4, 0.3011,  //140
		1.55, 4.4, 0.3011,
		1.55, 5.3, 0.3011,
		1.35, 5.3, 0.3011,

};

static GLfloat normais[] = {
	
	  0,  -1.0,  0.0,
	  0,  -1.0,  0.0,
	  0,  -1.0,  0.0,
	  0,  -1.0,  0.0,
	  // x=tam (Direita)
		-1.0,  0.0,  0.0,
		-1.0,  0.0,  0.0,
		-1.0,  0.0,  0.0,
		-1.0,  0.0,  0.0,
		// y=tam (Cima)
	   1.0,  1.0,  0.0,
	   1.0,  1.0,  0.0,
	   1.0,  1.0,  0.0,
	   1.0,  1.0,  0.0,

	   0,  0.0,  -1.0,
		0,  0.0,  -1.0,
		0,  0.0,  -1.0,
		0,  0.0,  -1.0,
		// y=tam (Cima)
	   0.0,  0.0,  1.0,
	   0.0,  0.0,  1.0,
	   0.0,  0.0,  1.0,
	   0.0,  0.0,  1.0,

	   0,  0.0,  1.0,
		0,  0.0,  1.0,
		0,  0.0,  1.0,
		0,  0.0,  1.0,
		// y=tam (Cima)
	   0.0,  0.0,  -1.0,
	   0.0,  0.0,  -1.0,
	   0.0,  0.0,  -1.0,
	   0.0,  0.0,  -1.0,

	   0,  0.0,  1.0,
		0,  0.0,  1.0,
		0,  0.0,  1.0,
		0,  0.0,  1.0,
		// y=tam (Cima)
	   0.0,  0,  -1.0,
	   0.0,  0,  -1.0,
	   0.0,  0,  -1.0,
	   0.0,  0,  -1.0,

		 0.0, 0,  1.0,
	   0.0,  0,  1.0,
	   0.0,  0,  1.0,
	   0.0,  0,  1.0,

		0.0, 0,  -1.0,
	   0.0,  0,  -1.0,
	   0.0,  0,  -1.0,
	   0.0,  0,  -1.0,

	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

		-1.0,  0,  0.0,
	   -1.0,  0,  0.0,
	   -1.0,  0,  0.0,
	   -1.0,  0,  0.0,

		 1.0, 0,  0.0,
	   1.0,  0,  0.0,
	   1.0,  0,  0.0,
	   1.0,  0,  0.0,

		0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,
	   0.0,  1.0,  0.0,

	   0.0,  -1.0,  0.0,
	   0.0,  -1.0,  0.0,
	   0.0,  -1.0,  0.0,
	   0.0,  -1.0,  0.0,
	   //janela frente
		0,  0,  1.0,
	   0,  0,  1.0,
	   0,  0,  1.0,
	   0,  0,  1.0,

		1.0,  0,  0.0,
	   1.0,  0,  0.0,
	   1.0,  0,  0.0,
	   1.0,  0,  0.0,

	   0.0,  0,  -1.0,
	   0.0,  0,  -1.0,
	   0.0, 0,  -1.0,
	   0.0,  0,  -1.0,


	   0.0,  0,  1.0,
	   0.0,  0,  1.0,
	   0.0,  0,  1.0,
	   0.0,  0,  1.0,

		0.0, 0, 1.0,
		0.0, 0, 1.0,
		0.0, 0, 1.0,
		0.0, 0, 1.0,


		1.0, 0, 0.0,
		1.0, 0, 0.0,
		1.0, 0, 0.0,
		1.0, 0, 0.0,

		0.0, 0, 1.0,
		0.0, 0, 1.0,
		0.0, 0, 1.0,
		0.0, 0, 1.0,


		0.0, 0, -1.0,
		0.0, 0, -1.0,
		0.0, 0, -1.0,
		0.0, 0, -1.0,
		//frame esquerda esquerda
		-1.0, 0, 0.0,
		-1.0, 0, 0.0,
		-1.0, 0, 0.0,
		-1.0, 0, 0.0,

		-1.0, 0, 0.0,
		-1.0, 0, 0.0,
		-1.0, 0, 0.0,
		-1.0, 0, 0.0,

		   0.0, 0, 1.0,
		   0.0, 0, 1.0,
		   0.0, 0, 1.0,
		   0.0, 0, 1.0,


		   0.0, 0, -1.0,
		   0.0, 0, -1.0,
		   0.0, 0, -1.0,
		   0.0, 0, -1.0,

		1.0, 0, 0.0,
		1.0, 0, 0.0,
		1.0, 0, 0.0,
		1.0, 0, 0.0,

		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,

		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,

			0.0, 0, 1.0,
			0.0, 0, 1.0,
			0.0, 0, 1.0,
			0.0, 0, 1.0,

			 0.0, 0, -1.0,
			 0.0, 0, -1.0,
			 0.0, 0, -1.0,
			 0.0, 0, -1.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,

		0.0, 0.0, -1.0,
		0.0, 0.0, -1.0,
		0.0, 0.0, -1.0,
		0.0, 0.0, -1.0,
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

		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		
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


		//fechadura
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,

		  //trinco
	    0.427, 0.321, 0.192,
		0.427, 0.321, 0.192,
		0.427, 0.321, 0.192,
		0.427, 0.321, 0.192,


		//frame
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,

		1, 1, 1,
		1, 1, 1,
	    1, 1, 1,
	   1, 1, 1, 

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,	

		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,

		1, 1, 1,
		1, 1, 1,
	    1, 1, 1,
	   1, 1, 1, 

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

		1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

		1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

		1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,
	   1, 1, 1,

			1, 1, 1,
			1, 1, 1,
			1, 1, 1,
			1, 1, 1,
};

static GLfloat texturas[] = {
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,

0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,
0, 0,
1, 0,
1, 1,
0, 1,

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
static GLuint	janelafrente[] = {64, 65, 66, 67 };
static GLuint	janelalado[] = { 68, 69, 70, 71 };
static GLuint   janelatras[] = { 75,74,73,72 };
static GLuint   fechadura[] = { 76,77,78,79 };
static GLuint	trinco[] = { 80, 81, 82, 83 };
static GLuint   frameesqdir[] = { 84, 85, 86, 87 };
static GLuint   frameesqfrente[] = { 88, 89, 90, 91 };
static GLuint	frameesqtras[] = { 95, 94, 93, 92 };
static GLuint	frameesqesq[] = { 99, 98,97,96 };
static GLuint	framediresq[] = { 103, 102, 101, 100 };
static GLuint	framedirfrente[] = { 107,106,105,104 };
static GLuint   framedirtras[] = { 108,109,110,111 };
static GLuint	framedirdir[] = { 112, 113, 114, 115 };
static GLuint	framedirbaixo[] = {116,117,118,119};
static GLuint	frameesqbaixo[] = {120,121,122,123};
static GLuint	framecimafrente[] = { 124, 125, 126, 127 };
static GLuint	framecimatras[] = { 131, 130, 129, 128 };
static GLuint	framecimacima[] = { 132, 133, 134, 135 };
static GLuint	framecimabaixo[] = { 139,138,137,136 };
static GLuint	trincotras[] = { 143, 142, 141, 140 };


GLuint   texture[5];
RgbImage imag;




//---------------------------------------------------- AMBIENTE - fixa
GLint   Dia = 1;     //:::   'D'  
GLfloat intensidadeDia = 0.3;
GLfloat luzGlobalCorAmb[4] = { intensidadeDia, intensidadeDia,intensidadeDia, 1.0 };   // 

//---------------------------------------------------- Luz pontual no TETO (eixo Y)
GLint   ligaTeto = 1;		 //:::   'T'  
GLfloat intensidadeT = 0.3;  //:::   'I'  
GLint   luzR = 1;		 	 //:::   'R'  
GLint   luzG = 1;			 //:::   'G'  
GLint   luzB = 1;			 //:::   'B'  
GLfloat localPos[4] = { 1.0, 2.0, 2.0, 1.0 };
GLfloat localCorAmb[4] = {1, 0, 0, 1 };
GLfloat localCorDif[4] = { luzR, luzG, luzB, 1.0 };
GLfloat localCorEsp[4] = { luzR, luzG, luzB, 1.0 };
GLfloat localAttCon = 1;
GLfloat localAttLin = 1;
GLfloat localAttQua = 1;
GLfloat   quadS = 5.0;
GLint     material = 1;

void initLights(void) {
	//Ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);

	// Teto
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);

	if(ligaTeto){
		glEnable(GL_LIGHT0);
	}
	else {
		glDisable(GL_LIGHT0);
	}
	
}


//=========TEXTURAS



//------------------------------------------------------------ Texturas (4 texturas)




void initTexturas()
{
	
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	imag.LoadBmpFile("pedra.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());


	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("MossRock.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("madeira.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	imag.LoadBmpFile("Plastic.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	imag.LoadBmpFile("metal.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	
}




void drawScene() {
	
	glPushMatrix();
	glTranslatef(-1.8, 0, 0);
	glRotatef(alfaPorta, 0, 1, 0);
	glTranslatef(1.8, 0, 0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, baixo);   // desenhar uma das faces da mesa
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, tras);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frenteesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frentedir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trasesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trasdir);
	//glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frentecima);
	//glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trascima);
	//glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, topo);

	


	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intdir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intbaixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, intcima);
	glDisable(GL_TEXTURE_2D);
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture[3]);
			glTranslatef(posjanela, 0, 0);
			glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, janelafrente);
			glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT,	janelalado);
			glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, janelatras);
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, fechadura);
		glDisable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslatef(1.45, 4.5, 0);
		glRotatef(alfaTrinco, 0, 0, 1);
		glTranslatef(-1.45, -4.5, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trinco);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, trincotras);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frameesqdir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frameesqfrente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frameesqtras);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frameesqesq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framedirdir);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framedirfrente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framedirtras);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framediresq);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framedirbaixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frameesqbaixo);

	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framecimafrente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framecimatras);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framecimacima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, framecimabaixo);
	glDisable(GL_TEXTURE_2D);

	
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
	glClearColor(WHITE);		//………………………………………………………………………………Apagar
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

	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	initTexturas();
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	initLights();

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
	glViewport(0.25 * wScreen, 0.25 * hScreen, 1 * wScreen, 1 * hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (tipoProjeccao == 0)
		gluPerspective(anguloZ, (float)wScreen / hScreen, 0.1, 100);
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
		if ((alfaPorta == 0 && alfaTrinco > -45) || (alfaPorta != 0)) {
			if (alfaPorta < 90) {
				alfaPorta += 5;
			}
		}
		glutPostRedisplay();
		break;
	case 'x':	case 'X':

		if ((alfaPorta == 0 && alfaTrinco > -45) || (alfaPorta != 0)) {
			if (alfaPorta > -90) {
				alfaPorta -= 5;
			}
		}
		glutPostRedisplay();
		break;

		//------------------------------ projeccao
	case 'p': 	case 'P':
		tipoProjeccao = (tipoProjeccao + 1) % 2;
		glutPostRedisplay();
		break;
	


	case 'a':	case 'A':
		if (posjanela > -0.8) {
			posjanela -= 0.05;

		}
		glutPostRedisplay();
		break;

	case 's':	case 'S':
		if (posjanela < 0) {
			posjanela += 0.05;

		}
		glutPostRedisplay();
		break;

	case 'q':	case 'Q':
		if (alfaTrinco < 0) {

			alfaTrinco += 2;
		}
		break;


	case 'w':	case 'W':
		if (alfaTrinco > -90) {
			alfaTrinco -= 2;
		}
		break;

	case 't':case 'T':
		ligaTeto = !ligaTeto;
		
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
		obsT[0] = 0; obsT[1] = 4; obsT[2] = 0;
		
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
	glutCreateWindow("|Observador:'SETAS'|  |Projecao -'p'| |Porta - 'z x'| |Janela - 'a s'| |Trinco - 'q w'| ");

	initialize();

	glutSpecialFunc(teclasNotAscii);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}



