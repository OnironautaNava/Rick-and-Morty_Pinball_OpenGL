//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Nava García Mario Guillermo			******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

//Variables globales///
static GLuint ciudad_display_list;	//Display List for the Monito

char giro1;
char s[30];
bool giro = true;
bool anima = true;
bool ani = false;
bool switchCam = true;
bool adelante;
bool adelante1;
bool Der = false;
bool Izq = false;
bool g_fanimacion = false;
bool g_fanimacion1 = false;
int w = 500, h = 500;
int frame=0,time1,timebase=0;
int deltaTime = 0;
int refreshMillis = 5;
float angle;
float xa=-6, ya= 0, z=14; //Posición inicial de Morty
float xPos = 7.0, yPos = -0.25, zPos= 12.20;
float xPos1 = 7.0, yPos1 = -0.25, zPos1= 12.20;
float PosX = 7.0,PosY = -0.25, PosZ= 12.20;
float comp=2.0;
float comp1=-4.0;
float giro_Bol;
float var= 0.0f;
float DerFlip =120, IzqFlip=-120, CentFlip= 120;
float vuelta;
const double PI = 3.1415926535897;
GLfloat xPosMax, xPosMin, yPosMax, yPosMin, zPosMax, zPosMin;
GLfloat xSpeed = 0.002f; // velocidad a la que se movera en las X
GLfloat ySpeed = -.007f; // velocidad a la que se movera en las Y
GLfloat zSpeed = 0.003f; // velocidad a la que se movera en las Z
GLfloat radio;
GLdouble xLeft, xRight, yBottom, yTop;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW)
GLfloat g_lookupdown1 = 0.0f;

CCamera objCamera;	//Create objet Camera
CCamera objCamera1;

int* font=(int*)GLUT_BITMAP_HELVETICA_18;
float movBrazoDer = 0.0, movBrazoIzq;
float  movBrazo111=-30.0, movBrazo11=-15.0, movBrazo1=-45.0, alargueSom=0.0;

//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0, rotRodDer = 0, rotHombroIzq = 0, rotHombroDer = 0, giro_g = 50;
float giroMonito = 0;

#define MAX_FRAMES 50		//N˙mero de cuadros m·ximos que se estan capturando
int i_max_steps = 90;
int i_curr_steps = 0;	//Siempre se inicializa en 0

typedef struct _frame
{
    //Variables para GUARDAR Key Frames
    float posX;		//Variable para PosicionX
    float posY;		//Variable para PosicionY
    float posZ;		//Variable para PosicionZ
    float incX;		//Variable para IncrementoX
    float incY;		//Variable para IncrementoY
    float incZ;		//Variable para IncrementoZ
    float giro_g;
    float giro_ginc;
    float giro;
    float giroInc;
    
    float DerFlip=120;
    float DerFlipI;
    
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 12;			//introducir datos
bool play = false;
int playIndex = 0;

static int spin = 0;

bool	light = false;		// Luz ON/OFF
bool	light1 = false;
bool	positional = true;
bool	positional1 = true;

GLfloat EarthAmbient[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };			// Canica Oro
GLfloat EarthDiffuse[] = { 0.75164, 0.60648, 0.22648, 1.0 };
GLfloat EarthSpecular[] = { 0.628281, 0.555802, 0.366065, 1.0 };
GLfloat EarthShininess[] = { 0.4 };

GLfloat CirculoAmbient[] = { 0.0, 0.0, 0.0, 1.0f };			// contorno
GLfloat CirculoDiffuse[] = { 0.5, 0.0, 0.0, 1.0 };
GLfloat CirculoSpecular[] = { 0.7, 0.6, 0.6, 1.0 };
GLfloat CirculoShininess[] = { 0.25 };

GLfloat Position[] = { 0.0f, 0.0f, 15.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -3.0f };			// Light Position

GLfloat LightAmbient[] = { 1.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values negro
//GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values blanco
//GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };			// Specular Light Values blanco
GLfloat LightPosition[] = { 0.0f, 0.0f, 15.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f , 0.0f, -1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, -1.0f, 0.0f };			// Light Position
GLfloat LightDiffuse[] = { 1.00f, 0.0f, 0.0f, 1.0f };				// Diffuse Light Values blanco
GLfloat LightSpecular[] = { 0.0f, 0.0, 1.0, 1.0 };

GLfloat LightDiffuse1[] = { 1.00f, 0.0f, 0.0f, 1.0f };

GLfloat LightPosition3[] = { -6.35f, 14.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition2[] = { 1.0f, 1.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection3[] = { 0.0f, 0.0f, -2.0f };

GLfloat mat_diffusehoja[] = { 0.5f, 0.35f, 0.05f, 1.0f };				// Diffuse Light Values blanco
GLfloat mat_specularhoja[] = { 0.5f, 0.35f, 0.05f, 1.0f };
GLfloat mat_ambient[] = { 1.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 0.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest

GLfloat redDiffuseMaterial[] = { 1.0, 0.0, 0.0 }; //set the material to red
GLfloat whiteSpecularMaterial[] = { 1.0, 1.0, 1.0 }; //set the material to white
GLfloat greenEmissiveMaterial[] = { 0.0, 1.0, 0.0 }; //set the material to green
GLfloat whiteSpecularLight[] = { 1.0, 1.0, 1.0 }; //set thelight specular to white
GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0 }; //set the light ambient to black
GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0 }; //set the diffuse light to white
GLfloat blankMaterial[] = { 0.0, 0.0, 0.0 }; //set the diffuse light to white
GLfloat mShininess[] = { 128 }; //set the shininess of the material

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
//GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
//GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position
//glLightfv(GL_LIGHT0, GL_POSITION, Position);

CTexture text1;
CTexture text2;	//Pavimento
CTexture text3;	//Casa1

CTexture vidrio;
CTexture agua;
CTexture piso;
CTexture madera;
CTexture resorte;
CTexture rojo;
CTexture cafe;
CTexture azul;
CTexture carne;
CTexture amarillo;
CTexture scoreboard;
CTexture flipper;
CTexture green_portal;
CTexture characters_run;
CTexture luz1;
CTexture luz2;
CTexture luz3;
CTexture score;
CTexture fondo;
CTexture arbol;
CTexture logo;

CTexture pesera;
CTexture flash;
CTexture cara;

//Variables para modelos 3ds
CModel dragon;
CModel craneo;

//Variables contenedoras de figuras
CFiguras cubo;
CFiguras fig_skybox;//pavimento
CFiguras fig3;	//Casa
CFiguras fig7;	//FLash
CFiguras canica1;
CFiguras canica2;
CFiguras fig_esquinas;
CFiguras fig_mesa;
CFiguras fig_resorte;
CFiguras fig_baners;
CFiguras fig_flippers;

void prisma(void)
{
    GLfloat vertice [8][3] = {
        {0.5 ,-0.5, 0.5},    //Coordenadas VÈrtice 0 V0
        {-0.5 ,-0.5, 0.5},    //Coordenadas VÈrtice 1 V1
        {-0.5 ,-0.5, -0.5},    //Coordenadas VÈrtice 2 V2
        {0.5 ,-0.5, -0.5},    //Coordenadas VÈrtice 3 V3
        {0.5 ,0.5, 0.5},    //Coordenadas VÈrtice 4 V4
        {0.5 ,0.5, -0.5},    //Coordenadas VÈrtice 5 V5
        {-0.5 ,0.5, -0.5},    //Coordenadas VÈrtice 6 V6
        {-0.5 ,0.5, 0.5},    //Coordenadas VÈrtice 7 V7
				};
    
    glBegin(GL_POLYGON);	//Front
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[4]);
    glVertex3fv(vertice[7]);
    glVertex3fv(vertice[1]);
    glEnd();
    
    glBegin(GL_POLYGON);	//Right
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[3]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[4]);
    glEnd();
    
    glBegin(GL_POLYGON);	//Back
    glNormal3f( 0.0f, 0.0f, -1.0f);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[3]);
    glVertex3fv(vertice[2]);
    glEnd();
    
    glBegin(GL_POLYGON);  //Left
    glNormal3f( -1.0f, 0.0f, 0.0f);
    glVertex3fv(vertice[1]);
    glVertex3fv(vertice[7]);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[2]);
    glEnd();
    
    glBegin(GL_POLYGON);  //Bottom
    glNormal3f( 0.0f, -1.0f, 0.0f);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[1]);
    glVertex3fv(vertice[2]);
    glVertex3fv(vertice[3]);
    glEnd();
    
    glBegin(GL_POLYGON);  //Top
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glVertex3fv(vertice[4]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[7]);
    glEnd();
}

