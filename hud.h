
#ifndef HUD_H
#define HUD_H

#include <string.h>

// ---------------------------------------- PAINEL DE CONTROLES (HUD 2D) ------------------------------------------ //

static bool g_hud_visible = true;

struct HudRow {
	const char *key;
	const char *action;
};

// Textos em ASCII; acentos usam escapes Latin-1 (\xe2 = a com circunflexo) para nao depender da codificacao do arquivo.
static const HudRow g_hud_rows[] = {
	{ "Mouse esquerdo + arrastar", "orbitar" },
	{ "Mouse direito + arrastar", "mover" },
	{ "Scroll ou W / S", "zoom" },
	{ "Setas", "orbitar" },
	{ "A / D / Q / E", "mover" },
	{ "R", "resetar c\xe2mera" },
	{ "H", "ocultar controles" },
	{ "ESC", "sair" }
};

static const int g_hud_row_count = sizeof(g_hud_rows) / sizeof(g_hud_rows[0]);

static void HudText(float x, float y, const char *text, void *font) {
	glRasterPos2f(x, y);
	for (const char *c = text; *c; ++c) {
		glutBitmapCharacter(font, (unsigned char) *c);
	}
}

void ToggleControlsHUD() {
	g_hud_visible = !g_hud_visible;
	glutPostRedisplay();
}

void DrawControlsHUD() {
	void *font = GLUT_BITMAP_9_BY_15;
	const int charW = 9, rowH = 20, pad = 12, margin = 10;

	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	int keyChars = 0, actionChars = 0;
	for (int i = 0; i < g_hud_row_count; ++i) {
		int k = (int) strlen(g_hud_rows[i].key);
		int a = (int) strlen(g_hud_rows[i].action);
		if (k > keyChars) keyChars = k;
		if (a > actionChars) actionChars = a;
	}
	int keyColumn = (keyChars + 3) * charW;
	int panelW = pad * 2 + keyColumn + actionChars * charW;
	int panelH = pad * 2 + rowH * (g_hud_row_count + 1);

	// salva o estado de projecao e de modelo: o HUD usa coordenadas de tela
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	GLboolean depthWasOn = glIsEnabled(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float top = (float) (h - margin);

	if (g_hud_visible) {
		float left = (float) margin;
		float right = left + panelW;
		float bottom = top - panelH;

		glColor4f(0.0f, 0.0f, 0.0f, 0.65f);
		glBegin(GL_QUADS);
			glVertex2f(left, bottom);
			glVertex2f(right, bottom);
			glVertex2f(right, top);
			glVertex2f(left, top);
		glEnd();

		glColor4f(0.21f, 0.95f, 0.63f, 1.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2f(left, bottom);
			glVertex2f(right, bottom);
			glVertex2f(right, top);
			glVertex2f(left, top);
		glEnd();

		float baseY = top - pad - 12;
		HudText(left + pad, baseY, "CONTROLES", font);

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		for (int i = 0; i < g_hud_row_count; ++i) {
			float y = baseY - rowH * (i + 1);
			HudText(left + pad, y, g_hud_rows[i].key, font);
			HudText(left + pad + keyColumn, y, g_hud_rows[i].action, font);
		}
	} else {
		glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
		HudText((float) margin, top - 12, "H: controles", font);
	}

	glDisable(GL_BLEND);
	if (depthWasOn) glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

#endif
