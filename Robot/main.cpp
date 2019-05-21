#include <iostream>
#include <ctime>
#include "Skeleton.h"

using namespace std;

const int windowWidth = 800;
const int windowHeight = 800;
const int windowDepth = 800;
Skeleton drawer;

void init();
void renderScene();
void normalKeyCallback(unsigned char key, int x, int y);
void mouseCallback(int button, int state, int x, int y);

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Robot");
	init();
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(normalKeyCallback);
	glutMouseFunc(mouseCallback);
	glutMainLoop();
	return 0;
}

void init() {
	// 透视投影
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(0.0, windowWidth, windowHeight, 0.0, 0.0, windowDepth);
	// 视图矩阵
	/*第一组eyex, eyey, eyez 相机在世界坐标的位置
	第二组centerx, centery, centerz 相机镜头对准的物体在世界坐标的位置
	第三组upx, upy, upz 相机向上的方向在世界坐标中的方向
	你把相机想象成为你自己的脑袋：
	第一组数据就是脑袋的位置
	第二组数据就是眼睛看的物体的位置
	第三组就是头顶朝向的方向（因为你可以歪着头看同一个物体）*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.2, 0.2, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	gluLookAt(0.0, -0.1, 0.0, 0.0, 0.0, -5.0, 0.0, 1.0, 0.0);

	// 设置光照模型
	GLfloat position[] = { 3.0f, 5.0f, 0.0f, 0.0f }; // 光源位置
	GLfloat ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f }; // 环境光
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 漫射光
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 镜面光
	//GLfloat lmodel_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	//GLfloat local_view[] = { 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	//glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// 设置材质
	GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };  //定义材质的环境光颜色
	GLfloat mat_diffuse[] = { 0.8f, 0.5f, 0.5f, 1.0f };  //定义材质的漫反射光颜色
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };   //定义材质的镜面反射光颜色
	GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 1.0f };   //定义材质的辐射广颜色
	GLfloat mat_shininess = 100.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	// 开启深度测试
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glColor4d(0.3, 0.1, 0.9, 1.0);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 测试数据
	//glTranslated(0.5, 0.5, 0.0);
	/*glBegin(GL_TRIANGLES);
	glVertex3d(0.1, 0.1, 0.0);
	glVertex3d(0.4, 0.1, 0.0);
	glVertex3d(0.3, 0.5, 0.0);
	glEnd();*/
	//glutWireCube(1.0);
	/*GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.2, 0.2, 1.0, 1000, 1000);*/
	drawer.draw();
	glutSwapBuffers();
}

void normalKeyCallback(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(1);
		break;
	case 'q':
		drawer.moveCameraLeft();
		glutPostRedisplay();
		break;
	case 'e':
		drawer.moveCameraRight();
		glutPostRedisplay();
		break;
	case 't':
		drawer.walk();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void mouseCallback(int button, int state, int x, int y) {
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			cout << '(' << x << ',' << y << ')' << endl;
		break;
	default:
		break;
	}
}