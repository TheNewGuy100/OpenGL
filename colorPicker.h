
#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <stdlib.h>

#define SHAPE_COUNT 8
#define COLOR_CHANGE_INTERVAL_MS 1000					// as formas de fundo trocam de cor a cada 1 segundo

GLfloat shapeColors[SHAPE_COUNT][3];					// cor (r, g, b) de cada forma
int lastColorChange = -COLOR_CHANGE_INTERVAL_MS;		// forca o primeiro sorteio no primeiro quadro

void RandomizeShapeColors() {
	for (int i = 0; i < SHAPE_COUNT; ++i) {
		for (int c = 0; c < 3; ++c) {
			shapeColors[i][c] = static_cast<GLfloat>(rand()) / RAND_MAX;	// valor entre 0.0 e 1.0
		}
	}
}

// Chamado a cada quadro: so sorteia novas cores quando o intervalo passou.
void UpdateShapeColors() {
	int now = glutGet(GLUT_ELAPSED_TIME);
	if (now - lastColorChange >= COLOR_CHANGE_INTERVAL_MS) {
		RandomizeShapeColors();
		lastColorChange = now;
	}
}

void SetShapeColor(int index) {
	glColor3f(shapeColors[index][0], shapeColors[index][1], shapeColors[index][2]);
}

#endif
