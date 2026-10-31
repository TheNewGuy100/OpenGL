
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdlib.h>
#include <math.h>
#include "./hud.h"

extern float g_janela;

extern GLbyte g_obs_operacao;

// A camera orbita ao redor de um PIVO (ponto do mundo). Mover a camera desloca o pivo; girar e dar zoom sempre
// acontecem em torno dele.
//   viewport_camera_new_z          = distancia da camera ao pivo (negativa)
//   viewport_camera_new_rotation_x = inclinacao (pitch), 180 = vista de cima | 270 = vista na horizontal
//   viewport_camera_new_rotation_y = giro (yaw) ao redor do eixo Z do mundo
extern float viewport_camera_new_x,
			 viewport_camera_new_y,
			 viewport_camera_new_z;

extern float viewport_camera_new_rotation_x,
			 viewport_camera_new_rotation_y;

extern GLint g_mouse_x,
			 g_mouse_y;

// ---------------------------------------- CAMERA: LIMITES E SENSIBILIDADE --------------------------------------- //

static const float CAMERA_PITCH_MIN = 180.0f;
static const float CAMERA_PITCH_MAX = 270.0f;
static const float CAMERA_ZOOM_NEAR = -4.0f;			// mais perto que isso atravessa o personagem
static const float CAMERA_ZOOM_FAR = -90.0f;			// o plano de recorte distante e 10 * g_janela (100)
static const float CAMERA_ORBIT_SENSITIVITY = 0.4f;		// graus por pixel arrastado
static const float CAMERA_ARROW_STEP = 3.0f;			// graus por toque nas setas

static const float CAMERA_PIVOT_LIMIT = 200.0f;			// o pivo nao se afasta mais que isso da origem

static int g_drag_button = -1;							// botao do mouse sendo arrastado (-1 = nenhum)

static float g_pivot_x = 0, g_pivot_y = 0, g_pivot_z = 0;	// pivo da camera, em coordenadas do mundo

// -------------------------------------------- FREEGLUT VIEWPORT CAMERA -------------------------------------------- //

void PositionViewportDisplay (void) {
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glTranslatef ( 0, 0, viewport_camera_new_z );
	glRotatef ( viewport_camera_new_rotation_x, 1, 0, 0 );
	glRotatef ( 180, 0, 1, 0 );										// a projecao (campo de visao 999) inverte a imagem; isto a mantem em pe
	glRotatef ( viewport_camera_new_rotation_y, 0, 0, 1 );
	glTranslatef ( -g_pivot_x, -g_pivot_y, -g_pivot_z );			// leva o pivo para o centro da tela
}

void UpdateCamera (void) {
	PositionViewportDisplay();
	glutPostRedisplay ();
}

void ResetCamera (void) {
	viewport_camera_new_x = 0;
	viewport_camera_new_y = 0;
	viewport_camera_new_z = -g_janela * 3.5;
	g_pivot_x = 0;
	g_pivot_y = 0;
	g_pivot_z = 0;
	viewport_camera_new_rotation_x = 246;
	viewport_camera_new_rotation_y = 0;
}

void InitializeViewportDisplay (void) {
	ResetCamera();
	PositionViewportDisplay();
}

static float ClampFloat (float value, float low, float high) {
	if (value < low) return low;
	if (value > high) return high;
	return value;
}

// Gira a cena ao redor do personagem. deltaYaw > 0 gira para a direita; deltaPitch > 0 desce o ponto de vista.
void OrbitCamera (float deltaYaw, float deltaPitch) {
	viewport_camera_new_rotation_y = fmodf(viewport_camera_new_rotation_y + deltaYaw, 360.0f);
	viewport_camera_new_rotation_x = ClampFloat(viewport_camera_new_rotation_x - deltaPitch, CAMERA_PITCH_MIN, CAMERA_PITCH_MAX);
}

// Rotaciona o vetor (x, y, z) em graus ao redor de cada eixo (mesma convencao do glRotatef).
static void RotateAroundX (float angle, float &y, float &z) {
	float c = cosf(angle * 3.14159265f / 180.0f), s = sinf(angle * 3.14159265f / 180.0f);
	float ny = y * c - z * s, nz = y * s + z * c;
	y = ny; z = nz;
}

static void RotateAroundY (float angle, float &x, float &z) {
	float c = cosf(angle * 3.14159265f / 180.0f), s = sinf(angle * 3.14159265f / 180.0f);
	float nx = x * c + z * s, nz = -x * s + z * c;
	x = nx; z = nz;
}

static void RotateAroundZ (float angle, float &x, float &y) {
	float c = cosf(angle * 3.14159265f / 180.0f), s = sinf(angle * 3.14159265f / 180.0f);
	float nx = x * c - y * s, ny = x * s + y * c;
	x = nx; y = ny;
}