void jerarquico() {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, CirculoDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, CirculoSpecular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, CirculoAmbient);
    glMaterialfv(GL_FRONT, GL_SHININESS, CirculoShininess);
    
    glPushMatrix();//punta brazos
    glTranslatef(0.0, 6.0, 0.0);
    glTranslatef(0.0, 0, 0.0);
    glRotatef(0, 1.0, 0.0, 0.0);
    glRotatef(0, 0.0, 1.0, 0.0);
    glRotatef(0, 0.0, 0.0, 1.0);
        
    glPushMatrix();//Brazo 1
    glTranslatef(0.35f, 0.2f, 0.0f);
    glRotatef(-45, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(-15, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 1.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 1.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 1.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo 1
    
    glPushMatrix();//Brazo 2
    glTranslatef(0.0f, 0.2f, -0.35f);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 2.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 2.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 2.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 2.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo 2
    
    glPushMatrix();//Brazo 3
    glTranslatef(-0.35f, 0.2f, 0.0f);
    glRotatef(180, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 3.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 3.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 3.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 3.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo 3
    
    glPushMatrix();//Brazo 4
    glTranslatef(0.0f, 0.2f, 0.35f);
    glRotatef(-90, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 4.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 4.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 4.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 4.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo 4
    
    glPushMatrix();//Brazo 5
    glTranslatef(0.35f, 0.2f, 0.35f);
    glRotatef(-45, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 5.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 5.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 5.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 5.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo 5
    
    glPushMatrix();//Brazo 6
    glTranslatef(0.35f, 0.2f, -0.35f);
    glRotatef(45, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 6.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 6.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 6.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 6.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo6
    
    glPushMatrix();//Brazo 7
    glTranslatef(-0.35f, 0.2f, 0.35f);
    glRotatef(225, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 7.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 7.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 7.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 7.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo7
    
    glPushMatrix();//Brazo 8
    glTranslatef(-0.35f, 0.2f, -0.35f);
    glRotatef(135, 0.0, 1.0, 0.0);
    glRotatef(movBrazo1, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix();//Brazo 8.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo11, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    glPushMatrix(); //Brazo 8.1.1
    glTranslatef(1.25f, 0.0f, 0.0f);
    glRotatef(movBrazo111, 0.0, 0.0, 1.0);
    glTranslatef(1.25f, 0.0f, 0.0f);
    
    glScalef(2.5, 0.25, 0.25);
    glColor3f(1.0, 0.2, 0.0);
    prisma();
    glPopMatrix(); // Sale del stack del Brazo 8.1.1
    glScalef(2.5, .25, 0.25);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//Sale stack brazo 8.1
    glScalef(2.5, 0.25, 0.25);
    glRotatef(180, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    prisma();
    glPopMatrix();//Sale Brazo8
    
    
    glScalef(0.7, 1.0, 0.7);
    glRotatef(90, 1, 0, 0);
    glColor3f(1.0, 1.0, 0.0);
    prisma();
    glPopMatrix();//sale stack punta brazos
}

void TableroJerarquico(GLuint text1)
{
    glPushMatrix();
		glTranslatef(0.0, 1.5, 7.5);
		glPushMatrix();
			glTranslatef(-7.0, -2.7, -7.8);
			glRotatef(10, 1, 0, 0);
			glPushMatrix();
				glTranslatef(14.0, 0.0, 0.0);
				glScalef(1.0, 5, 1.0);
				fig_mesa.pata(madera.GLindex);//Pata Derecha Trasera
			glPopMatrix();
			glScalef(1.0, 5, 1.0);
			fig_mesa.pata(madera.GLindex);//Pata Izquierda Trasera
		glPopMatrix();
    
		glPushMatrix();
			glTranslatef(-7.0, -3.5, 7.3);
			glPushMatrix();
				glTranslatef(14, 0.0, 0);
				glScalef(1.0, 3.0, 1.0);
				fig_mesa.pata(madera.GLindex); //Pata Delantera Derecha
			glPopMatrix();
			glScalef(1.0, 3.0, 1.0);
			fig_mesa.pata(madera.GLindex);//Pata Delantera Izquerda
		glPopMatrix();
		glRotatef(10, 1, 0, 0);
		glScalef(15.0, 3.0, 16.0);
		fig_mesa.caja(madera.GLindex,vidrio.GLindex); //Sale Mesa
    glPopMatrix();
}

void Dragon()
{
	//glPushMatrix();
	//	glDisable(GL_COLOR_MATERIAL);
	glColor3f(0.1, 0.8, 0.1);
	glRotatef(10, 1, 0, 0);
	glScalef(0.01, 0.01, 0.01);
	dragon.GLrender(NULL, _SHADED, 1.0);
	//glPopMatrix();
}

void Craneo()
{
	//glPushMatrix();
	//glDisable(GL_COLOR_MATERIAL);
	glColor3f(0.9, 0.9, 0.9);
	glTranslatef(1.5, 1.6, 3.7);
	glScalef(0.3, 0.3, 0.3);
	glRotatef(-10, 1, 0, 0);
	craneo.GLrender(NULL, _SHADED, 1.0);
	//glPopMatrix();
}

void InitGL ( GLvoid )     // Inicializamos parametros
{
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
    
    glEnable(GL_TEXTURE_2D);
    
	GLfloat light_ambient[] = { 0.75, 0.75, 0.75, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 0, 0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, .0, 0.0 };
    
   //glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
    
    glShadeModel (GL_SMOOTH);
    //Para construir la figura comentar esto
    glLightfv(GL_LIGHT1, GL_POSITION, Position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
    
    glLightfv(GL_LIGHT2, GL_POSITION, Position);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse1);
    //glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glEnable ( GL_COLOR_MATERIAL );
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    //glPolygonMode(GL_BACK, GL_LINE);
    
    glClearDepth(1.0f);									// Configuramos Depth Buffer
    glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
    glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    
	//Seteo de Texturas
	text1.LoadBMP("night-sky.bmp");
    text1.BuildGLTexture();
    text1.ReleaseImage();

    vidrio.LoadTGA("vidrio.tga");
    vidrio.BuildGLTexture();
    vidrio.ReleaseImage();
    
    agua.LoadTGA("water01a.tga");
    agua.BuildGLTexture();
    agua.ReleaseImage();
    
	piso.LoadTGA("texture_ground_bluerocks.tga");
    piso.BuildGLTexture();
    piso.ReleaseImage();
    
    madera.LoadTGA("madera.tga");
    madera.BuildGLTexture();
    madera.ReleaseImage();
    
    scoreboard.LoadTGA("rick-and-morty_science-time.tga");
    scoreboard.BuildGLTexture();
    scoreboard.ReleaseImage();
    
	resorte.LoadTGA("resorte.tga");
	resorte.BuildGLTexture();
	resorte.ReleaseImage();

	flipper.LoadTGA("flipper.tga");
	flipper.BuildGLTexture();
	flipper.ReleaseImage();

    amarillo.LoadTGA("amarillo.tga");
    amarillo.BuildGLTexture();
    amarillo.ReleaseImage();

	azul.LoadTGA("azul.tga");
	azul.BuildGLTexture();
	azul.ReleaseImage();

	carne.LoadTGA("carne.tga");
	carne.BuildGLTexture();
	carne.ReleaseImage();

	cafe.LoadTGA("cafe.tga");
	cafe.BuildGLTexture();
	cafe.ReleaseImage();

	arbol.LoadTGA("tree.tga");
	arbol.BuildGLTexture();
	arbol.ReleaseImage();

	luz1.LoadTGA("lazer.tga");
	luz1.BuildGLTexture();
	luz1.ReleaseImage();

	luz2.LoadTGA("rick_rayo-laser.tga");
	luz2.BuildGLTexture();
	luz2.ReleaseImage();

	luz3.LoadTGA("luz3.tga");
	luz3.BuildGLTexture();
	luz3.ReleaseImage();

	logo.LoadTGA("Rick_and_Morty_logo.tga");
	logo.BuildGLTexture();
	logo.ReleaseImage();

	score.LoadTGA("score.tga");
	score.BuildGLTexture();
	score.ReleaseImage();

	fondo.LoadTGA("Rick-And-Morty-fondo-tablero.tga");
	fondo.BuildGLTexture();
	fondo.ReleaseImage();

    green_portal.LoadTGA("rick_y_morty_green-portal.tga");
    green_portal.BuildGLTexture();
    green_portal.ReleaseImage();
    
    characters_run.LoadTGA("rick-morty-chars-run.tga");
    characters_run.BuildGLTexture();
    characters_run.ReleaseImage();
       
	///////////////////
    text2.LoadTGA("pavimento.tga");
    text2.BuildGLTexture();
    text2.ReleaseImage();

    text3.LoadTGA("casa01.tga");
    text3.BuildGLTexture();
    text3.ReleaseImage();

    pesera.LoadTGA("pecera.tga");
    pesera.BuildGLTexture();
    pesera.ReleaseImage();

    //modelos 3ds
	dragon._3dsLoad("Dragon.3ds");
	craneo._3dsLoad("skull.3ds");
    
    objCamera.Position_Camera(0,12.5f,22, 0,2.5f,0, 0, 1, 0);
    objCamera1.Position_Camera(-6,1.5f,15, -6,5.5f,0, 0, 1, 0);
	    
    //NEW Iniciar variables de KeyFrames
    /*for(int i=0; i<MAX_FRAMES; i++)
     {
     KeyFrame[i].posX =0;
     KeyFrame[i].posY =0;
     KeyFrame[i].posZ =0;
     KeyFrame[i].incX =0;
     KeyFrame[i].incY =0;
     KeyFrame[i].incZ =0;
     KeyFrame[i].rotRodIzq =0;
     KeyFrame[i].rotInc =0;
     KeyFrame[i].giroMonito =0;
     KeyFrame[i].giroMonitoInc =0;
     KeyFrame[i].giroBrazo =0;
     KeyFrame[i].giroBrazoInc = 0/;
     
     }*/
    
    KeyFrame[0].posX = 7.0;
    KeyFrame[0].posY = -0.25;
    KeyFrame[0].posZ = 12.20;
    KeyFrame[0].DerFlip = 120;
    
    KeyFrame[1].posX = 7.0;
    KeyFrame[1].posY = 1.4;
    KeyFrame[1].posZ = 1;
    KeyFrame[1].DerFlip = 120;
    
    KeyFrame[2].posX = 2.0;
    KeyFrame[2].posY = 1.2;
    KeyFrame[2].posZ = 2.0;
    KeyFrame[2].DerFlip = 120;
    
    KeyFrame[3].posX = -7.0;
    KeyFrame[3].posY = 1.0;
    KeyFrame[3].posZ = 3.0;
    KeyFrame[3].DerFlip = 120;
    
    KeyFrame[4].posX = -3;
    KeyFrame[4].posY = 0.8;
    KeyFrame[4].posZ = 5.0;
    KeyFrame[4].DerFlip = 120;
    
    KeyFrame[5].posX = -7;
    KeyFrame[5].posY = 0.6;
    KeyFrame[5].posZ = 7.0;
    KeyFrame[5].DerFlip = 120;
    
    KeyFrame[6].posX = -4.3;
    KeyFrame[6].posY = 0.3;
    KeyFrame[6].posZ = 8.5;
    KeyFrame[6].DerFlip = 120;
    
    KeyFrame[7].posX = 3.6;
    KeyFrame[7].posY = 0.3;
    KeyFrame[7].posZ = 8.7;
    KeyFrame[7].DerFlip = 120;
    
    KeyFrame[8].posX = -4;
    KeyFrame[8].posY = 0.0;
    KeyFrame[8].posZ = 11.2;
    KeyFrame[8].DerFlip = 120;
    
    KeyFrame[9].posX = 1.2;
    KeyFrame[9].posY = -0.2;
    KeyFrame[9].posZ = 13.4;
    KeyFrame[9].DerFlip = 120;
    
    KeyFrame[10].posX = -0.8;
    KeyFrame[10].posY = -0.0;
    KeyFrame[10].posZ = 11.2;
    KeyFrame[10].DerFlip = 60;
    
    KeyFrame[11].posX = -0.8;
    KeyFrame[11].posY = -0.0;
    KeyFrame[11].posZ = 11.2;
    KeyFrame[11].DerFlip = 120;
    //NEW//////////////////NEW//////////////////NEW//////////////////
    
}

void Morty()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpecularMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
	glPushMatrix();//Pecho
		glScalef(0.5, 0.5, 0.5);
		fig7.cilindro(1, 2, 24, amarillo.GLindex);

		glPushMatrix();//Cuello
			glTranslatef(0, 2.0, 0.0);
			fig7.cilindro(0.25, 0.5, 15, carne.GLindex);
			glPushMatrix();//Cabeza
				glTranslatef(0, 1.4, 0);
				fig7.esfera(1.2, 24, 24, carne.GLindex);
				glPushMatrix();//Cabello
					glTranslatef(0, 0.3, -0.3);
					fig7.esfera(1.1, 24, 24, cafe.GLindex);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo derecho-->
			glTranslatef(1.25, 1.5, 0);
			glRotatef(rotHombroDer, 0.0, 1.0, 0.0);
			fig7.esfera(0.5, 12, 12, amarillo.GLindex);
			glPushMatrix();
				glTranslatef(0, -2, 0);
				glRotatef(0, 0.0, 0.0, 1.0);
				fig7.cilindro(0.5, 2, 24, amarillo.GLindex);
				glPushMatrix();
					glTranslatef(0, -0.3, 0);
					fig7.esfera(0.4, 12, 12, carne.GLindex);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo izquierdo-->
			glTranslatef(-1.25, 1.5, 0);
			glRotatef(rotHombroDer, 0.0, 1.0, 0.0);
			fig7.esfera(0.5, 12, 12, amarillo.GLindex);
			glPushMatrix();
				glTranslatef(0, -2, 0);
				glRotatef(0, 0.0, 0.0, 1.0);
				fig7.cilindro(0.5, 2, 24, amarillo.GLindex);
				glPushMatrix();
					glTranslatef(0, -0.3, 0);
					fig7.esfera(0.4, 12, 12, carne.GLindex);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//Cintura
			glTranslatef(0, -1.5, 0);

			glPushMatrix(); //Pie Derecho -->
				glTranslatef(0.7, -0.75, 0);
				fig7.cilindro(0.5, 2.3, 16, azul.GLindex);
				glPushMatrix();
					glTranslatef(0, -0.5, 0.3);
					fig7.prisma1(0.2, 1.0, 1.5, cafe.GLindex, cafe.GLindex, cafe.GLindex);
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //Pie Izquierdo -->
				glTranslatef(-0.7, -0.75, 0);
				fig7.cilindro(0.5, 2.3, 16, azul.GLindex);
				glPushMatrix();
					glTranslatef(0, -0.5, 0.3);
					fig7.prisma1(0.2, 1.0, 1.5, cafe.GLindex, cafe.GLindex, cafe.GLindex);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void ScoreBoard() {
	//Score
	glPushMatrix();
	glTranslatef(5.5, 12, -0.5);
	glScalef(4, 2, 1);
	fig_baners.TexturaEstatica(score.GLindex);
	glPopMatrix();

	//Scoreboard
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0.0, 0.0, -8.5);
	glScalef(15.0, 0.5, 10.0);
	fig_mesa.caja1(madera.GLindex, vidrio.GLindex, scoreboard.GLindex);
	glPopMatrix();
}

void AdornosInteriores() {
	//Textura luz1
	glPushMatrix();
	glTranslatef(5, 1, 7);
	glRotatef(-90, 1, 0, 0);
	glScalef(4.0, 4.0, 1);
	//fig_baners.TexturaConCorrimiento(luz1.GLindex, var, 0);
	glPopMatrix();

	//Textura luz2 Lazer verde
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 11.5);
	glRotatef(100, 1, 0, 0);
	glScalef(1.0, 4.5, 1);
	fig_baners.TexturaConCorrimiento(luz2.GLindex, 0, var);
	glPopMatrix();

	//Textura luz3
	glPushMatrix();
	glTranslatef(4, 1.8, 1.3);
	glRotatef(180, 0, 1, 0);
	glRotatef( 80, 1, 0, 0);
	glScalef(3.0, 1.0, 1);
	fig_baners.TexturaConCorrimiento(luz1.GLindex, var, 0);
	glPopMatrix();
}

void TableroInterior() {
	
	//nombre pinball
	glPushMatrix();
		glTranslatef(-5, 9, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(9, 2, 1);
		fig_baners.TexturaConCorrimiento(logo.GLindex, var*0.7, 0);
	glPopMatrix();

	//Objeto por modelado jerarquico
	glPushMatrix();
		glTranslatef(-5.0, -0.25, 9);
		glRotatef(10, 1, 0, 0);
		glScalef(0.2, 0.15, 0.2);
		jerarquico();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(4.5, -0.55, 10.5);
		glRotatef(10, 1, 0, 0);
		glScalef(0.2, 0.15, 0.2);
		jerarquico();
	glPopMatrix();

	//Obstáculo 3ds
	glPushMatrix();
		Craneo();//Bum1
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-4, -.3, 2);
		Craneo();//Bum2
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, -.7, 4);
		Craneo();//Bum3
	glPopMatrix();

	//Obstaculo 3ds
	glPushMatrix();//Dragon1
		glTranslatef(-4.8, 0.5, 10);
		Dragon();
	glPopMatrix();
	glPushMatrix();//Dragon2
		glTranslatef(-6.5, 1.9, 0.5);
		Dragon();
	glPopMatrix();

	//Canal para pelota
	glPushMatrix();
	glTranslatef(6, 0.0, 8.75);
	glRotatef(10, 1, 0, 0);
	glScalef(1, 0.5, 13.0);
	fig_mesa.caja1(madera.GLindex, madera.GLindex, madera.GLindex);
	glPopMatrix();

	//Esquinas inferiores	
	glPushMatrix();//Izquierda
	glTranslatef(-5.5, -0.75, 13);
	glRotatef(180, 0, 1, 0);
	glRotatef(-10, 1, 0, 0);
	glScalef(4, 0.5, 4);
	fig_esquinas.esquina(madera.GLindex, madera.GLindex);
	glPopMatrix();
	glPushMatrix();//Derecha
	glTranslatef(4.5, -0.75, 13);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-10, 0, 0, 1);
	glScalef(4, 0.5, 4);
	fig_esquinas.esquina(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//Esquina superior derecha
	glPushMatrix();
	glTranslatef(7, 1.5, 0);
	glRotatef(10, 1, 0, 0);
	glScalef(1, 0.5, 1);
	fig_esquinas.esquina(madera.GLindex, madera.GLindex);
	glPopMatrix();

	//Texturas por dentro de la caja
	glPushMatrix();
	glTranslatef(0.0, 1.5, 7.5);
	glRotatef(10, 1, 0, 0);
	glScalef(14.9, 2.9, 15.9);
	fig_mesa.caja2(green_portal.GLindex, characters_run.GLindex, fondo.GLindex);
	glPopMatrix();
}

void Flippers() {
	//Flippers
	glPushMatrix();//Derecho
		glMaterialfv(GL_FRONT, GL_DIFFUSE, redDiffuseMaterial);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpecularLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmbientLight);
		glMaterialfv(GL_FRONT, GL_SHININESS, mShininess);
		glTranslatef(3.0, -0.55, 12.95);
		glRotatef(10, 1, 0, 0);
		glRotatef(DerFlip, 0, 1, 0);
		glScalef(1.0, 0.5, 3.0);
		fig_flippers.Flippers ( 0, flipper.GLindex);
	glPopMatrix();

	glPushMatrix();//Izquierdo
		glMaterialfv(GL_FRONT, GL_DIFFUSE, redDiffuseMaterial);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpecularLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmbientLight);
		glMaterialfv(GL_FRONT, GL_SHININESS, mShininess);
		glTranslatef(-3.5, -0.55, 12.95);
		glRotatef(10, 1, 0, 0);
		glRotatef(IzqFlip, 0, 1, 0);
		glScalef(1.0, 0.5, 3.0);
		fig_flippers.Flippers(0, flipper.GLindex);
	glPopMatrix();

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, redDiffuseMaterial);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpecularLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackAmbientLight);
		glMaterialfv(GL_FRONT, GL_SHININESS, mShininess);
		glTranslatef(4.75, 0.15, 8.0);
		glRotatef(10, 1, 0, 0);
		glRotatef(CentFlip, 0, 1, 0);
		glScalef(1.0, 0.5, 2.0);
		fig_flippers.Flippers(0, flipper.GLindex);
	glPopMatrix();
}

void Resorte() {
	//Resorte
	glPushMatrix();
		glTranslatef(7, -0.55, 12.25);
		glRotatef(100, 1, 0, 0);
		glRotatef(-90, 0, 1, 0);
		glRotatef(180, 1, 0, 0);
		glTranslatef(0.0, -2.0, 0);
		fig_resorte.cilindro(0.5, comp, 30, resorte.GLindex);
	glPopMatrix();
	//Palanca
	glPushMatrix();
		glTranslatef(7, -0.55, 12.25);
		glRotatef(100, 1, 0, 0);
		glRotatef(-90, 0, 1, 0);
		glRotatef(180, 1, 0, 0);
		glTranslatef(0.0, comp1, 0.0);
		fig_resorte.cilindro(0.5, 2.0, 30, azul.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(7, -0.55, 12.25);
		glRotatef(100, 1, 0, 0);
		glRotatef(-90, 0, 1, 0);
		glRotatef(180, 1, 0, 0);
		glTranslatef(0.0, comp1, 0.0);
		fig_resorte.cilindro(1.0, 0.15, 30, azul.GLindex);
	glPopMatrix();
}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
    
    char *c;     //Almacena los caracteres a escribir
    glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
    //glWindowPos2i(150,100);
    for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
    {
        glutBitmapCharacter(font, *c); //imprime
    }
}

void Arbol()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, arbol.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 2.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 2.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 2.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 2.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 2.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 2.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 2.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 2.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();

}

