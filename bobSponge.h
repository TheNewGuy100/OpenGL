
#ifndef BOBSPONGE_H
#define BOBSPONGE_H

#include <freeglut.h>
#include <glut.h>

//	------------------------------------------- LEG SCRIPT -------------------------------------------
	
void drawCylinder(float radius, float height, int sides, float offsetX, float offsetY, float offsetZ) {
	glPushMatrix();
		glColor3f(0.42, 0.18, 0.08);
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 6.25);
		
    	float angleStep = 2.0 * 3.14 / sides;
    
	    glBegin(GL_TRIANGLE_STRIP);
	    
	    for (int i = 0; i <= sides; ++i) {
	    	
	        float angle = i * angleStep;
	        float x = radius * cos(angle);
	        float y = radius * sin(angle);
	        
	        glVertex3f(x, y, height / 2.0);
	        glVertex3f(x, y, -height / 2.0);
	    }
	    
	    glEnd();
	glPopMatrix();
}

void drawCircle(float radius, int sides, float offsetX, float offsetY, float offsetZ, float rotateX, float rotateY, float rotateZ, float colorR, float colorG, float colorB) {
    float angleStep = 2.0 * M_PI / sides;
    
    glPushMatrix();
		glColor3f(colorR, colorG, colorB);
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 0);
	    glRotatef(90.0f, rotateX, rotateY, rotateZ);
	    
	    glBegin(GL_TRIANGLE_FAN);
	    
		    glVertex2f(0.0, 0.0); // Center vertex
		    
		    for (int i = 0; i <= sides; ++i)
		    {
		        float angle = i * angleStep;
		        float x = radius * cos(angle);
		        float y = radius * sin(angle);
		        
		        glVertex2f(x, y);
		    }
	    
	    glEnd();
	glPopMatrix();
}
	
	
void BobSpongeLegScript(float offsetX, float offsetY, float offsetZ) {
	// LEG L
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 7.75);
		glColor3f(1, 0.95, 0.08);
		glScalef(1.0f, 1.0f, 3.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK L PART 1
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 3);
		glColor3f(1, 1, 1);
		glScalef(1.0f, 1.0f, 8.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK MARK RED L
	glPushMatrix ();

		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 5.25);
		glColor3f(0.89f, 0.21f, 0.12f);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK L PART 2
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 5.75);
		glColor3f(1, 1, 1);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	
	// SOCK MARK BLUE L
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 6.25);
		glColor3f(0.05f, 0.30f, 0.60f);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// SOCK L PART 3
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + 0, offsetZ + 6.75);
		glColor3f(1, 1, 1);
		glScalef(1.0f, 1.0f, 1.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	// BOOT L
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 0.5);
		glColor3f(0, 0, 0);
		glScalef(2.0f, 6.0f, 2.0f);
		glutSolidCube(0.5f);
		
	glPopMatrix ();
	
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -2, offsetZ + 0.5);
		glColor3f(0, 0, 0);
		glScalef(0.7, 1.3, 0.9);
		glutSolidSphere(1, 12, 7);
		
	glPopMatrix ();
	
	// LEG PANTS
	drawCylinder(1.0, 1.0, 12, offsetX, 0, 2);
	
}

