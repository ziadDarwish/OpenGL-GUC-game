
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <glut.h>
#include <math.h>
#include <string>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


using namespace std;


int passX = 0;
int passY = 0;

int actX = 0;
int actY = 0;

int keyX = 0;
int keyY = 500;
int keyC = 0;

int barX = 600;
float gravY = 0;

int ycount = 0;
int keyCount = 500;

int prevY = 0;
bool stop = false;
bool stop2 = false;
bool win = false;
bool pls = true;

bool pass = false;


bool used = false;

float angle = 0;


bool lose = false;

int ar[] = {1100,800,1400,500};

int ar2[] = {200,400,200,500};


bool sh = false;

bool powerUpTaken = false;


int powerUpPos;
int powerUpX;
int powerUpY;


int liveCount = 0;

int pixelsDown = 500;

int speX = 0;
int speY = 0;
int speC = 0;

double backRed = 0.8;
double backGreen = 0.4;
double backBlue = 0.5;


float r = 0.5;
float g = 0.2;
float b = 0.0;

int scoreCount = 0;

int redD = 1;
int greenD = 1;
int blueD = 1;



int b1y1 = 250;
int b1y2 = 450;


int b2y1 = 200;
int b2y2 = 400;


int b3y1 = 450;
int b3y2 = 650;



int b4y1 = 300;
int b4y2 = 500;


int b5y1 = 200;
int b5y2 = 500;



int b6y1 = 100;
int b6y2 = 300;

int b7y1=150;
int b7y2=350;

int b8y1 = 120;
int b8y2 = 320;
int barPos1;
int barPos2;
int barPos3;
int barPos4;
int randNum;

