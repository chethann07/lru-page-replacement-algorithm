#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define SCENE 10

int request[9] = { 0 }, counter[3] = { 0 }, pages[3] = { 0 }, fault[9] = { 0 }, colour[9] = { 1,1,1,1,1,1,1,1,1 }, pagecolour[3] = { 1,1,1 };
float assigns[9] = { -5.5,-5.5,-5.5,-5.5,-5.5,-5.5,-5.5,-5.5,-5.5 };
int dest = 0, showresult = 0;
int step = -1, startani = 0, faults = 0;
char res[] = "No. of page faults =  ";

float bgcolor[][3] = { {1,0,0},{0,1,0},{0,0,1} };
int bgpointer = 0;
float tilecolor[][3] = { {1,1,0},{1,0.7,0.7},{0,1,1} };
int tilepointer = 0;
void* fonts[] =
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_12,
GLUT_BITMAP_HELVETICA_10,
GLUT_BITMAP_HELVETICA_18,
};

void output(int x, int y, const char* string, int j)
{
	int len, i;
	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(fonts[j], string[i]);
}



void front_page()
{
	//glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();


	output(270, 500, "EAST WEST COLLEGE OF ENGINEERING ", 2);
	output(335, 450, " BANGALORE ", 2);
	output(285, 400, "Subject:Computer Graphics (18CSL67)", 2);
	output(360, 350, "   A   ", 2);
	output(330, 300, "MINI PROJECT ON", 2);
	output(280, 250, "LRU PAGE REPLACEMENT ALGORITHM", 2);
	output(225, 150, "Guide:", 5);
	output(250, 130, "Ms.Kumuda N S", 5);
	output(135, 100, "", 5);

	output(515, 150, "By:", 5);
	output(525, 130, "Chethan G [1EE20CS010]", 5);
	output(525, 110, "Sohan R [1EE20CS054]", 5);
	output(330, 50, "PRESS S to START", 2);

	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();
}

void init()
{
	glColor3f(0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glMatrixMode(GL_MODELVIEW);

}

int getLRU()
{
	if (counter[0] >= counter[1] && counter[0] >= counter[2]) return 0;
	if (counter[1] >= counter[0] && counter[1] >= counter[2]) return 1;
	//if(counter[2]>=counter[1] && counter[2]>=counter[3]) return 2;
	return 2;
}

void tile(float x, float y, char n)
{

	float size = 20;

	//glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glVertex2f(x + size, y + size);
	glVertex2f(x - size, y + size);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glVertex2f(x + size, y + size);
	glVertex2f(x - size, y + size);
	glEnd();
	glRasterPos2f(x - size / 2, y);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, n);


}

void draw_flag()
{

	glColor3fv(bgcolor[bgpointer]);
	glBegin(GL_POLYGON);
	glVertex2f(-10, -10);
	glVertex2f(10, -10);
	glVertex2f(10, 10);
	glVertex2f(-10, 10);
	glEnd();

}



void setup_request()
{
	int i;
	glColor3fv(bgcolor[bgpointer]);

	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(700, 0);
	glVertex2f(700, 100);
	glVertex2f(0, 100);
	glEnd();


	glPushMatrix();
	glTranslatef(-10, 40, 0);
	for (i = 0; i < 9; i++)
	{
		glColor3fv(tilecolor[tilepointer]);
		glTranslatef(70, 0, 0);
		glPushMatrix();

		if (assigns[i] > -4.5)
		{

			glTranslatef(70 * step - 70 * i, 0, 0);
		}

		glTranslatef(0, -250 - 45 * assigns[i], 0);

		if ((int)assigns[i] == dest && assigns[i] >= 0)
			glColor3f(1, 0.3, 0.3);
		else
			//glColor3f(colour[i],1,0);
			glColor3fv(tilecolor[tilepointer]);

		tile(10, 10, request[i] + '0');
		glPopMatrix();

		if (fault[i])
		{
			glPushMatrix();
			glTranslatef(0, -385, 0);
			draw_flag();
			glPopMatrix();
		}

	}

	glPopMatrix();

}

void drawText(const char* string, float x, float y, float z)
{
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		if (*c == '\n')
			glRasterPos3f(x, y - 0.05, z);
		else
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}


void setup_pages()
{


	glPushMatrix();
	//glColor3f(fabs(sin(ycolour[1])), 1, 0);
//	glColor3f(1, pagecolour[0], 0);
	tile(0, 0, pages[0] == 0 ? ' ' : pages[0] + '0');
	glTranslatef(0, -45, 0);
	//	glColor3f(fabs(sin(ycolour[2])), 1, 0);
		//glColor3f(1, pagecolour[1], 0);
	tile(0, 0, pages[1] == 0 ? ' ' : pages[1] + '0');
	glTranslatef(0, -45, 0);
	//	glColor3f(fabs(sin(ycolour[3])), 1, 0);
		//glColor3f(1, pagecolour[2], 0);
	tile(0, 0, pages[2] == 0 ? ' ' : pages[2] + '0');
	glPopMatrix();


}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glTranslatef(120 + 70 * step, 200, 0);
	setup_pages();
	glPopMatrix();

	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(50, 400, 0);
	setup_request();
	glPopMatrix();


	glEnd();



	if (showresult && step == 8)
	{
		glColor3f(0, 0, 0);
		res[21] = faults + '0';
		drawText(res, 50, 20, 0);
	}
	drawText("LRU Page Replacement Algorithm", 340, 550, 1);
	drawText("LRU page replacement is a popular algorithm used in computer science to manage memory in an efficient way. It works by keeping track of the time when a page was",50,535,0);
	drawText("last accessed, and replacing the page that was least recently used. This helps to ensure that the most frequently used pages are kept in memory, while less",50,520,0);
	drawText("frequently used pages are swapped out to disk. LRU is a simple and effective algorithm that has been used in many operating systems and applications",50,505,0);



	glFlush();
	glutSwapBuffers();
}