void Entorno() {
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig_skybox.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();//MAR
	glTranslatef(0.0, -4.0, -65.0);
	glBindTexture(GL_TEXTURE_2D, agua.GLindex);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);;
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0 + var, 0.0 + var); glVertex3f(-65, 0.0, 0.0);//V1
	glTexCoord2f(1.0 + var, 0.0 + var); glVertex3f(65, 0.0, 0.0);//V2
	glTexCoord2f(1.0 + var, 1.0 + var); glVertex3f(65, 0.0, 130.0);//V3
	glTexCoord2f(0.0 + var, 1.0 + var); glVertex3f(-65, 0.0, 130.0);//V4
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);

	//Árboles
	int dis = 10;
	for (int i = 0; i < 5; i++) {
		glPushMatrix();
		glTranslatef(-20, -4, -15 + (i*dis));
		glScalef(4, 15, 4);
		Arbol();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(20, -4, -15 + (i*dis));
		glScalef(4, 15, 4);
		Arbol();
		glPopMatrix();
	}

	//Suelo
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glTranslatef(0.0, -4.0, 0.0);
	glScalef(68.0, 1.0, 60);
	glColor3f(1.0, 1.0, 1.0);
	fig3.prisma3(piso.GLindex, piso.GLindex);
	glPopMatrix();

	glEnable(GL_BLEND);
}