void barriers() {

	int y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15, y16;
	int bar1, bar2, bar3;


	if (randNum == 1) {
		barPos1 = 600; barPos2 = 1200; barPos3 = 1800; barPos4 = 2400;
		y1 = b1y1;	y2 = b1y2; y3 = b2y1; y4 = b2y2; y5 = b3y1; y6 = b3y2; y7 = b4y1; y8 = b4y2; y9 = b5y1;
		y10 = b5y2; y11 = b6y1; y12 = b6y2; y13 = b7y1; y14 = b7y2; y15 = b8y1; y16 = b8y2;
	}
	else if(randNum == 2){
		barPos1 = 1200; barPos2 = 600; barPos3 = 1800;  barPos4 = 2400;
		y1 = b3y1;	y2 = b3y2; y3 = b4y1; y4 = b4y2; y5 = b1y1; y6 = b1y2; y7 = b2y1; y8 = b2y2; y9 = b5y1;
		y10 = b5y2; y11 = b6y1; y12 = b6y2; y13 = b7y1; y14 = b7y2; y15 = b8y1; y16 = b8y2;
	}
	else if (randNum == 3) {
		barPos1 = 600; barPos2 = 1800; barPos3 = 1200;  barPos4 = 2400;
		y1 = b1y1;	y2 = b1y2; y3 = b2y1; y4 = b2y2; y5 = b5y1; y6 = b5y2; y7 = b6y1; y8 = b6y2; y9 = b3y1;
		y10 = b3y2; y11 = b4y1; y12 = b4y2; y13 = b7y1; y14 = b7y2; y15 = b8y1; y16 = b8y2;
	}
	else if (randNum == 4) {
		barPos1 = 1800; barPos2 = 1200; barPos3 = 600;  barPos4 = 2400;
		y1 = b5y1;	y2 = b5y2; y3 = b6y1; y4 = b6y2; y5 = b3y1; y6 = b3y2; y7 = b4y1; y8 = b4y2; y9 = b1y1;
		y10 = b1y2; y11 = b2y1; y12 = b2y2; y13 = b7y1; y14 = b7y2; y15 = b8y1; y16 = b8y2;
	}
	else if (randNum == 5) {
		barPos1 = 1200; barPos2 = 1800; barPos3 = 600;  barPos4 = 2400;
		y1 = b5y1;	y2 = b5y2; y3 = b6y1; y4 = b5y2; y5 = b1y1; y6 = b1y2; y7 = b2y1; y8 = b2y2; y9 = b3y1;
		y10 = b3y2; y11 = b4y1; y12 = b4y2; y13 = b7y1; y14 = b7y2; y15 = b8y1; y16 = b8y2;
	}
	else if (randNum == 6) {
		barPos1 = 1800; barPos2 = 600; barPos3 = 1200;  barPos4 = 2400;
		y1 = b3y1;	y2 = b3y2; y3 = b4y1; y4 = b4y2; y5 = b5y1; y6 = b5y2; y7 = b6y1; y8 = b6y2; y9 = b1y1;
		y10 = b1y2; y11 = b2y1; y12 = b2y2; y13 = b7y1; y14 = b7y2; y15 = b8y1; y16 = b8y2;
	}
	else if (randNum==7) {
		barPos1 = 2400; barPos2 = 1200; barPos3 = 1800; barPos4 = 600;
		y1 = b7y1;	y2 = b7y2; y3 = b8y1; y4 = b8y2; y5 = b3y1; y6 = b3y2; y7 = b4y1; y8 = b4y2; y9 = b5y1;
		y10 = b5y2; y11 = b6y1; y12 = b6y2; y13 = b1y1; y14 = b1y2; y15 = b2y1; y16 = b2y2;
	}
	else if (randNum == 8) {
		barPos1 = 1200; barPos2 = 2400; barPos3 = 1800;  barPos4 = 600;
		y1 = b7y1;	y2 = b7y2; y3 = b8y1; y4 = b8y2; y5 = b1y1; y6 = b1y2; y7 = b2y1; y8 = b2y2; y9 = b5y1;
		y10 = b5y2; y11 = b6y1; y12 = b6y2; y13 = b3y1; y14 = b3y2; y15 = b4y1; y16 = b4y2;
	}
	else if (randNum == 9) {
		barPos1 = 1200; barPos2 = 1800; barPos3 = 2400;  barPos4 = 600;
		y1 = b7y1;	y2 = b7y2; y3 = b8y1; y4 = b8y2; y5 = b1y1; y6 = b1y2; y7 = b2y1; y8 = b2y2; y9 = b3y1;
		y10 = b3y2; y11 = b4y1; y12 = b4y2; y13 = b5y1; y14 = b5y2; y15 = b6y1; y16 = b6y2;
	}
	

	if (!lose) {
		
		if (keyY >= 800 || keyY < 40) {
			lose = true;
		}
		else if (barX > -150 & keyY < 800 & keyY>40) {
			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
	
		}
		else if (barX <= -150 & barX >= -250 & y1 < keyY & keyY < y2) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			scoreCount = scoreCount + 10;

		}
		else if (barX <= -250 & barX > -450 & keyY < 800 & keyY>40) {
			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			if (powerUpX == 800 & powerUpY == 400) {
				if (barX > -440 & barX < -310 & keyY > 350 & keyY < 450) {
					powerUpTaken = true;
					r = 0.0; g = 0.1; b = 0.2;
				}
			}


		}
		else if (barX <= -450 & barX > -550 & y3 < keyY & keyY < y4) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop == false;
			scoreCount = scoreCount + 10;
		
			
		}
		else if (barX <= -550 & barX > -750 & keyY < 800 & keyY>40) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
		}
		else if (barX <= -750 & barX > -850 & y5 < keyY & keyY < y6) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			scoreCount = scoreCount + 10;

		}
		else if (barX <= -850 & barX > -1050 & keyY < 800 & keyY>40) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			powerUpTaken = false;

		}
		else if (barX <= -1050 & barX > -1150 & y7 < keyY & keyY < y8) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			scoreCount = scoreCount + 10;
		}
		else if (barX <= -1150 & barX > -1350 & keyY < 800 & keyY>40) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
		}
		else if (barX <= -1350 & barX > -1450 & y9 < keyY & keyY < y10) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			scoreCount = scoreCount + 10;
		}
		else if (barX <= -1450 & barX > -1650) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
		}
		else if (barX <= -1650 & barX > -1750 & y11 < keyY & keyY < y12) {

			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
			scoreCount = scoreCount + 10;
		}
		else if (barX <= -1750 & barX > -1950 & keyY < 800 & keyY>40) {
			keyY = keyY - 1;
			prevY = keyY;
			keyCount = keyCount - 1;
			barX = barX - 2;
			stop = false;
		}
		else if (barX <= -1950 & barX > -2050 & keyY < y14 & keyY>y13) {
		keyY = keyY - 1;
		prevY = keyY;
		keyCount = keyCount - 1;
		barX = barX - 2;
		stop = false;
		}
		else if (barX <= -2050 & barX > -2250 & keyY < 800 & keyY>40) {
		keyY = keyY - 1;
		prevY = keyY;
		keyCount = keyCount - 1;
		barX = barX - 2;
		stop = false;
		}
		else if (barX <= -2250 & barX > -2350 & keyY < y16 & keyY>y15) {
		keyY = keyY - 1;
		prevY = keyY;
		keyCount = keyCount - 1;
		barX = barX - 2;
		stop = false;
		}
		else if (barX <= -2350 & barX > -2550 & keyY < 799 & keyY>40) {
		keyY = keyY - 1;
		prevY = keyY;
		keyCount = keyCount - 1;
		barX = barX - 2;
		pass = true;
		stop = false;
		}

		else {
			stop = true;
			if (powerUpTaken) {
			barX = barX - 200;
			PlaySound(TEXT("C:\\Users\\ziadd\\Downloads\\powerup.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//powerUpTaken = false;
			used = true;
			liveCount = 0;
			powerUpTaken = false;
			}
			else if (barX==-150 & liveCount < 3) {
				keyY = (y1 + y2) / 2;
				scoreCount = 0;
			}
			else if (barX == -450 & liveCount < 3) {
				keyY = (y3 + y4) / 2;
				scoreCount = 0;
			}
			else if (barX == -750 & liveCount < 3) {
				keyY = (y5 + y6) / 2;
				scoreCount = 0;
			}
			else if (barX == -1050 & liveCount < 3) {
				keyY = (y7 + y8) / 2;
				scoreCount = 0;
			}
			else if (barX == -1350 & liveCount < 3) {
				keyY = (y9 + y10) / 2;
				scoreCount = 0;
			}
			else if (barX == -1650 & liveCount < 3) {
				keyY = (y11 + y12) / 2;
				scoreCount = 0;
			}
			else if (barX == -1950 & liveCount < 3) {
				keyY = 250;
				scoreCount = 0;
			}
			else if (barX == -2250 & liveCount < 3 ) {
				keyY = 200;
				scoreCount = 0;
			}
			else if (pass) {
				keyX = 0;
				win = true;
			}
			else if (liveCount == 3) {
				keyX = 0;
				scoreCount = 0;
				lose = true;
				PlaySound(TEXT("C:\\Users\\ziadd\\Downloads\\lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			

		}
	}
}

void drawBitmapText(string text, float x, float y, float z)
{

	glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(x, y, z);
	for (int i = 0; i < text.size(); i++)
	{ 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}

void drawScore() {
	string score = "SCORE : " + to_string(int(scoreCount));
	drawBitmapText(score, 190, 40, 0);
}


void drawWin() {
	string score = "CONGRATS YOU WIN. SCORE: " + to_string(int(scoreCount));
	drawBitmapText(score, 500, 500, 0);
	
}


void drawLose() {
	string score = "YOU LOST";
	drawBitmapText(score, 500, 500, 0);
}


void drawCircle(GLfloat x, GLfloat y, GLfloat radius, float r, float g, float b) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	glPushMatrix();
	GLfloat twicePi = 2.0f * atan(1) * 4;
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);
	glTranslated(300.0, keyY, 0);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
	glPopMatrix();
}


void DrawCirclee(float cx, float cy, float r, int num_segments) {
	glBegin(GL_TRIANGLE_FAN);

	glColor3d(0.0, 0.0, 0.0);
	//DrawCircle(100.0, 500.0, 40.0, 100);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}


void drawEye(float cx, float cy, float r, int num_segments) {
	glBegin(GL_TRIANGLE_FAN);

	glColor3d(1.0, 0.0, 0.0);
	//DrawCircle(100.0, 500.0, 40.0, 100);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}


void DrawCircle2(float cx, float cy, float r, int num_segments) {
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.0, 0.0);
	//DrawCircle(100.0, 500.0, 40.0, 100);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}

void drawSign() {
	glPushMatrix();
	glColor3f(1.0, 0.7, 0.0);
	glTranslated(barX, 0, 0);
	//	glScalef(0.3, 0.3, 0.3);
	glBegin(GL_TRIANGLES);
	glVertex3d(810, 440, 0);
	glVertex3d(780, 400, 0);
	glVertex3d(800, 400, 0);
	glEnd();
	glPopMatrix();

}
void drawSign2() {
	glPushMatrix();
	glColor3f(1.0, 0.7, 0.0);
	glTranslated(barX, 0, 0);
	//	glScalef(0.3, 0.3, 0.3);
	glBegin(GL_TRIANGLES);
	glVertex3d(800, 400, 0);
	glVertex3d(790, 360, 0);
	glVertex3d(820, 400, 0);

	glEnd();
	glPopMatrix();
}

void DrawPowerUp(float cx, float cy, float r, int num_segments) {
	glPushMatrix();
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.9, 0.0, 0.0);
	//DrawCircle(100.0, 500.0, 40.0, 100);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
	glPopMatrix();
	drawSign();
	drawSign2();


}


void DrawLive(float cx, float cy, float r, int num_segments) {
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 1.0, 0.0);
	//DrawCircle(100.0, 500.0, 40.0, 100);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}


void drawSemiCircle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	glPushMatrix();
	GLfloat twicePi = atan(1) * 4;
	glColor3f(0, 0, 0);
	glTranslated(300.0, keyY, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
	glPopMatrix();
}

void drawPlayer(GLfloat x, GLfloat y, GLfloat radius) {


		// BODY OF LADY BIRD
		int i;
		int triangleAmount = 20;
		glPushMatrix();
		GLfloat twicePi = atan(1) * 4;
		glColor3f(1, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i * twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		glPopMatrix();
		// Spots
		drawSemiCircle(x - (0.6 * radius), y, radius / 4);
		drawSemiCircle(x + (0.6 * radius), y, radius / 4);
		//drawCircle(x, y + (0.6 * radius), radius / 4, 0, 0, 0);
		//drawCircle(x - radius, y + radius, radius / 2, 0, 0, 0);

		

		//POWER UP LEGS

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_LINES);
		glVertex3f(x - radius, y, 0);
		glVertex3f(x - radius, y - (radius / 2), 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_LINES);
		glVertex3f(x + radius, y, 0);
		glVertex3f(x + radius, y - (radius / 2), 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_LINES);
		glVertex3f(x - radius + 4, y, 0);
		glVertex3f(x - radius + 4, y - (radius / 2), 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_LINES);
		glVertex3f(x - radius + 8, y, 0);
		glVertex3f(x - radius + 8, y - (radius / 2), 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_LINES);
		glVertex3f(x + radius - 4, y, 0);
		glVertex3f(x + radius - 4, y - (radius / 2), 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(300.0, keyY, 0);
		glBegin(GL_LINES);
		glVertex3f(x + radius - 8, y, 0);
		glVertex3f(x + radius - 8, y - (radius / 2), 0);
		glEnd();
		glPopMatrix();


		glPushMatrix();
		glTranslated(300.0, keyY, 0);
		DrawCirclee(140.0, 30, 20.0, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslated(300.0, keyY, 0);
		DrawCirclee(100.0, 20, 10.0, 100);
		glPopMatrix();


		glPushMatrix();
		glTranslated(300.0, keyY, 0);
		drawEye(145.0, 35, 5.0, 100);
		glPopMatrix();


	}




void drawSet1(int x) {
	//SET1
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.1);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 768, 0);
	glVertex3d(x + 400, 768, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); 
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x,768, 0);
	glVertex3d(x+100,768, 0);

	glVertex3d(x+100,500, 0);
	glVertex3d(x, 500, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); 
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	
	glVertex3d(x, 500, 0);
	glVertex3d(x+25, 450, 0);
	glVertex3d(x+50, 500, 0);
	glVertex3d(x+50, 500, 0);
	glVertex3d(x+75, 450, 0);
	glVertex3d(x+100, 500, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 200, 0);
	glVertex3d(x+100, 200, 0);
	glVertex3d(x+100, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x, 200, 0);
	glVertex3d(x+25, 250, 0);
	glVertex3d(x+50, 200, 0);
	glVertex3d(x+50, 200, 0);
	glVertex3d(x+75, 250, 0);
	glVertex3d(x+100, 200, 0);
	glEnd();
	glPopMatrix();

	//// 

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x+300, 768, 0);
	glVertex3d(x+400, 768, 0);
	glVertex3d(x+400, 450, 0);
	glVertex3d(x+300, 450, 0);
	glEnd();
	glPopMatrix();

	//Background 1

	

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x+300, 450, 0);
	glVertex3d(x+325, 400, 0);
	glVertex3d(x+350, 450, 0);
	glVertex3d(x+350, 450, 0);
	glVertex3d(x+375, 400, 0);
	glVertex3d(x+400, 450, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x+300, 150, 0);
	glVertex3d(x+400, 150, 0);
	glVertex3d(x+400, 0, 0);
	glVertex3d(x+300, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x+300, 150, 0);
	glVertex3d(x+325, 200, 0);
	glVertex3d(x+350, 150, 0);
	glVertex3d(x+350, 150, 0);
	glVertex3d(x+375, 200, 0);
	glVertex3d(x+400, 150, 0);
	glEnd();
	glPopMatrix();

	
}


