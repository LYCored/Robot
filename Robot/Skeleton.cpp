#include "Skeleton.h"



Skeleton::Skeleton()
{
	leftShoulder[0] = 0.13;
	leftShoulder[1] = 0.47;
	leftShoulder[2] = 0;
	rightShoulder[0] = -0.13;
	rightShoulder[1] = 0.47;
	rightShoulder[2] = 0;
	leftUpperArm[0] = 0.135;
	leftUpperArm[1] = 0.44;
	leftUpperArm[2] = 0;
	rightUpperArm[0] = -0.135;
	rightUpperArm[1] = 0.44;
	rightUpperArm[2] = 0;
	leftElbow[0] = 0.155;
	leftElbow[1] = 0.32;
	leftElbow[2] = 0;
	rightElbow[0] = -0.155;
	rightElbow[1] = 0.32;
	rightElbow[2] = 0;
	leftLowerArm[0] = 0.155;
	leftLowerArm[1] = 0.32;
	leftLowerArm[2] = 0;
	rightLowerArm[0] = -0.155;
	rightLowerArm[1] = 0.32;
	rightLowerArm[2] = 0;
	leftHand[0] = 0.155;
	leftHand[1] = 0.15;
	leftHand[2] = 0.0;
	rightHand[0] = -0.155;
	rightHand[1] = 0.15;
	rightHand[2] = 0.0;
	leftHip[0] = 0.07;
	leftHip[1] = 0.1;
	leftHip[2] = 0;
	rightHip[0] = -0.07;
	rightHip[1] = 0.1;
	rightHip[2] = 0;
	leftThigh[0] = 0.07;
	leftThigh[1] = 0.1;
	leftThigh[2] = 0;
	rightThigh[0] = -0.07;
	rightThigh[1] = 0.1;
	rightThigh[2] = 0;
	leftKnee[0] = 0.07;
	leftKnee[1] = -0.12;
	leftKnee[2] = 0;
	rightKnee[0] = -0.07;
	rightKnee[1] = -0.12;
	rightKnee[2] = 0;
	leftCalf[0] = 0.07;
	leftCalf[1] = -0.12;
	leftCalf[2] = 0;
	rightCalf[0] = -0.07;
	rightCalf[1] = -0.12;
	rightCalf[2] = 0;
	cameraHorizontalSpeed = 1.0;
	leftUpperArmAngle = 0;
	leftLowerArmAngle = 0;
	rightUpperArmAngle = 0;
	rightLowerArmAngle = 0;
	armFlag = true;
}


Skeleton::~Skeleton()
{
}

void Skeleton::draw()
{
	drawHead();
	drawBody();
	drawLeftShoulder();
	drawRightShoulder();
	drawLeftUpperArm();
	drawRightUpperArm();
	drawLeftElbow();
	drawRightElbow();
	drawLeftLowerArm();
	drawRightLowerArm();
	drawLeftHand();
	drawRightHand();
	drawButtocks();
	drawLeftHip();
	drawRightHip();
	drawLeftThigh();
	drawRightThigh();
	drawLeftKnee();
	drawRightKnee();
	drawLeftCalf();
	drawRightCalf();
	/*drawLeftAnkle();
	drawRightAnkle();
	drawLeftFoot();
	drawRightFoot();*/
}

void Skeleton::drawHead()
{
	glPushMatrix();
	glTranslated(0.0, 0.6, 0.0);
	glutSolidSphere(0.1, 100, 100);
	glPopMatrix();
}