void idle()
{

	if (!startani)
		return;

	if (dest > assigns[step])
		assigns[step] += 0.01;

	if (dest <= assigns[step])
	{
		if (fault[step])
			pages[dest] = request[step];
		startani = 0;
		dest = -10;
		showresult = 1;
	}

	display();

}


void mouse(int btn, int state, int x, int y)
{
	int n, i, j;
	if (startani == 1)
		return;
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN && step < 8)
	{
		if (step < 9)
			step++;
		for (i = 0; i < 3; i++)
		{
			if (request[step] == pages[i])
			{
				fault[step] = 0;
				counter[i] = 0;
				for (j = 0; j < 3; j++)
					if (j != i) counter[j]++;
				//dest=i;
				dest = -5;
				startani = 1;
				colour[step] = 0;
				glutPostRedisplay();
				return;
			}
		}
		n = getLRU();
		counter[n] = 0;
		for (i = 0; i < 3; i++)
			if (i != n)
				counter[i]++;
		//pagecolour[n]=0;
		//assigns[step]=n;
		dest = n;
		startani = 1;

		fault[step] = 1;
		faults++;
	}
	glutPostRedisplay();
}

void handle_bg_colour(int action)
{
	bgpointer = action;
	glutPostRedisplay();
}

void handle_tile_colour(int action)
{
	tilepointer = action;
	glutPostRedisplay();
}

void menu(int action)
{

	if (action == 0)
		exit(0);

    if(action == 1)
    {
    //glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();


	output(270, 575, "LRU PAGE REPLACEMENT ALGORITHM", 2);
	output(8, 530, "This is a simple explaination of the algorithm in few steps.These steps are as follows:", 2);
	output(20, 490, "-> Initialize the cache: Start with an empty cache of a fixed size (number of pages) to hold frequently accessed pages.", 2);
	output(20, 460, "-> Page Request: When a page is requested by the CPU, check if it is already present in the cache.", 2);
	output(20, 430, "->Cache Hit: If the page is found in the cache (cache hit), mark the page as the most recently used and update its position in the cache accordingly.", 2);
	output(35, 410, "No further action is required.", 2);
	output(20, 380, "->Cache Miss: If the page is not found in the cache (cache miss), it needs to be loaded into the cache.", 2);
	output(20, 350, "->Empty Slot: If there is an empty slot in the cache, simply place the requested page in the empty slot and mark it as the most recently used.", 2);
	output(20, 320, "->Full Cache: If the cache is already full, select the least recently used page for eviction. This is the page that has not been accessed for the longest time.", 2);
    output(20, 290, "->Evict the LRU page: Remove the least recently used page from the cache to make room for the new page. The evicted page is then replaced with the", 2);
	output(35, 270, "requested page, which becomes the most recently used.", 2);
	output(20, 240, "->Update Cache Order: After evicting the LRU page and inserting the new page, update the order of the remaining pages in the cache. Move the", 2);
	output(35, 220, "remaining pages up one position to make space for the new most recently used page.", 2);
	output(20, 190, "->Repeat: Repeat the above steps for each page request, continuously tracking the least recently used page and updating the cache accordingly.", 2);

	glFlush();
	glCallList(SCENE);
	glPopMatrix();
	glutSwapBuffers();

    }

}


void addMenu()
{
	int submenu1, submenu2;

	submenu1 = glutCreateMenu(handle_bg_colour);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);

	submenu2 = glutCreateMenu(handle_tile_colour);
	glutAddMenuEntry("Yellow", 0);
	glutAddMenuEntry("Light Red", 1);
	glutAddMenuEntry("Light Blue", 2);

	glutCreateMenu(menu);
	glutAddSubMenu("Background Colour", submenu1);
	glutAddSubMenu("Tile Colour", submenu2);
	glutAddMenuEntry("About the algorithm",1);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display1()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	front_page();
	glFlush();
	glutSwapBuffers();
}

void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'S':
	case 's':glutDisplayFunc(display);
    break;

	case 'Q':
	case 'q':exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	int i;
	printf("Enter a sequence of 9 numbers for page request\n");
	for (i = 0; i < 9; i++)
		scanf("%d", &request[i]);
    	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	//glutInitWindowSize(640,480);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("LRU Page Rreplacement Algorithm");
	glutDisplayFunc(display1);
	glutDisplayFunc(front_page);
    glutKeyboardFunc(key);
	//glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	glClearColor(1, 1, 1, 1);
	init();
	addMenu();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0;
}