void display ( void )   // Creamos la funcion donde se dibuja
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    glPushMatrix();
		if (switchCam) {
		glRotatef(g_lookupdown,1.0f,0,0);
    
		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,
				  objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
				  objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		}
		else{
			glRotatef(g_lookupdown1, 1.0f, 0, 0);
			gluLookAt(objCamera1.mPos.x, objCamera1.mPos.y, objCamera1.mPos.z,
					  objCamera1.mView.x, objCamera1.mView.y, objCamera1.mView.z,
					  objCamera1.mUp.x, objCamera1.mUp.y, objCamera1.mUp.z);
		}
    
		glPushMatrix();
		
			Entorno();
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
			glPushMatrix();
				if (positional)
				{
					glRotatef(vuelta, 1,0,0);
					//glColor3f(1, 0, 0);
					glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
					glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);
					glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
				}
				else
					glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
    
				glPushMatrix();
					glDisable(GL_LIGHTING);
				   // glColor3f(1.0, 1.0, 1.0);
    
					glutSolidSphere(.07, 10, 10);
					if (!light)
					{
						glDisable(GL_LIGHTING);
						AdornosInteriores();
					}
					else
					{
						glRotatef(vuelta, 1, 0, 0);
						glEnable(GL_LIGHTING);
						glColor3f(1.0, 1.0, 1.0);
					}
			glPopMatrix();
		glPopMatrix();
    	
		//Canica1
		glPushMatrix();
			glColor3f(0.30754, 0.30754, 0.30754);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glMaterialfv(GL_FRONT, GL_AMBIENT, EarthAmbient);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
			glTranslatef(xPos1, yPos1, zPos1);
			glRotatef(10, 1, 0, 0);
			glRotatef(giro_Bol, -1, 0, 0);
			canica1.esfera(0.25, 30, 30, 0);
		glPopMatrix();

		//Canica2
		glPushMatrix();
			glColor3f(0.30754, 0.30754, 0.30754);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glMaterialfv(GL_FRONT, GL_AMBIENT, EarthAmbient);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
			glTranslatef(posX, posY, posZ);
			glRotatef(10, 1, 0, 0);
			glRotatef(giro_Bol, -1, 0, 0);
			canica2.esfera(0.25, 30, 30, 0);
		glPopMatrix();

		ScoreBoard();
	
		//Personaje
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_DIFFUSE, CirculoDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, CirculoSpecular);
			glMaterialfv(GL_FRONT, GL_AMBIENT, CirculoAmbient);
			glMaterialfv(GL_FRONT, GL_SHININESS, CirculoShininess);
			glTranslatef(xa, ya, z);
			glRotatef(10, 1, 0, 0);
			glRotatef(180, 0, 1, 0);
			glScalef(0.5, 0.5, 0.5);
			Morty();
		glPopMatrix();
    
		TableroInterior();

		Flippers();

		Resorte();

		glPushMatrix();
			glTranslatef(-6.35, 14.0, 0.5);
			glutSolidSphere(.07, 10, 10);
			if (positional1)
			{
				glRotatef(vuelta, 1, 0, 0);
				glDisable(GL_LIGHTING);
				glLightfv(GL_LIGHT3, GL_POSITION, LightPosition3);
				glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, LightDirection3);
				glLightfv(GL_LIGHT3, GL_DIFFUSE, redDiffuseMaterial);
			}
			else
				glLightfv(GL_LIGHT3, GL_POSITION, LightPosition1);
		glPopMatrix();
	
		//Tablero
		glPushMatrix();
			TableroJerarquico(madera.GLindex);
		glPopMatrix();
    
		glDisable(GL_BLEND);
          
		glPopMatrix();
    glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void *)font, "Rick & Morty Pinball");
	pintaTexto(-11, 10.5, -14, (void *)font, "Score: 0000000");
	pintaTexto(-11, 8.5, -14, (void *)font, s);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
    
    glutSwapBuffers ( );
}