void drawSet2(int x) {

	glPushMatrix();
	glColor3f(0.7, 0.3, 0.7);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 768, 0);
	glVertex3d(x + 400, 768, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();


	//SET2
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 768, 0);
	glVertex3d(x + 100, 768, 0);

	glVertex3d(x + 100, 700, 0);
	glVertex3d(x, 700, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3d(x, 700, 0);
	glVertex3d(x + 25, 650, 0);
	glVertex3d(x + 50, 700, 0);
	glVertex3d(x + 50, 700, 0);
	glVertex3d(x + 75, 650, 0);
	glVertex3d(x + 100, 700, 0);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 400, 0);
	glVertex3d(x + 100, 400, 0);
	glVertex3d(x + 100, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x, 400, 0);
	glVertex3d(x + 25, 450, 0);
	glVertex3d(x + 50, 400, 0);
	glVertex3d(x + 50, 400, 0);
	glVertex3d(x + 75, 450, 0);
	glVertex3d(x + 100, 400, 0);
	glEnd();
	glPopMatrix();

	//// 

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x + 300, 768, 0);
	glVertex3d(x + 400, 768, 0);
	glVertex3d(x + 400, 550, 0);
	glVertex3d(x + 300, 550, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x + 300, 550, 0);
	glVertex3d(x + 325, 500, 0);
	glVertex3d(x + 350, 550, 0);
	glVertex3d(x + 350, 550, 0);
	glVertex3d(x + 375, 500, 0);
	glVertex3d(x + 400, 550, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x + 300, 250, 0);
	glVertex3d(x + 400, 250, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x + 300, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x + 300, 250, 0);
	glVertex3d(x + 325, 300, 0);
	glVertex3d(x + 350, 250, 0);
	glVertex3d(x + 350, 250, 0);
	glVertex3d(x + 375, 300, 0);
	glVertex3d(x + 400, 250, 0);
	glEnd();
	glPopMatrix();


}


