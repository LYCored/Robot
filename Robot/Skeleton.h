#pragma once
#include <GL/glut.h>
class Skeleton
{
public:
	Skeleton();
	~Skeleton();
	void draw();
	void drawHead();
	void drawBody();
	void drawLeftShoulder();
	void drawRightShoulder();
	void drawLeftUpperArm();
	void drawRightUpperArm();
	void drawLeftElbow();
	void drawRightElbow();
	void drawLeftLowerArm();
	void drawRightLowerArm();
	void drawLeftHand();
	void drawRightHand();
	void drawButtocks();
	void drawLeftHip();
	void drawRightHip();
	void drawLeftThigh();
	void drawRightThigh();
	void drawLeftKnee();
	void drawRightKnee();
	void drawLeftCalf();
	void drawRightCalf();
	void drawLeftAnkle();
	void drawRightAnkle();
	void drawLeftFoot();
	void drawRightFoot();
	void setTarget(GLdouble x, GLdouble y, GLdouble z);
	void moveCameraLeft();
	void moveCameraRight();
	void walk();
private:
	GLdouble leftShoulder[3];
	GLdouble rightShoulder[3];
	GLdouble leftUpperArm[3];
	GLdouble rightUpperArm[3];
	GLdouble leftElbow[3];
	GLdouble rightElbow[3];
	GLdouble leftLowerArm[3];
	GLdouble rightLowerArm[3];
	GLdouble leftHand[3];
	GLdouble rightHand[3];
	GLdouble leftHip[3];
	GLdouble rightHip[3];
	GLdouble leftThigh[3];
	GLdouble rightThigh[3];
	GLdouble leftKnee[3];
	GLdouble rightKnee[3];
	GLdouble leftCalf[3];
	GLdouble rightCalf[3];
	GLdouble target[3];
	GLdouble offset[3];
	GLdouble cameraHorizontalSpeed;
	GLdouble leftUpperArmAngle;
	GLdouble leftLowerArmAngle;
	GLdouble rightUpperArmAngle;
	GLdouble rightLowerArmAngle;
	GLdouble leftThighAngle;
	GLdouble rightThighAngle;
	GLdouble leftTCalfAngle;
	GLdouble rightCalfAngle;
	bool armFlag;
};

