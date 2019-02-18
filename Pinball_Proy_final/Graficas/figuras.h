//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;
    void prisma1 (float altura, float largo, float profundidad, GLuint text, GLuint text2, GLuint text3);
    void prisma_F(float altura, float largo, float profundidad, GLuint text, GLuint text2, GLuint text3);
    void prisma_c(float altura, float largo, float profundidad, GLuint text, GLuint text2, GLuint text3,GLuint text4, GLuint text5);
	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
    void prisma3 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

	void esquina(GLuint textura1, GLuint textura2);
	void caja(GLuint textura1, GLuint textura2);
	void caja1(GLuint textura1, GLuint textura2, GLuint textura3);
	void caja2(GLuint textura1, GLuint textura2, GLuint textura3);
	void pata(GLuint textura1);
	void TexturaConCorrimiento(GLuint textura1, float varX, float varY);
	void TexturaEstatica(GLuint textura1);
	void Flippers(GLuint textura1, GLuint textura2);
};