void drawSet3(int x) {



	glPushMatrix();
	glColor3f(0.5, 0.2, 0.8);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 768, 0);
	glVertex3d(x + 400, 768, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	//SET1
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x+300, 768, 0);
	glVertex3d(x + 400, 768, 0);

	glVertex3d(x + 400, 300, 0);
	glVertex3d(x+300, 300, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3d(x+300, 300, 0);
	glVertex3d(x + 325, 250, 0);
	glVertex3d(x + 350, 300, 0);
	glVertex3d(x + 350, 300, 0);
	glVertex3d(x + 375,250, 0);
	glVertex3d(x + 400, 300, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x+300, 80, 0);
	glVertex3d(x + 400, 80, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x+300, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x+300, 80, 0);
	glVertex3d(x + 325, 100, 0);
	glVertex3d(x + 350, 80, 0);
	glVertex3d(x + 350, 80, 0);
	glVertex3d(x + 375, 100, 0);
	glVertex3d(x + 400, 80, 0);
	glEnd();
	glPopMatrix();

	//// 

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x , 768, 0);
	glVertex3d(x + 100, 768, 0);
	glVertex3d(x + 100, 500, 0);
	glVertex3d(x , 500, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x , 500, 0);
	glVertex3d(x + 25, 450, 0);
	glVertex3d(x + 50, 500, 0);
	glVertex3d(x + 50, 500, 0);
	glVertex3d(x + 75, 450, 0);
	glVertex3d(x + 100, 500, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x , 200, 0);
	glVertex3d(x + 100, 200, 0);
	glVertex3d(x + 100, 0, 0);
	glVertex3d(x , 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x , 200, 0);
	glVertex3d(x + 25, 250, 0);
	glVertex3d(x + 50, 200, 0);
	glVertex3d(x + 50, 200, 0);
	glVertex3d(x + 75, 250, 0);
	glVertex3d(x + 100, 200, 0);
	glEnd();
	glPopMatrix();


}