void animacion()
{
	//Animación canica 1
    if (g_fanimacion)
    {
        if (adelante)
        {
            if (zPos1 >= 1.20) {
                giro_Bol += 10;
                zPos1 -= 1;
                yPos1 += 0.14;
            }
            else if (zPos1 > 0) {
                giro_Bol += 10;
                zPos1 -= .2;
                xPos1 -= .2;
                yPos1 += 0.0;
            }
        }
        else
        {
            if (zPos1 < 4) {
                giro_Bol -= 10;
                zPos1 += .25;
                yPos1 -= 0.045;
                xPos1 -= 0.25;
            }
            else if (zPos1 < 7) {
                giro_Bol -= 10;
                zPos1 += 0.25;
                yPos1 -= 0.045;
                xPos1 += 0.2;
            }
            else if (zPos1 < 9) {
                giro_Bol -= 10;
                zPos1 += 0.25;
                yPos1 -= 0.03;
                xPos1 -= 1.0;
            }
            else if (zPos1 < 12) {
                giro_Bol -= 10;
                zPos1 += 0.375;
                yPos1 -= 0.045;
                xPos1 += 0.5;
            }
            else if (zPos1 < 13.19) {
                giro_Bol -= 10;
                zPos1 += .125;
                yPos1 -= 0.025;
                xPos1 -= 0.15;
                printf("\n %f \n" ,zPos1);
            }
            else if (zPos1 < 13.40) {
                zPos1 =13.50;
                yPos1 = -0.25;
                xPos1 = 7.0;
            }
        }
        if (zPos1 <= 0.0)
            adelante = false;
        if (zPos1 >= 13.50)
            adelante = true;
    }
    else
    {
        zPos1 =12.20;
        yPos1 = -0.25;
        xPos1 = 7.0;
    }
    //Movimiento por keyframes
    if (play)
    {
        
        if (i_curr_steps >= i_max_steps) //end of animation between frames?
        {
            playIndex++;
            if (playIndex > FrameIndex - 2)	//end of total animation?
            {
                printf("Fin de animacion por keyframes\n");
                playIndex = 0;
                play = false;
            }
            else //Next frame interpolations
            {
				printf("Play Index: %d\n", playIndex);
				printf("\tCoordenadas ( %0.2f, %0.2.f, %0.2.f)\n", posX, posY, posZ);
                i_curr_steps = 0; //Reset counter
                //Interpolation
                KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
                KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
                KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	
                KeyFrame[playIndex].DerFlipI = (KeyFrame[playIndex + 1].DerFlip - KeyFrame[playIndex].DerFlip) / i_max_steps;
						
            }
        }
        else
        {	//Draw information
            posX += KeyFrame[playIndex].incX;
            posY += KeyFrame[playIndex].incY;
            posZ += KeyFrame[playIndex].incZ;
            DerFlip += KeyFrame[playIndex].DerFlipI;
                        
            i_curr_steps++;
        }
    }
    
    frame++;
    time1 = glutGet(GLUT_ELAPSED_TIME);
    if (time1 - timebase > 1000) {
        sprintf(s, "FPS:%4.2f", frame*1000.0 / (time1 - timebase));
        timebase = time1;
        frame = 0;
    }
    
    var += 0.0002;
    glutPostRedisplay();
}