// Desloca o PIVO. (viewX, viewY) e quanto a cena deve andar no plano da tela; convertemos para o mundo desfazendo
// a rotacao da camera, entao o pivo anda na direcao que o usuario ve e a camera passa a girar em torno do novo ponto.
void MovePivot (float viewX, float viewY) {
	float x = viewX, y = viewY, z = 0;

	// inverso de R = Rx(pitch) * Ry(180) * Rz(yaw): aplica Rx(-pitch), Ry(-180) e Rz(-yaw), nessa ordem
	RotateAroundX(-viewport_camera_new_rotation_x, y, z);
	RotateAroundY(-180.0f, x, z);
	RotateAroundZ(-viewport_camera_new_rotation_y, x, y);

	g_pivot_x = ClampFloat(g_pivot_x - x, -CAMERA_PIVOT_LIMIT, CAMERA_PIVOT_LIMIT);
	g_pivot_y = ClampFloat(g_pivot_y - y, -CAMERA_PIVOT_LIMIT, CAMERA_PIVOT_LIMIT);
	g_pivot_z = ClampFloat(g_pivot_z - z, -CAMERA_PIVOT_LIMIT, CAMERA_PIVOT_LIMIT);
}

// Move a camera no plano da tela. A distancia define quanto vale um pixel no mundo.
void PanCamera (float deltaX, float deltaY) {
	int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
	if (windowHeight < 1) windowHeight = 1;
	float worldPerPixel = (2.0f * 0.854f * fabsf(viewport_camera_new_z)) / windowHeight;
	MovePivot(-deltaX * worldPerPixel, deltaY * worldPerPixel);
}

// direction > 0 aproxima, direction < 0 afasta
void ZoomCamera (int direction) {
	float step = 0.1f * fabsf(viewport_camera_new_z);
	if (step < 0.5f) step = 0.5f;
	viewport_camera_new_z = ClampFloat(viewport_camera_new_z + direction * step, CAMERA_ZOOM_FAR, CAMERA_ZOOM_NEAR);
}

// ---------------------------------------- FREEGLUT KEYBOARD CONTROLLER ------------------------------------------ //

void KeyboardController (unsigned char key, int x, int y) {
	float step = 0.05f * fabsf(viewport_camera_new_z);

	switch (key) {
		case 'w':
		case 'W':
			ZoomCamera(1);
			break;
		case 's':
		case 'S':
			ZoomCamera(-1);
			break;
		case 'a':
		case 'A':
			MovePivot(-step, 0);
			break;
		case 'd':
		case 'D':
			MovePivot(step, 0);
			break;
		case 'q':
		case 'Q':
			MovePivot(0, -step);
			break;
		case 'e':
		case 'E':
			MovePivot(0, step);
			break;
		case 'r':
		case 'R':
			ResetCamera();
			break;
		case 'h':
		case 'H':
			ToggleControlsHUD();
			break;
		case 27:
			exit(0);
			break;
	}

	UpdateCamera();
}

void gEspeciais (int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_LEFT:
			OrbitCamera(-CAMERA_ARROW_STEP, 0);
			break;
		case GLUT_KEY_RIGHT:
			OrbitCamera(CAMERA_ARROW_STEP, 0);
			break;
		case GLUT_KEY_UP:
			OrbitCamera(0, -CAMERA_ARROW_STEP);
			break;
		case GLUT_KEY_DOWN:
			OrbitCamera(0, CAMERA_ARROW_STEP);
			break;
	}

	UpdateCamera();
}

// --------------------------------------------- FREEGLUT MOUSE CONTROLLER ------------------------------------------ //

void MouseInputController (int botao, int estado, int x, int y) {
	if (estado == GLUT_DOWN) {
		g_drag_button = botao;
		g_mouse_x = x;
		g_mouse_y = y;
	} else if (botao == g_drag_button) {
		g_drag_button = -1;
	}
}

void MouseMovementController (int x, int y) {
	int deltaX = x - g_mouse_x;
	int deltaY = y - g_mouse_y;
	g_mouse_x = x;
	g_mouse_y = y;

	if (g_drag_button == GLUT_LEFT_BUTTON) {
		OrbitCamera(deltaX * CAMERA_ORBIT_SENSITIVITY, deltaY * CAMERA_ORBIT_SENSITIVITY);
	} else if (g_drag_button == GLUT_RIGHT_BUTTON || g_drag_button == GLUT_MIDDLE_BUTTON) {
		PanCamera((float) deltaX, (float) deltaY);
	}

	UpdateCamera();
}

void MouseScrollController (int botao, int direcao, int x, int y) {
	ZoomCamera(direcao > 0 ? 1 : -1);
	UpdateCamera();
}

#endif