void drawSet4(int x) {
	//SET1
	glPushMatrix();
	glColor3f(0.3, 0.9, 0.4);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 768, 0);
	glVertex3d(x + 400, 768, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 768, 0);
	glVertex3d(x + 100, 768, 0);

	glVertex3d(x + 100, 400, 0);
	glVertex3d(x, 400, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);

	glVertex3d(x, 400, 0);
	glVertex3d(x + 25, 350, 0);
	glVertex3d(x + 50, 400, 0);
	glVertex3d(x + 50, 400, 0);
	glVertex3d(x + 75, 350, 0);
	glVertex3d(x + 100, 400, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x, 100, 0);
	glVertex3d(x + 100, 100, 0);
	glVertex3d(x + 100, 0, 0);
	glVertex3d(x, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x, 100, 0);
	glVertex3d(x + 25, 150, 0);
	glVertex3d(x + 50, 100, 0);
	glVertex3d(x + 50, 100, 0);
	glVertex3d(x + 75, 150, 0);
	glVertex3d(x + 100, 100, 0);
	glEnd();
	glPopMatrix();

	//// 

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x + 300, 768, 0);
	glVertex3d(x + 400, 768, 0);
	glVertex3d(x + 400, 350, 0);
	glVertex3d(x + 300, 350, 0);
	glEnd();
	glPopMatrix();

	//Background 1



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x + 300, 350, 0);
	glVertex3d(x + 325, 320, 0);
	glVertex3d(x + 350, 350, 0);
	glVertex3d(x + 350, 350, 0);
	glVertex3d(x + 375, 320, 0);
	glVertex3d(x + 400, 350, 0);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(x + 300, 70, 0);
	glVertex3d(x + 400, 70, 0);
	glVertex3d(x + 400, 0, 0);
	glVertex3d(x + 300, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(barX, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(x + 300, 70, 0);
	glVertex3d(x + 325, 120, 0);
	glVertex3d(x + 350, 70, 0);
	glVertex3d(x + 350, 70, 0);
	glVertex3d(x + 375, 120, 0);
	glVertex3d(x + 400, 70, 0);
	glEnd();
	glPopMatrix();


}

void dolives() {
	if (liveCount==0) {
		glPushMatrix();
		glTranslated(0, 300, 0);
		DrawLive(50, -250, 20, 100);
		glColor3f(255, 0, 0);

		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 300, 0);
		DrawLive(100, -250, 20, 100);
		glColor3f(255, 0, 0);

		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 300, 0);
		DrawLive(150, -250, 20, 100);
		glColor3f(255, 0, 0);

		glPopMatrix();
	}
	else if (liveCount==1) {
			glPushMatrix();
			glTranslated(0, 300, 0);
			DrawLive(50, -250, 20, 100);
			glColor3f(255, 0, 0);

			glPopMatrix();

			glPushMatrix();
			glTranslated(0, 300, 0);
			DrawLive(100, -250, 20, 100);
			glColor3f(255, 0, 0);

			glPopMatrix();
		
	}
	else if (liveCount == 2) {
		glPushMatrix();
		glTranslated(0, 300, 0);
		DrawLive(50, -250, 20, 100);
		glColor3f(255, 0, 0);

		glPopMatrix();

	}

}