void Skeleton::drawBody()
{
	glPushMatrix();
	glTranslated(0.0, 0.5, 0.0);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.1, 0.1, 0.3, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftShoulder()
{
	glPushMatrix();
	glTranslated(leftShoulder[0], leftShoulder[1], leftShoulder[2]);
	glutSolidSphere(0.03, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightShoulder()
{
	glPushMatrix();
	glTranslated(rightShoulder[0], rightShoulder[1], rightShoulder[2]);
	glutSolidSphere(0.03, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftUpperArm()
{
	glPushMatrix();
	glTranslated(leftShoulder[0], leftShoulder[1], leftShoulder[2]);
	glRotated(leftUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(leftUpperArm[0] - leftShoulder[0], leftUpperArm[1] - leftShoulder[1], leftUpperArm[2] - leftShoulder[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	glRotated(10.0, 0.0, 1.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.01, 0.01, 0.1, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightUpperArm()
{
	glPushMatrix();
	glTranslated(rightShoulder[0], rightShoulder[1], rightShoulder[2]);
	glRotated(rightUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(rightUpperArm[0] - rightShoulder[0], rightUpperArm[1] - rightShoulder[1], rightUpperArm[2] - rightShoulder[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	glRotated(-10.0, 0.0, 1.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.01, 0.01, 0.1, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftElbow()
{
	glPushMatrix();
	glTranslated(leftShoulder[0], leftShoulder[1], leftShoulder[2]);
	glRotated(leftUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(leftElbow[0] - leftShoulder[0], leftElbow[1] - leftShoulder[1], leftElbow[2] - leftShoulder[2]);
	glutSolidSphere(0.025, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightElbow()
{
	glPushMatrix();
	glTranslated(rightShoulder[0], rightShoulder[1], rightShoulder[2]);
	glRotated(rightUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(rightElbow[0] - rightShoulder[0], rightElbow[1] - rightShoulder[1], rightElbow[2] - rightShoulder[2]);
	glutSolidSphere(0.025, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftLowerArm()
{
	glPushMatrix();
	glTranslated(leftShoulder[0], leftShoulder[1], leftShoulder[2]);
	glRotated(leftUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(leftElbow[0] - leftShoulder[0], leftElbow[1] - leftShoulder[1], leftElbow[2] - leftShoulder[2]);
	glRotated(leftLowerArmAngle, 1.0, 0.0, 0.0);
	glTranslated(leftLowerArm[0] - leftElbow[0], leftLowerArm[1] - leftElbow[1], leftLowerArm[2] - leftElbow[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.01, 0.01, 0.17, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightLowerArm()
{
	glPushMatrix();
	glTranslated(rightShoulder[0], rightShoulder[1], rightShoulder[2]);
	glRotated(rightUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(rightElbow[0] - rightShoulder[0], rightElbow[1] - rightShoulder[1], rightElbow[2] - rightShoulder[2]);
	glRotated(rightLowerArmAngle, 1.0, 0.0, 0.0);
	glTranslated(rightLowerArm[0] - rightElbow[0], rightLowerArm[1] - rightElbow[1], rightLowerArm[2] - rightElbow[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.01, 0.01, 0.17, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftHand()
{
	glPushMatrix();
	glTranslated(leftShoulder[0], leftShoulder[1], leftShoulder[2]);
	glRotated(leftUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(leftElbow[0] - leftShoulder[0], leftElbow[1] - leftShoulder[1], leftElbow[2] - leftShoulder[2]);
	glRotated(leftLowerArmAngle, 1.0, 0.0, 0.0);
	glTranslated(leftHand[0] - leftElbow[0], leftHand[1] - leftElbow[1], leftHand[2] - leftElbow[2]);
	glutSolidSphere(0.025, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightHand()
{
	glPushMatrix();
	glTranslated(rightShoulder[0], rightShoulder[1], rightShoulder[2]);
	glRotated(rightUpperArmAngle, 1.0, 0.0, 0.0);
	glTranslated(rightElbow[0] - rightShoulder[0], rightElbow[1] - rightShoulder[1], rightElbow[2] - rightShoulder[2]);
	glRotated(rightLowerArmAngle, 1.0, 0.0, 0.0);
	glTranslated(rightHand[0] - rightElbow[0], rightHand[1] - rightElbow[1], rightHand[2] - rightElbow[2]);
	glutSolidSphere(0.025, 100, 100);
	glPopMatrix();
}

void Skeleton::drawButtocks()
{
	glPushMatrix();
	glTranslated(0.0, 0.2, 0.0);
	glutSolidSphere(0.1, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftHip()
{
	glPushMatrix();
	glTranslated(leftHip[0], leftHip[1], leftHip[2]);
	glutSolidSphere(0.03, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightHip()
{
	glPushMatrix();
	glTranslated(rightHip[0], rightHip[1], rightHip[2]);
	glutSolidSphere(0.03, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftThigh()
{
	glPushMatrix();
	glTranslated(leftThigh[0], leftThigh[1], leftThigh[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.012, 0.012, 0.22, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightThigh()
{
	glPushMatrix();
	glTranslated(rightThigh[0], rightThigh[1], rightThigh[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.012, 0.012, 0.22, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftKnee()
{
	glPushMatrix();
	glTranslated(leftKnee[0], leftKnee[1], leftKnee[2]);
	glutSolidSphere(0.025, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightKnee()
{
	glPushMatrix();
	glTranslated(rightKnee[0], rightKnee[1], rightKnee[2]);
	glutSolidSphere(0.025, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftCalf()
{
	glPushMatrix();
	glTranslated(leftCalf[0], leftCalf[1], leftCalf[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.012, 0.012, 0.32, 100, 100);
	glPopMatrix();
}

void Skeleton::drawRightCalf()
{
	glPushMatrix();
	glTranslated(rightCalf[0], rightCalf[1], rightCalf[2]);
	glRotated(90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, 0.012, 0.012, 0.32, 100, 100);
	glPopMatrix();
}

void Skeleton::drawLeftAnkle()
{
	glPushMatrix();
	glPopMatrix();
}

void Skeleton::drawRightAnkle()
{
	glPushMatrix();
	glPopMatrix();
}

void Skeleton::drawLeftFoot()
{
	glPushMatrix();
	glPopMatrix();
}

void Skeleton::drawRightFoot()
{
	glPushMatrix();
	glPopMatrix();
}

void Skeleton::setTarget(GLdouble x, GLdouble y, GLdouble z)
{
	target[0] = 1.0;
	target[1] = leftHand[1];
	target[2] = 0;
	offset[0] = (leftHand[0] - target[0]) / 100;
}

void Skeleton::moveCameraLeft()
{
	glRotated(-cameraHorizontalSpeed, 0.0, 1.0, 0.0);
}

void Skeleton::moveCameraRight()
{
	glRotated(cameraHorizontalSpeed, 0.0, 1.0, 0.0);
}

void Skeleton::walk()
{
	if (armFlag) {
		leftUpperArmAngle += 8;
		rightUpperArmAngle -= 8;
		if (leftUpperArmAngle <= 40 && leftUpperArmAngle > 0) {
			leftLowerArmAngle += 10;
		}
		else {
			rightLowerArmAngle -= 10;
		}
		if (leftUpperArmAngle >= 40) {
			armFlag = false;
		}
	}
	else {
		leftUpperArmAngle -= 8;
		rightUpperArmAngle += 8;
		if (leftUpperArmAngle < 40 && leftUpperArmAngle >= 0) {
			leftLowerArmAngle -= 10;
		}
		else {
			rightLowerArmAngle += 10;
		}
		if (leftUpperArmAngle <= -40) {
			armFlag = true;
		}
	}
}