// ----------------------------------- DRAW BODY ---------------------------------------------------
void DrawSpongeBobBody(float offsetX, float offsetY, float offsetZ) {
	
	//	PANTS
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 0.5);
		glColor3f(0.47, 0.23, 0.08);
		glScalef(2, 1.6f, 0.8f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	//	SHIRT
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 2.3);
		glColor3f(1, 1, 1);
		glScalef(2, 1.6f, 0.4f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	//	BODY
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 6.6);
		glColor3f(1, 0.95, 0.08);
		glScalef(2.1f, 1.7f, 2.5f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	glPushMatrix ();
	
		glTranslatef (offsetX + 0, offsetY + -0.5, offsetZ + 6.6);
		glColor3f(1, 0.95, 0.08);
		glScalef(2.1f, 1.7f, 2.5f);
		glutSolidCube(3.0f);
		
	glPopMatrix ();
	
	// PANTS MARKS
		glPushMatrix ();
			glTranslatef (offsetX + -2, offsetY + -3, offsetZ + 3.7);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(1, 1, 1.5);
			glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex3f(-1.0, 0, 0.0);
				glVertex3f(-1.0, 0, 1.0);
				glVertex3f(-3.0, 0, 0.0);
				glVertex3f(-3.0, 0, 1.0);
			glEnd();
			
		glPopMatrix ();
		
		glPushMatrix ();
			glTranslatef (offsetX + -1.85, offsetY + -3.001, offsetZ + 3.65);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glScalef(0.93, 0.8, 1.3);
			glColor3f(1, 1, 1);
			
			glBegin(GL_QUADS);
				glVertex3f(-1.0, 0, 0.0);
				glVertex3f(-1.0, 0, 1.0);
				glVertex3f(-3.0, 0, 0.0);
				glVertex3f(-3.0, 0, 1.0);
			glEnd();
			
		glPopMatrix ();
		
	// STRIPS FRONT / BACK
	glPushMatrix ();
			glTranslatef (offsetX + -3.55, offsetY + -3, offsetZ + 0.7);
			glScalef(0.65, 1, 0.7);
			glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(3.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 1.0);
				glVertex3f(3.5, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(6, 0.0, 0.0);
				glVertex3f(8, 0.0, 0.0);
				glVertex3f(8, 0.0, 1.0);
				glVertex3f(6, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(8.5, 0.0, 0.0);
				glVertex3f(10, 0.0, 0.0);
				glVertex3f(10, 0.0, 1.0);
				glVertex3f(8.5, 0.0, 1.0);
			glEnd();
	glPopMatrix ();
	
	glPushMatrix ();
			glTranslatef (offsetX + -3.55, offsetY + 2, offsetZ + 0.7);
			glScalef(0.65, 1, 0.7);
			glColor3f(0, 0, 0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(3.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 0.0);
				glVertex3f(5.5, 0.0, 1.0);
				glVertex3f(3.5, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(6, 0.0, 0.0);
				glVertex3f(8, 0.0, 0.0);
				glVertex3f(8, 0.0, 1.0);
				glVertex3f(6, 0.0, 1.0);
			glEnd();
			
			glBegin(GL_QUADS);
				glVertex3f(8.5, 0.0, 0.0);
				glVertex3f(10, 0.0, 0.0);
				glVertex3f(10, 0.0, 1.0);
				glVertex3f(8.5, 0.0, 1.0);
			glEnd();
	glPopMatrix ();
	
	// STRIP SIDES LEFT
	glPushMatrix ();
		glTranslatef (offsetX + -3.1, offsetY + -4, offsetZ + 0.7);
		glRotatef(90, 0.0, 0.0, 1.0);
		glScalef(0.65, 1, 0.7);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(3.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 1.0);
			glVertex3f(3.5, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(6, 0.0, 0.0);
			glVertex3f(8, 0.0, 0.0);
			glVertex3f(8, 0.0, 1.0);
			glVertex3f(6, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(8.5, 0.0, 0.0);
			glVertex3f(9, 0.0, 0.0);
			glVertex3f(9, 0.0, 1.0);
			glVertex3f(8.5, 0.0, 1.0);
		glEnd();
	glPopMatrix ();
	
	// STRIP SIDES RIGHT
	glPushMatrix ();
		glTranslatef (offsetX + 3.1, offsetY + -4, offsetZ + 0.7);
		glRotatef(90, 0.0, 0.0, 1.0);
		glScalef(0.65, 1, 0.7);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(3.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 0.0);
			glVertex3f(5.5, 0.0, 1.0);
			glVertex3f(3.5, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(6, 0.0, 0.0);
			glVertex3f(8, 0.0, 0.0);
			glVertex3f(8, 0.0, 1.0);
			glVertex3f(6, 0.0, 1.0);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(8.5, 0.0, 0.0);
			glVertex3f(9, 0.0, 0.0);
			glVertex3f(9, 0.0, 1.0);
			glVertex3f(8.5, 0.0, 1.0);
		glEnd();
	glPopMatrix ();
	
	glPushMatrix ();
		glTranslatef (offsetX + -0.5, offsetY + -3.1, offsetZ + 3.45);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(0.6, 1, 1);
		glColor3f(1, 0, 0);
	
		glBegin(GL_QUADS);
			glVertex3f(1, 0.0, 0);
			glVertex3f(3, 0.0, 0.2);
			glVertex3f(3, 0.0, 0.7);
			glVertex3f(1, 0.0, 1);
		glEnd();
	glPopMatrix ();
	
		glPushMatrix ();
		glTranslatef (offsetX + -0.35, offsetY + -3.1, offsetZ + 2.65);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1, 1, 0.6);
		glColor3f(1, 0, 0);
	
		glBegin(GL_QUADS);
			glVertex3f(1, 0.0, 0);
			glVertex3f(3, 0.0, 0);
			glVertex3f(3, 0.0, 1);
			glVertex3f(1, 0.0, 1);
		glEnd();
	glPopMatrix ();
}


// ----------------------------------- DRAW EYE SCRIPT -----------------------------------------------

void DrawSpongeBobEyeLashes(float offsetX, float offsetY, float offsetZ) {
		glPushMatrix ();
			glTranslatef (offsetX + -2.4, offsetY + -2.6, offsetZ + 18.5);
			glColor3f(0, 0, 0);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(45, 0.0, 1.0, 0.0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
		
		glPopMatrix ();
		
		glPushMatrix ();
			glTranslatef (offsetX + -1.4, offsetY + -2.6, offsetZ + 19);
			glColor3f(0, 0, 0);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(90, 0.0, 1.0, 0.0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
		
		glPopMatrix ();
		
		
		glPushMatrix ();
			glTranslatef (offsetX + -0.9, offsetY + -2.6, offsetZ + 17.7);
			glColor3f(0, 0, 0);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(-45, 0.0, 1.0, 0.0);
			
			glBegin(GL_QUADS);
				glVertex3f(1.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 0.0);
				glVertex3f(3.0, 0.0, 1.0);
				glVertex3f(1.0, 0.0, 1.0);
			glEnd();
		
		glPopMatrix ();
}

void DrawMouth( float offsetX, float offsetY, float offsetZ ) {
	
	// BELZIER CURVE FOR MOUTH
	glPushMatrix ();
		glTranslatef (offsetX + 0, offsetY + -2.63, offsetZ + 14.5);
		glColor3f(0, 0, 0);
		glScalef(3.5, 3.5, 2.5);
		glRotatef(-90, 1, 0, 0);
	
	    glBegin(GL_LINE_STRIP);
	    glVertex2f(-0.5f, 0.0f); // Starting point
	    
	    // Control point
	    float controlPointX = 0.0f;
	    float controlPointY = 0.5f;
	    
	    // Ending point
	    float endPointX = 0.5f;
	    float endPointY = 0.0f;
	    
	    for (int i = 1; i <= 20; ++i)
	    {
	        float t = static_cast<float>(i) / 20.0f;
	        float oneMinusT = 1.0f - t;
	        
	        float x = oneMinusT * oneMinusT * -0.5f + 2.0f * oneMinusT * t * controlPointX + t * t * endPointX;
	        float y = oneMinusT * oneMinusT * 0.0f + 2.0f * oneMinusT * t * controlPointY + t * t * endPointY;
	        
	        glVertex2f(x, y);
	    }
	    
	    glEnd();
    glPopMatrix ();
    
    // TEETH L 
    glPushMatrix ();
		glTranslatef (offsetX + -2, offsetY + -2.6, offsetZ + 12.9);
		glScalef(0.65, 1, 1);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
    
    glPushMatrix ();
		glTranslatef (offsetX + -1.75, offsetY + -2.61, offsetZ + 13);
		glScalef(0.55, 1, 0.90);
		glColor3f(1, 1, 1);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
    
    // TEETH R
    glPushMatrix ();
		glTranslatef (offsetX + -1.3, offsetY + -2.6, offsetZ + 12.9);
		glScalef(0.65, 1, 1);
		glColor3f(0, 0, 0);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
    
    glPushMatrix ();
		glTranslatef (offsetX + -1.05, offsetY + -2.61, offsetZ + 13);
		glScalef(0.55, 1, 0.90);
		glColor3f(1, 1, 1);
		
		glBegin(GL_QUADS);
			glVertex3f(2.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 1.0);
			glVertex3f(2.0, 0.0, 1.0);
		glEnd();
    glPopMatrix ();
}

void DrawSpongeBobEye(float offsetX, float offsetY, float offsetZ) {
	// EYES
		// EYE LINE
		drawCircle(1.25, 18, -1.22, -2.6, 17, 1.0f, 0 , 0, 0, 0, 0);
		drawCircle(1.25, 18, 1.22, -2.6, 17, 1.0f, 0 , 0, 0, 0, 0);
		
		// EYE INNER
		drawCircle(1.15, 18, -1.22, -2.61, 17, 1.0f, 0 , 0, 1, 1, 1);
		drawCircle(1.15, 18, 1.22, -2.61, 17, 1.0f, 0 , 0, 1, 1, 1);
		
		// EYE BORDER
		drawCircle(0.65, 18, -1.22, -2.62, 17, 1.0f, 0 , 0, 0, 0, 0);
		drawCircle(0.65, 18, 1.22, -2.62, 17, 1.0f, 0 , 0, 0, 0, 0);
		
		// EYE IRIS
		drawCircle(0.60, 18, -1.22, -2.63, 17, 1.0f, 0 , 0, 0.40, 0.74, 0.88);
		drawCircle(0.60, 18, 1.22, -2.63, 17, 1.0f, 0 , 0, 0.40, 0.74, 0.88);
		
		// EYE INNER
		drawCircle(0.35, 18, -1.22, -2.64, 17, 1.0f, 0 , 0, 0, 0, 0);
		drawCircle(0.35, 18, 1.22, -2.64, 17, 1.0f, 0 , 0, 0, 0, 0);
		
		DrawSpongeBobEyeLashes( 0, 0, 0);
		DrawSpongeBobEyeLashes( 2.5, 0, 0);
}

// ----------------------------------- ARM SCRIPT -----------------------------------------------------
//
// O braco e montado como uma cadeia articulada: ombro -> braco -> cotovelo -> antebraco -> pulso -> mao com dedos.
// Cada junta gira em relacao a anterior, entao o movimento sai natural (sem esticar o cubo, como antes).

#define ARM_SEGMENT_LENGTH 2.75f			// comprimento do braco e do antebraco (juntos 5.5, como o braco original)
#define ARM_SHOULDER_Z 11.5f				// altura do ombro: no meio da parte branca da camisa (z 10.9 a 12.1)
#define ARM_SHOULDER_X 3.25f				// o ombro encosta na lateral do corpo (largura da camisa = +-3.0 + meia espessura do braco)
#define ARM_ANIM_PERIOD_MS 2400.0f			// duracao de um ciclo completo (sobe e desce)

// angulos atuais da animacao, atualizados a cada quadro por AnimateSpongeBobArm()
float armSwingAngle = 0;					// giro do ombro para fora (0 = braco pendurado ao lado do corpo, 90 = na horizontal, 135 = levantado)
float armBendAngle = 0;						// dobra do cotovelo
float armWristAngle = 0;					// balanco do pulso
float armFingerSpread = 0;					// abertura dos dedos

void DrawArmSegment(float length, float thickness) {
	glPushMatrix ();
		glTranslatef (0, 0, length / 2.0f);
		glScalef(thickness, thickness, length);
		glutSolidCube(1.0f);
	glPopMatrix ();
}

void DrawArmFinger(float spreadAngle, float length) {
	glPushMatrix ();
		glRotatef(spreadAngle, 0, 1, 0);
		glTranslatef (0, 0, 0.75f);
		glPushMatrix ();
			glScalef(0.22f, 0.22f, length);
			glTranslatef (0, 0, 0.5f);
			glutSolidCube(1.0f);
		glPopMatrix ();
		glTranslatef (0, 0, length + 0.05f);
		glutSolidSphere(0.16, 8, 6);
	glPopMatrix ();
}

// side = -1 para o braco esquerdo (x negativo) e +1 para o direito. Os angulos giram para fora do corpo.
// O braco e modelado apontando para cima (+Z); o giro de 180 graus abaixo o deixa pendurado em repouso.
void DrawSpongeBobArmPose(float shoulderX, float side, float swing, float bend, float wrist, float spread) {
	glPushMatrix ();
		glTranslatef (shoulderX, 0, ARM_SHOULDER_Z);
		glRotatef(180.0f - side * swing, 0, 1, 0);

		// braco (amarelo)
		glColor3f(1, 0.95, 0.08);
		DrawArmSegment(ARM_SEGMENT_LENGTH, 0.5f);

		// cotovelo
		glTranslatef (0, 0, ARM_SEGMENT_LENGTH);
		glutSolidSphere(0.3, 10, 7);
		glRotatef(-side * bend, 0, 1, 0);

		// antebraco
		DrawArmSegment(ARM_SEGMENT_LENGTH, 0.45f);

		// pulso e mao (branca)
		glTranslatef (0, 0, ARM_SEGMENT_LENGTH);
		glRotatef(-side * wrist, 0, 1, 0);
		glColor3f(1, 1, 1);

		glPushMatrix ();
			glTranslatef (0, 0, 0.35f);
			glScalef(1.0f, 0.7f, 1.0f);
			glutSolidSphere(0.65, 12, 8);
		glPopMatrix ();

		// tres dedos que se abrem + polegar
		DrawArmFinger(-spread, 0.55f);
		DrawArmFinger(0, 0.65f);
		DrawArmFinger(spread, 0.55f);

		glPushMatrix ();
			glTranslatef (side * 0.55f, 0, 0.35f);
			glRotatef(side * (35 + spread), 0, 1, 0);
			glScalef(0.2f, 0.2f, 0.5f);
			glTranslatef (0, 0, 0.5f);
			glutSolidCube(1.0f);
		glPopMatrix ();
	glPopMatrix ();
}

// Braco animado: balanca para baixo e volta, dobrando o cotovelo e abrindo os dedos.
void DrawSpongeBobArm(float offsetX, float offsetY, float offsetZ) {
	DrawSpongeBobArmPose(offsetX, -1, armSwingAngle, armBendAngle, armWristAngle, armFingerSpread);
}

// Braco parado: mesma montagem, em pose fixa (levantado, dedos levemente abertos).
void DrawSpongeBobArmNoAnimation(float offsetX, float offsetY, float offsetZ) {
	DrawSpongeBobArmPose(offsetX, 1, 0, 0, 0, 12);
}

// ----------------------------------- ARM ANIMATION ------------------------------------------------

// A pose vem do tempo decorrido (e nao de um contador por quadro), entao a velocidade e a mesma em qualquer taxa de quadros.
void AnimateSpongeBobArm() {
	float t = glutGet(GLUT_ELAPSED_TIME);
	float phase = 0.5f - 0.5f * cosf(2.0f * 3.14159265f * t / ARM_ANIM_PERIOD_MS);	// 0 -> 1 -> 0, suave nas pontas

	armSwingAngle = 135.0f * phase;
	armBendAngle = 40.0f * phase * phase;
	armWristAngle = 14.0f * phase * sinf(2.0f * 3.14159265f * t / 600.0f);
	armFingerSpread = 12.0f + 14.0f * phase;
}


// ----------------------------------- BUILD SPONGE BOB SCRIPT ---------------------------------------

void BobEsponjaScriptDraw(float offsetX, float offsetY, float offsetZ) {
	
	glPushMatrix ();
		glTranslatef (offsetX, offsetY, offsetZ + 0.1);
		// DRAW FLOOR
		glBegin(GL_QUADS);
			glColor3f(0.31f, 0.40f, 0.37f);
			glVertex3f(12.0, -12.0, 0.0);
			glVertex3f(-12.0, -12.0, 0.0);
			glVertex3f(-12.0, 12.0, 0.0);
			glVertex3f(12.0, 12.0, 0.0);
		glEnd();
	glPopMatrix ();
	
	BobSpongeLegScript( -1.5, 0, 0);
	BobSpongeLegScript( 1.5, 0, 0);
	DrawSpongeBobBody( 0, 0.5, 9.2);
	DrawSpongeBobArm( -ARM_SHOULDER_X, 0, 0);
	DrawSpongeBobArmNoAnimation(ARM_SHOULDER_X, 0, 0);
	DrawSpongeBobEye(offsetX, offsetY, offsetZ);
	
	DrawMouth(0,0,0);
}













#endif