void drawBariers() {
	drawSet1(barPos1);
	drawSet2(barPos2);
	drawSet3(barPos3);
	drawSet4(barPos4);

}

void Display() {

	glClearColor(backRed, backGreen, backBlue, 0.0f);//the background color is changed in the timer function after 1 sec by changing these parameters.
	glClear(GL_COLOR_BUFFER_BIT);
	drawBariers();
	drawPlayer(100.0,0, 40);
	
	if (!powerUpTaken) {
		DrawPowerUp(powerUpX, powerUpY, 40.0, 100);
	}
	if (stop==true & !powerUpTaken) {
		liveCount += 1;
	}
	stop = false;
	//test = test + 100;
	dolives();
	drawScore();
	if (win) {
		drawWin();
		//PlaySound(TEXT("C:\\Users\\ziadd\\Downloads\\win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		
	}
	if (lose) {
		drawLose();
	}


	

	glFlush();
}


void passM(int x, int y)//passive motion function takes 2 parameters the x and y positions of the mouse
						//it allows the user to make use of the mouse motion without clicking on the mouse buttons
{
	passX = x;//it moves the red square center to the mouse location.
	passY = y;
	glutPostRedisplay();
}

void actM(int button, int state, int x, int y)//mouse function takes 4 parameters: button: which button has been clicked (GLUT_RIGHT_BUTTON or GLUT_LEFT_BUTTON),
											//state wether the button is clicked or released (GLUT_UP or GLUT_DOWN)
											// x and y are the position of the mouse cursor
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//if the left button has been clicked then translate the square to the mouse position
	{
		actX = x - 10;
		actY = 250 - y - 20;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//if the right button has been clicked, translate  the square to the origin (0,0)
	{
		actX = 0;
		actY = 0;
	}

	glutPostRedisplay();//redisplay to update the screen with the new paraeters
}