void Transicion(){
    display();
    
    xPos += xSpeed;
    yPos += ySpeed;

    if (xPos > xPosMax) {
        xPos = xPosMax;
        xSpeed = -xSpeed;
    } else if (xPos < xPosMin) {
        xPos = xPosMin;
        xSpeed = -xSpeed;
    }
    if (yPos > yPosMax) {
        yPos = yPosMax;
        ySpeed = -ySpeed;
    } else if (yPos < yPosMin) {
        yPos = yPosMin;
        ySpeed = -ySpeed;
    }
}

void reshape(GLsizei weight, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)weight / height;
    
    glViewport(1, 1, weight, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (weight <= height) {
        xLeft = -1.0;
        xRight = 1.0;
        yBottom = -1.0 / aspect;
        yTop = 1.0 / aspect;
    } else {
        xLeft = -1.0 * aspect;
        xRight = 1.0 * aspect;
        yBottom = -1.0;
        yTop = 1.0;
    }
    gluOrtho2D(xLeft, xRight, yBottom, yTop);
    xPosMin = xLeft + radio;
    yPosMax = yTop - radio;
    xPosMax = xRight - radio;
    yPosMin = yBottom + radio;
    
    glViewport(0,0,weight,height);
    
    glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
    glLoadIdentity();
    
    // Tipo de Vista
    
    glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshMillis, Timer, 0);
}

