// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>

using namespace std;

//Declarar una ventana
GLFWwindow* window;
float posXTriangulo = 0.0f , posYTriangulo = 0.0f;

float posXCuadrado = 0.5f, posYCuadrado = 0.5f;

double tiempoActual, tiempoAnterior;
double velocidadTriangulo = 0.8;

//glColor3f(0.2, 0.6, 0.1);
float rojoTriangulo = 0.2f;
float verdeTriangulo = 0.6f;
float azulTriangulo = 0.1f;

void teclado_callback(GLFWwindow* window,
	int key, int scancode, int action, int mods) {

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT) 
		&& key == GLFW_KEY_RIGHT) {
		posXTriangulo += 0.01;
	}

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT)
		&& key == GLFW_KEY_LEFT) {
		posXTriangulo -= 0.01;
	}

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT)
		&& key == GLFW_KEY_UP) {
		posYTriangulo += 0.01;
	}

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT)
		&& key == GLFW_KEY_DOWN) {
		posYTriangulo -= 0.01;
	}



}

void checarColisiones() {

	if (
		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.15f >= posXCuadrado - 0.15f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.15f <= posXCuadrado + 0.15f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.15f >= posYCuadrado - 0.15f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.15f <= posYCuadrado + 0.15f
		) {
		rojoTriangulo = 0.0f;
		verdeTriangulo = 0.0f;
		azulTriangulo = 0.0f;
		//exit(1);
	}
	else {
		rojoTriangulo = 0.2f;
		verdeTriangulo = 0.6f;
		azulTriangulo = 0.1f;
	}
}

void actualizar() {
	tiempoActual = glfwGetTime();

	checarColisiones();

	double tiempoDiferencial = 
		tiempoActual - tiempoAnterior;
	int estadoDerecha =
		glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		posXTriangulo += velocidadTriangulo * tiempoDiferencial;
	}
	int estadoArriba =
		glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		posYTriangulo += velocidadTriangulo * tiempoDiferencial;
	}
	int estadoIzquierda =
		glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		posXTriangulo -= velocidadTriangulo * tiempoDiferencial;
	}
	int estadoAbajo =
		glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		posYTriangulo -= velocidadTriangulo * tiempoDiferencial;
	}

	tiempoAnterior = tiempoActual;
}

void dibujarTriangulo() {
	glPushMatrix();

	glTranslatef(posXTriangulo, posYTriangulo, 0.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(rojoTriangulo, verdeTriangulo, azulTriangulo);
	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
}


void dibujarFigura1(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.3f, 0.5f, 0.9f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura2(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.3f, 0.5f, 0.9f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura3(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.3f, 0.5f, 0.9f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura4(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.3f, 0.5f, 0.9f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura5(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.3f, 0.5f, 0.9f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura6(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.4f, 0.7f, 0.2f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura7(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.4f, 0.7f, 0.2f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura8(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.4f, 0.7f, 0.2f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura9(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.4f, 0.7f, 0.2f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura10(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.2f, 0.5f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura11(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.2f, 0.5f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura12(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.2f, 0.5f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura13(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.2f, 0.5f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura14(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.2f, 0.5f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura15(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura16(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura17(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura18(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura19(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(0.4f, 0.7f, 0.2f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujarFigura20(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(x + cx, y + cy, 1.0f);

	}
	glEnd();
}

void dibujar() {

	
	dibujarFigura1(0.1, 0.1, 0.05, 3);
	dibujarFigura2(0.2, 0.2, 0.05, 4);
	dibujarFigura3(0.3, 0.3, 0.05, 5);
	dibujarFigura4(0.4, 0.4, 0.05, 6);
	dibujarFigura5(0.5, 0.5, 0.05, 7);
	dibujarFigura6(0.6, 0.6, 0.05, 8);
	dibujarFigura7(0.7, 0.7, 0.05, 9);
	dibujarFigura8(0.8, 0.8, 0.05, 10);
	dibujarFigura9(0.9, 0.9, 0.05, 100);

	dibujarFigura10(-0.1, -0.1, 0.05, 3);
	dibujarFigura11(-0.2, -0.2, 0.05, 4);
	dibujarFigura12(-0.3, -0.3, 0.05, 5);
	dibujarFigura13(-0.4, -0.4, 0.05, 6);
	dibujarFigura14(-0.5, -0.5, 0.05, 7);
	dibujarFigura15(-0.6, -0.6, 0.05, 8);
	dibujarFigura16(-0.7, -0.7, 0.05, 9);
	dibujarFigura17(-0.8, -0.8, 0.05, 10);
	dibujarFigura18(-0.9, -0.9, 0.05, 100);

	dibujarFigura19(0.1, -0.1, 0.05, 11);
	dibujarFigura20(-0.1, 0.1, 0.05, 11);


	//dibujarTriangulo();
}

int main()
{
    

	//Si no se pudo iniciar GLFW
	//Terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//inicializamos la ventana
	window =
		glfwCreateWindow(600, 600, "Ventana",
			NULL, NULL);
	//Si no se pudo crear la venata
	//Terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//Establecemos que con cada evento de teclado
	//se llama a la función teclado_callback
	//glfwSetKeyCallback(window, teclado_callback);

	tiempoActual = glfwGetTime();
	tiempoAnterior = tiempoActual;
	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.0f, 0.0f, 0.0f, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | 
			GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		actualizar();
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despúes del ciclo de dibujo
	//Eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