void key(unsigned char k, int x, int y)//keyboard function, takes 3 parameters
									// k is the key pressed from the keyboard
									// x and y are mouse postion when the key was pressed.
{
	if (k == 'w' & !lose & !win) {//if the letter w is pressed, then the object will be translated in the y axis by 10. (moving upwords)
		keyY += 50;
		keyCount += 50;
		angle = 20;
		PlaySound(TEXT("C:\\Users\\ziadd\\Downloads\\jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	



	
	glutPostRedisplay();//redisplay to update the screen with the changes
}

void keyUp(unsigned char k, int x, int y)//keyboard up function is called whenever the keyboard key is released
{
	if (k == 'q')//if the letter q is pressed, then the object will go back to it's original color.
		keyC = 0;
	glutPostRedisplay();//redisplay to update the screen with the changed
}

void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	if (k == GLUT_KEY_RIGHT)//if the right arrow is pressed, then the object will be translated in the x axis by 10. (moving right)
		speX += 10;
	if (k == GLUT_KEY_LEFT)//if the left arrow is pressed, then the object will be translated in the x axis by -10. (moving left)
		speX -= 10;
	if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
		speY += 10;
	if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
		speY -= 10;
	if (k == GLUT_KEY_F1)//if the F1 key is pressed, then the object color will be changed
		speC = 1;
	glutPostRedisplay();//redisplay to update the screen with the changes
}

void speUp(int k, int x, int y)// keyboard special key function is called whenever the special key is released.
{
	if (k == GLUT_KEY_F1)//if the F1 key is released, then the object will return back to it's original color.
		speC = 0;
	glutPostRedisplay();//redisplay to update the screen with the changes
}

void time2(int val)//timer animation function, allows the user to pass an integer valu to the timer function.
{
	// spawn area
	if (!lose & !win) {
		scoreCount = scoreCount + 1;
	}
	barriers();
	glutPostRedisplay();						// redraw 		
	glutTimerFunc(1, time2, 0);					//recall the time function after 1000 ms and pass a zero value as an input to the time func.
}

void main(int argc, char** argr) {


	glutInit(&argc, argr);
	std::string a1 = "sound.wav";

	glutInitWindowSize(700, 500);
	glutInitWindowPosition(150, 150);

	if (pls == true) {
		//PlaySound(TEXT("C:\\Users\\ziadd\\Downloads\\sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
		unsigned seed = time(0);
		srand(seed);
		randNum = (rand() % 9) + 1;
		powerUpX = 800;
		powerUpY = 400;
		pls = false;
	}
	glutCreateWindow("Game");
	glutDisplayFunc(Display);
	glutPassiveMotionFunc(passM);	//call the passive motion function
	glutMouseFunc(actM);			//call the mouse function
	glutKeyboardFunc(key);			//call the keyboard function
	glutKeyboardUpFunc(keyUp);		//call the keyboard up function
	glutSpecialFunc(spe);			//call the keyboard special keys function
	glutSpecialUpFunc(speUp);		//call the keyboard special keys up function
	glutTimerFunc(0, time2, 0);		//call the timer function
	glPointSize(25);				//change the point size to be 25
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 1366, 0.0, 768);

	glutMainLoop();
}