void keyboard_up ( unsigned char key, int x, int y )  // Create Keyboard Function
{
    if (key == 'm' || key == 'M') {
        DerFlip +=60;
    }
    if (key == 'b' || key == 'B') {
        IzqFlip -=60;
    }
    if (key == 'n' || key == 'N') {
        CentFlip +=60;
    }
    if (key == ' ') {
        DerFlip += 60;
        IzqFlip -=60;
    }
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
    switch ( key ) {
            
        ///////////Movimiento de Flippers///////////    
        case 'm':
        case 'M':
            if (DerFlip > 60) {
                DerFlip -=60;
            }
            break;
        case 'b':
        case 'B':
            if (IzqFlip < -60) {
                IzqFlip +=60;
            }
            break;
        case 'n':
        case 'N':
            if (CentFlip > 60) {
                CentFlip -=60;
            }
            break;
        case ' ':
            if (DerFlip > 60 && IzqFlip < -60) {
                DerFlip -=60;
                IzqFlip +=60;
            }
            break;
			//Movimientos de camara///////////////
        case 'w':   
        case 'W':
            if (switchCam) {
            objCamera.Move_Camera( CAMERASPEED+0.05 );
            }
            else
            {
                objCamera1.Move_Camera( CAMERASPEED+0.02 );
                z -= 2.6;
                ya += 0.4;
            }
            break;
            
        case 's':
        case 'S':
            if (switchCam) {
            objCamera.Move_Camera(-(CAMERASPEED+0.05));
            }
            else{
                objCamera1.Move_Camera( -(CAMERASPEED+0.02) );
                z += 2.6;
                ya -= 0.4;
            }
            break;
            
        case 'a':
        case 'A':
            if (switchCam) {
            objCamera.Strafe_Camera(-(CAMERASPEED+0.1));
            }
            else{
                objCamera1.Strafe_Camera( -(CAMERASPEED+0.01) );
                xa -= 2.4;
            }
            break;
            
        case 'd':
        case 'D':
            if (switchCam) {
                objCamera.Strafe_Camera( CAMERASPEED+0.1);
            }
            else{
                objCamera1.Strafe_Camera( CAMERASPEED+0.01 );
                xa += 2.4;
            }
            break;
           ///////////////////////////////////////////
        case '8':
            if (switchCam) {
                objCamera.UpDown_Camera(CAMERASPEED);
            }
            else{
                objCamera1.UpDown_Camera(CAMERASPEED);
            }
            break;
            
        case '2':
            if (switchCam) {
                objCamera.UpDown_Camera(-CAMERASPEED);
            }
            else{
                objCamera1.UpDown_Camera(-CAMERASPEED);
            }
            break;
         /////////////////////////////////////////////////////   
        case '1':
            g_fanimacion^= true; //Activamos/desactivamos la animacÌon
            
            break;
		//////luces////////////////////////////
        case 'j':   //Activamos/desactivamos luz
        case 'J':
            light = !light;
            if (light == 0)
                printf("apagada\n");
            else
                printf("prendida\n");
            break;
        case 'k':   //Activamos/desactivamos luz
        case 'K':
            positional = !positional;
            if (positional == 1)
                printf("\n");
            else
                printf("\n");
            break;
		case 'l':   //Activamos/desactivamos luz
		case 'L':
			positional1 = !positional1;
			if (positional1 == 1)
				printf("\n");
			else
				printf("\n");
			break;
        case '9':
            vuelta -= 10;
            break;
		case 'c':   //cambiamos camara
		case 'C':
			switchCam = !switchCam;
			break;
            
        case 'r':		//
        case 'R':
            if (FrameIndex<MAX_FRAMES)
            {
                printf("Frameindex %d\n", FrameIndex);
                
                KeyFrame[FrameIndex].posX = posX;
                KeyFrame[FrameIndex].posY = posY;
                KeyFrame[FrameIndex].posZ = posZ;
                KeyFrame[FrameIndex].DerFlip = DerFlip;
                
                FrameIndex++;
            }
            
            break;
            
        case 'p':
        case 'P':
            if (play == false && (FrameIndex>1))
            {
				
                posX = KeyFrame[0].posX;
                posY = KeyFrame[0].posY;
                posZ = KeyFrame[0].posZ;
                DerFlip = KeyFrame[0].DerFlip;
                
                //First Interpolation
                KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
                KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
                KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	
                KeyFrame[playIndex].DerFlipI = (KeyFrame[playIndex + 1].DerFlip - KeyFrame[playIndex].DerFlip) / i_max_steps;
                
                play = true;
                playIndex = 0;
                i_curr_steps = 0;
                positional = !positional;
            }
            else
            {
                play = false;
            }
            break;
        
        case 27:        // Cuando Esc es presionado...
            exit ( 0 );   // Salimos del programa
            break;
        default:        // Cualquier otra
            break;
    }
    
    glutPostRedisplay();
}

