// TestOpenGL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdafx.h"  
#include "GL/glut.h"  
#include "GL/gl.h"  
void  display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0, 0.0, 0.0, 1.0);     // set the quad color  
	glBegin(GL_QUADS);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145);
	glEnd();
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}



//int _tmain(int argc, _TCHAR* argv[])  
//{  
//  glutInit(&argc, argv);  
//  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  
//  glutInitWindowPosition(100, 100);  
//  glutInitWindowSize(400, 400);  
// glutCreateWindow("��һ��OpenGL����");  
//  glutDisplayFunc(&myDisplay);  
//  glutMainLoop();  
//  return 0;  
//}  
int main(int argc, char** argv)
{
	//todo����һ��������
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("��һ��OpenGL����");
	glutDisplayFunc(&display);
	glutMainLoop();
	//todo:�ڶ�����ֱ��
	//glutInit(&argc, argv);
	/*glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("OpenGL");
	init();
	glutDisplayFunc(&myDisplay);*/
	glutMainLoop();

	return 0;
}