void ControlRaton(int button, int state, int x, int y) {
    if (button==GLUT_LEFT_BUTTON || state==GLUT_DOWN) {
        if (comp > 0.5) {
            comp -= 1.5;
            comp1 -=1.0;
        }
            zPos1 += 1.3;
    }
    if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) {
            comp +=1.5;
            comp1 +=1.0;
            g_fanimacion ^= true; //Activamos/desactivamos la animacÃon
    }
    if (button==GLUT_RIGHT_BUTTON && state==GLUT_UP) {
       if (IzqFlip < -60) {
            IzqFlip +=60;
        }
    }
    glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
    switch ( a_keys ) {
        case GLUT_KEY_PAGE_UP:
            if (switchCam) {
            objCamera.UpDown_Camera(CAMERASPEED);
            }
            else{
                objCamera1.UpDown_Camera(CAMERASPEED);
            }
            break;
            
        case GLUT_KEY_PAGE_DOWN:
            if (switchCam) {
                objCamera.UpDown_Camera(-CAMERASPEED);
            }
            else{
                objCamera1.UpDown_Camera(-CAMERASPEED);
            }
            break;
            
        case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
            if (switchCam) {
            g_lookupdown -= 1.0f;
            }
            else{
                g_lookupdown1 -=1.0f;
            }
            break;
            
        case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
            if (switchCam) {
                g_lookupdown += 1.0f;
            }
            else{
                g_lookupdown1 +=1.0f;
            }
            break;
            
        case GLUT_KEY_LEFT:
            if (switchCam) {
            objCamera.Rotate_View(-CAMERASPEED);
            }
            else{
            objCamera1.Rotate_View(-CAMERASPEED);
            }
            break;
            
        case GLUT_KEY_RIGHT:
            if (switchCam) {
            objCamera.Rotate_View( CAMERASPEED);
            }
            else{
            objCamera1.Rotate_View( CAMERASPEED);
            }
            break;
            
        default:
            break;
    }
    glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{
    glutInit            (&argc, argv); // Inicializamos OpenGL
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
    glutInitWindowSize  (1000, 1000);	// TamaÒo de la Ventana
    glutInitWindowPosition (0, 0);	//Posicion de la Ventana
    glutCreateWindow    ("Pinball"); // Nombre de la Ventana
    //glutFullScreen     ( );         // Full Screen
    InitGL ();						// Parametros iniciales de la aplicacion
    glutDisplayFunc     ( display );  //Indicamos a Glut funciÛn de dibujo
    glutDisplayFunc(Transicion);
    glutReshapeFunc     ( reshape );	//Indicamos a Glut funciÛn en caso de cambio de tamano
    glutKeyboardUpFunc    ( keyboard_up );
    glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funciÛn de manejo de teclado
    glutMouseFunc(ControlRaton);
    glutSpecialFunc     ( arrow_keys );	//Otras
    glutIdleFunc	  ( animacion );
    glutMainLoop        ( );          // 
    
    return 0;
}

