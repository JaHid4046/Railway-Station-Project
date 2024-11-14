#include <windows.h>
#include <iostream>
#include<mmsystem.h>

#include <GL/glut.h>

#include<math.h>


GLfloat i = 0.0;
GLfloat position_car1x = 0.0;
GLfloat position_bus1x = 0.0;
GLfloat position_bus2x = 0.0;
GLfloat position_car1y = 0.0;
GLfloat position_bus1y = 0.0;
GLfloat position_bus2y = 0.0;
GLfloat position_train1x = 0.0;
GLfloat position_train2x = 0.0;
GLfloat position_cloud1x = 0.0;
GLfloat position_cloud2x = 0.0;
GLfloat position_cloud3x = 0.0;
GLfloat position_boat1x = 0.0;
GLfloat position_boat2x = 0.0;

GLfloat speed = 0.1;
GLfloat speed1 = 0.01;
GLfloat speed2 = 0.01;
GLfloat speedTrain = 0.03;
GLfloat speedBoat = 0.02;

# define PI    3.14159265358979323846
using namespace std;


void circle(float a, float b, float r)
{

    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x=a;
    GLfloat y=b;
    GLfloat radius =r;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}



void motion_vehicle(int value)
{
    /**....................................... (Jahid) ..........................................**/
    if(position_car1x < - 1.5)
        position_car1x = 1.5;

    if(position_bus1x < - 1.5)
        position_bus1x = 1.5;

    if(position_bus2x > 1.5)
        position_bus2x = -1.5;

    if(position_car1y >  0.2)
        position_car1y = - 0.1;

    if(position_bus1y >  0.2)
        position_bus1y = - 0.1;

    if(position_bus2y < - 0.2)
        position_bus2y =  0.1;

    if(position_train1x < -1.5)
        position_train1x = 1.5;

    if(position_train2x > 1.5)
        position_train2x = -1.5;

    if(position_cloud1x < - 1.5)
        position_cloud1x = 1.5;

    if(position_cloud2x > 1.5)
        position_cloud2x = -1.5;

    if(position_cloud3x > 1.5)
        position_cloud3x = -1.5;

    if(position_boat1x < - 1.5)
        position_boat1x = 1.5;

    if(position_boat2x > 1.5)
        position_boat2x = -1.5;

    position_car1x -= speed;
    position_bus1x -= speed;
    position_bus2x += speed;
    position_car1y +=speed1;
    position_bus1y +=speed1;
    position_bus2y -=speed1;
    position_train1x -= speedTrain;
    position_train2x += speedTrain;
    position_cloud1x -= speed2;
    position_cloud2x += speed2;
    position_cloud3x += speed2;
    position_boat1x -= speedBoat;
    position_boat2x += speedBoat;
    glutPostRedisplay();
    glutTimerFunc(100, motion_vehicle, 0);
}


void motion2_vehicle(int value)
{
    /**....................................... (Jahid) ..........................................**/
    if(position_car1x > 1.5)
        position_car1x = -1.5;

    if(position_bus1x > 1.5)
        position_bus1x = -1.5;

    if(position_bus2x < -1.5)
        position_bus2x = 1.5;

    if(position_car1y < - 0.2)
        position_car1y =  0.1;

    if(position_bus1y < - 0.2)
        position_bus1y = 0.1;

    if(position_bus2y >  0.2)
        position_bus2y = - 0.1;

    if(position_train1x > 1.5)
        position_train1x = -1.5;

    if(position_train2x < -1.5)
        position_train2x = 1.5;

    if(position_cloud1x >  1.5)
        position_cloud1x = -1.5;

    if(position_cloud2x < - 1.5)
        position_cloud2x = 1.5;

    if(position_cloud3x < - 1.5)
        position_cloud3x = 1.5;

    if(position_boat1x > 1.5)
        position_boat1x = -1.5;

    if(position_boat2x < -1.5)
        position_boat2x = 1.5;

    position_car1x += speed;
    position_bus1x += speed;
    position_bus2x -= speed;
    position_car1y -=speed1;
    position_bus1y -=speed1;
    position_bus2y +=speed1;
    position_train1x += speedTrain;
    position_train2x -= speedTrain;
    position_cloud1x += speed2;
    position_cloud2x -= speed2;
    position_cloud3x -= speed2;
    position_boat1x += speedBoat;
    position_boat2x -= speedBoat;

    glutPostRedisplay();
    glutTimerFunc(100, motion2_vehicle, 0);
}



void SpecialInput(int key, int x, int y)
{
    /**....................................... (Jahid) ..........................................**/
    switch(key)
    {
    case GLUT_KEY_UP:
        speed = speed + 0.01;
        speed1 = speed1 +0.001;
        speed2 = speed2 +0.001;
        speedTrain = speedTrain +0.003;
        speedBoat = speedBoat +0.002;
        break;

    case GLUT_KEY_DOWN:
        speed = speed - 0.01;
        speed1 = speed1 -0.001;
        speedTrain = speedTrain -0.003;
        speedBoat = speedBoat -0.002;



        break;

    case GLUT_KEY_LEFT:
        glutTimerFunc(100, motion_vehicle, 0);

        break;

    case GLUT_KEY_RIGHT:
        glutTimerFunc(100, motion2_vehicle, 0);

        break;


    case GLUT_KEY_INSERT:

        speedTrain = 0.0;

        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void initGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Idle()
{
    glutPostRedisplay();/// marks the current window as needing to be redisplayed
}

void sea()
{
    /**.......................................Sea (Amrin)..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(-1.0, 0.66);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(-1.0, 0.76);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(1.0, 0.76);
    glColor3f(0.49, 0.824, 0.871);
    glVertex2f(1.0, 0.55);
    glEnd();

    /**.......................................Sea Wave ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5, 0.68);
    glVertex2f(-.5, 0.689);
    glVertex2f(-0.36, 0.687);
    glVertex2f(-0.34, 0.686);
    glVertex2f(-0.56, 0.687);
    glVertex2f(-0.54, 0.686);
    glEnd();

    glPushMatrix();
    glTranslated(0.9f,-0.07f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5, 0.68);
    glVertex2f(-.5, 0.689);
    glVertex2f(-0.36, 0.687);
    glVertex2f(-0.34, 0.686);
    glVertex2f(-0.56, 0.687);
    glVertex2f(-0.54, 0.686);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f,0.05f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5, 0.68);
    glVertex2f(-.5, 0.689);
    glVertex2f(-0.36, 0.687);
    glVertex2f(-0.34, 0.686);
    glVertex2f(-0.56, 0.687);
    glVertex2f(-0.54, 0.686);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6f,0.06f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5, 0.68);
    glVertex2f(-.5, 0.689);
    glVertex2f(-0.36, 0.687);
    glVertex2f(-0.34, 0.686);
    glVertex2f(-0.56, 0.687);
    glVertex2f(-0.54, 0.686);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99, 0.7);
    glVertex2f(-0.85, 0.71);
    glVertex2f(-0.79, 0.7);
    glVertex2f(-0.87, 0.71);
    glVertex2f(-0.88, 0.7);
    glVertex2f(-0.93, 0.7);
    glVertex2f(-1.1, 0.69);
    glEnd();

    glPushMatrix();
    glTranslated(0.7f,-0.03f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99, 0.7);
    glVertex2f(-0.85, 0.71);
    glVertex2f(-0.79, 0.7);
    glVertex2f(-0.87, 0.71);
    glVertex2f(-0.88, 0.7);
    glVertex2f(-0.93, 0.7);
    glVertex2f(-1.1, 0.69);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f,0.02f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99, 0.7);
    glVertex2f(-0.85, 0.71);
    glVertex2f(-0.79, 0.7);
    glVertex2f(-0.87, 0.71);
    glVertex2f(-0.88, 0.7);
    glVertex2f(-0.93, 0.7);
    glVertex2f(-1.1, 0.69);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.6f,-0.08f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99, 0.7);
    glVertex2f(-0.85, 0.71);
    glVertex2f(-0.79, 0.7);
    glVertex2f(-0.87, 0.71);
    glVertex2f(-0.88, 0.7);
    glVertex2f(-0.93, 0.7);
    glVertex2f(-1.1, 0.69);
    glEnd();
    glPopMatrix();

}

void beach()
{
    /**....................................... Beach Sand (Amrin) ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.58, 0.404, 0.298);
    glVertex2f(-1.0, 0.65);
    glColor3f(0.882, 0.714, 0.522);
    glVertex2f(-1.0, 0.66);
    glColor3f(0.58, 0.404, 0.298);
    glVertex2f(1.0, 0.55);
    glColor3f(0.882, 0.714, 0.522);
    glVertex2f(1.0, 0.48);
    glEnd();

}

void sky()
{
    /**.......................................Sky(Amrin) ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.831, 0.949);
    glVertex2f(-1.0, 0.76);
    glColor3f(0.478, 0.78, 0.925);
    glVertex2f(-1.0, 1.0);
    glColor3f(0.478, 0.78, 0.925);
    glVertex2f(1.0, 1.0);
    glColor3f(0.576, 0.831, 0.949);
    glVertex2f(1.0, 0.76);
    glEnd();

}

void sun ()
{
    /**.......................................Sun(Amrin)...........................................**/

    GLfloat x=0.7f;
    GLfloat y=0.85f;
    GLfloat radius =0.055f;
    int triangleAmount = 100; //# of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 0.680f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

        glColor3f(1.0f, 1.0f, 0.0f);
    }
    glEnd();


}

void sun_shadow()
{
    glColor3f(1.0f, 1.0f, 0.680f);
    circle(0.7,0.68,0.055);
}

void cloud1()
{
    /**........................................Cloud Middle(Amrin)..........................................**/
    glPushMatrix();
    glTranslated(position_cloud1x,0.0f,0.0f);
    glPushMatrix();
    glTranslated(0.0f, 0.05f, 0.0f);
    GLfloat x=0.0;
    GLfloat y=0.88;
    GLfloat radius =0.04;
    int  triangleAmount = 100;
    GLfloat twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.05;
    y=0.88;
    radius =0.04;
    twicePi =2.0 * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.05;
    y=0.88;
    radius =0.04;
    twicePi =2.0 * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.04;
    y=0.92;
    radius =0.03;
    twicePi =2.0 * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.013;
    y=0.85;
    radius =0.03;
    twicePi =2.0 * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.053;
    y=0.85;
    radius =0.036;
    twicePi =2.0 * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void cloud2()
{
    /**........................................Cloud Left(Amrin)...........................................**/
    glPushMatrix();
    glTranslated(position_cloud2x,0.0f,0.0f);
    GLfloat x=-0.5f;
    GLfloat y=0.85f;
    GLfloat radius =.058f;
    int  triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.57f;
    y=0.85f;
    radius =.037f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.43f;
    y=0.85f;
    radius =.04f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.55f;
    y=0.86f;
    radius =.03f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.61f;
    y=0.85f;
    radius =.02f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.39f;
    y=0.85f;
    radius =.02f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }

    glEnd();
    glPopMatrix();
}

void cloud3()
{
    /**........................................Cloud Right(Amrin)...........................................**/
    glPushMatrix();
    glTranslated(position_cloud3x,0.0f,0.0f);
    GLfloat x=0.45f;
    GLfloat y=0.85f;
    GLfloat radius =.035f;
    int  triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),

                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    x=0.48f;
    y=0.85f;
    radius =.03f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.42f;
    y=0.85f;
    radius =.028f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
}

void road()
{

    /**.......................................Road(Tamanna) ..........................................**/
    /**....................................... Road color  ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.301, 0.355, 0.35);
    glVertex2f(-1.0f, 0.65f);
    glColor3f(0.301, 0.33, 0.35);
    glVertex2f(1.0f, 0.48f);
    glColor3f(0.302, 0.32, 0.32);
    glVertex2f(1.0f, 0.3f);
    glColor3f(0.301, 0.355, 0.35);
    glVertex2f(-1.0f, 0.55f);
    glEnd();
    /**....................................... Side Divider  ..........................................**/
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-1.0f, 0.64f);
    glVertex2f(1.0f, 0.47f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-1.0f, 0.56f);
    glVertex2f(1.0f, 0.31f);
    glEnd();

    /**....................................... Divider  ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();
    /**....................................... Continuous Road divider  ..........................................**/
    glPushMatrix();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.019f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.015f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.015f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.015f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glTranslated(0.175f,-0.018f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.92f, 0.59f);
    glEnd();

    glPopMatrix();
}

void car()
{
    /**....................................... Car (Tamanna) ..........................................**/
    glPushMatrix();
    glTranslated(position_car1x,position_car1y,0.0f);

    glTranslated(-0.9f,0.4f,0.0f);
    glScalef(0.5f,0.5f,0.0f);

    glBegin(GL_QUADS);
    glColor3f(1,0.5,0);
    glVertex2f(1.125,0.375);
    glVertex2f(0.8,0.395);
    glVertex2f(0.8,0.35);
    glVertex2f(1.125,0.325);

    glColor3f(0,0,0);
    glVertex2f(0.9,0.425);
    glVertex2f(0.85,0.415);
    glVertex2f(1.125,0.375);
    glVertex2f(1.05,0.425);

    glColor3f(1,0.5,0);
    glVertex2f(1.115,0.375);
    glVertex2f(1.115,0.325);
    glVertex2f(1.205,0.315);
    glVertex2f(1.215,0.35);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0);
    glVertex2f(0.8,0.395);
    glVertex2f(0.85,0.415);
    glVertex2f(1.125,0.375);
    glEnd();


    /**....................................... Car Tire 1  ..........................................**/

    GLfloat x=0.865f;
    GLfloat y=0.35f;
    GLfloat radius =.03f;
    int triangleAmount = 100; //# of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.865f;
    y=0.35f;
    radius =.008f;
    triangleAmount = 100; //# of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    /**....................................... Car Tire 2  ..........................................**/
    x=1.1f;
    y=0.325f;
    radius =.03f;
    triangleAmount = 100; //# of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=1.1f;
    y=0.325f;
    radius =.008f;
    triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

}

void bus1()
{
    ///*---------------------------------------Bus 1 (Tamanna)-------------------------------------*///
    glPushMatrix();
    glTranslated(position_bus1x,position_bus1y,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.3f, 0.6f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.625f, 0.575f);
    glColor3f(0.753, 0.792, 0.82);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.625f, 0.475f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.3f, 0.5f);
    glColor3f(0.196, 0.66, 0.64);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.45, 0.69);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.625f, 0.550f);
    glVertex2f(0.3f, 0.575f);

    glVertex2f(0.3f, 0.550f);
    glVertex2f(0.625f, 0.525f);
    glVertex2f(0.625f, 0.475f);
    glVertex2f(0.3f, 0.5f);

    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.29f, 0.5f);
    glVertex2f(0.29f, 0.6f);

    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.655f, 0.545f);
    glVertex2f(0.655f, 0.475f);
    glVertex2f(0.625f, 0.475f);

    glColor3f(0.35, 0.55, 0.79);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.665f, 0.58f);
    glVertex2f(0.695f, 0.55f);
    glVertex2f(0.655f, 0.545f);

    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.665f, 0.58f);
    glVertex2f(0.33f, 0.605f);
    glVertex2f(0.29f, 0.6f);

    glVertex2f(0.655f, 0.545f);
    glVertex2f(0.655f, 0.475f);
    glVertex2f(0.695f, 0.48f);
    glVertex2f(0.695f, 0.55f);

    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.66f, 0.54f);
    glVertex2f(0.66f, 0.51f);
    glVertex2f(0.69f, 0.515f);
    glVertex2f(0.69f, 0.545f);
    glEnd();
    /**....................................... Bus 1 Tire 1 ..........................................**/
    GLfloat x=0.350f;
    GLfloat y=0.5f;
    GLfloat radius =.02f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.350f;
    y=0.5f;
    radius =.008f;
    triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    /**....................................... Bus 1 Tire 2  ..........................................**/
    x=0.575f;
    y=0.475f;
    radius =.02f;
    triangleAmount = 100; //# of lines used to draw circle

    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.575f;
    y=0.475f;
    radius =.008f;
    triangleAmount = 100; //# of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    /**....................................... Bus 1 Window  ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glPushMatrix();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();


    ///.....................................................................

    glPopMatrix();



    glPopMatrix();
    glPopMatrix();
    ///...............................................

    glPopMatrix();


}

void bus2()
{
    ///*-------------------------------------------Bus 2(Tamanna)-------------------------------------------------*///

    glPushMatrix();
    glPushMatrix();
    glTranslated(position_bus2x,position_bus2y,0.0f);
    //glScalef(0.2,0.0,0.0);
    glTranslated(0.4f,-0.13f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.3f, 0.6f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.625f, 0.575f);
    glColor3f(0.753, 0.792, 0.82);
    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.625f, 0.475f);
    glColor3f(0.753, 0.792, 0.82);
    glVertex2f(0.3f, 0.5f);
    glColor3f(0.196, 0.66, 0.64);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.8, 0.89);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.625f, 0.550f);
    glVertex2f(0.3f, 0.575f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.8, 0.89);
    glVertex2f(0.3f, 0.550f);
    glVertex2f(0.625f, 0.525f);
    glVertex2f(0.625f, 0.475f);
    glVertex2f(0.3f, 0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.625f, 0.575f);
    glVertex2f(0.64f, 0.575f);
    glVertex2f(0.64f, 0.475f);
    glVertex2f(0.625f, 0.475f);

    glColor3f(0.35, 0.9, 0.99);
    glVertex2f(0.64f, 0.575f);
    glVertex2f(0.69f, 0.58f);
    glVertex2f(0.69f, 0.48f);
    glVertex2f(0.64f, 0.475f);

    glColor3f(0.196, 0.66, 0.64);
    glVertex2f(0.645f, 0.563f);
    glVertex2f(0.685f, 0.568f);
    glVertex2f(0.685f, 0.53f);
    glVertex2f(0.645f, 0.525f);

    glColor3f(0.35, 0.9, 0.99);
    glVertex2f(0.64f, 0.573f);
    glVertex2f(0.69f, 0.58f);
    glVertex2f(0.35f, 0.605f);
    glVertex2f(0.3f, 0.6f);

    glColor3f(0.25, 0.8, 0.89);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.28f, 0.57f);
    glVertex2f(0.28f, 0.5f);
    glVertex2f(0.3f, 0.5f);
    glEnd();

    /**....................................... Bus 2 Tire 1  ..........................................**/
    GLfloat x=0.350f;
    GLfloat y=0.5f;
    GLfloat radius =.02f;
    int triangleAmount = 100; //# of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.350f;
    y=0.5f;
    radius =.008f;
    triangleAmount = 100; //# of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    /**....................................... Bus 2 Tire 2  ..........................................**/
    x=0.575f;
    y=0.475f;
    radius =.02f;
    triangleAmount = 100; //# of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.575f;
    y=0.475f;
    radius =.008f;
    triangleAmount = 100; //# of lines used to draw circle
    twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    /**....................................... Bus 2 Windows  ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glPushMatrix();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.002f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();
    glTranslated(0.025f,-0.0021f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.325f, 0.575f);
    glVertex2f(0.325f, 0.548f);
    glEnd();

    /**....................................... Bus 2 Door  ..........................................**/
    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.89, 0.886, 0.871);
    glVertex2f(0.285f, 0.575f);
    glVertex2f(0.31f, 0.574f);
    glVertex2f(0.31f, 0.5f);
    glVertex2f(0.285f, 0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.285f, 0.575f);
    glVertex2f(0.31f, 0.5f);
    glEnd();
    glPopMatrix();


    glPopMatrix();

}

void hills()
{
    /**....................................... Hills(Tamanna) ..........................................**/

    /**....................................... Hill 1 ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.192, 0.459, 0.192);
    glVertex2f(-0.902f, 0.582f);
    glVertex2f(-0.846f, 0.621f);
    glVertex2f(-0.867f, 0.670f);
    glVertex2f(-0.789f, 0.711f);
    glVertex2f(-0.765f, 0.805f);
    glVertex2f(-0.686f, 0.724f);
    glVertex2f(-0.659f, 0.716f);
    glVertex2f(-0.635f, 0.659f);
    glVertex2f(-0.588f, 0.621f);
    glVertex2f(-0.576f, 0.542f);
    glVertex2f(-0.549f, 0.556f);
    glVertex2f(-0.498f, 0.482f);
    glVertex2f(-0.412f, 0.221f);
    glVertex2f(-0.917f, 0.221f);
    glEnd();

    /**....................................... Hill 1 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.791f, 0.714f);
    glVertex2f(-0.763f, 0.742f);
    glVertex2f(-0.776f, 0.761f);
    glVertex2f(-0.744f, 0.756f);
    glVertex2f(-0.713f, 0.718f);
    glVertex2f(-0.746f, 0.722f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.744f, 0.756f);
    glVertex2f(-0.746f, 0.722f);
    glVertex2f(-0.736f, 0.663f);
    glVertex2f(-0.83f, 0.631f);
    glVertex2f(-0.78f, 0.666f);
    glVertex2f(-0.815f, 0.679f);
    glVertex2f(-0.815f, 0.679f);
    glVertex2f(-0.767f, 0.716f);
    glVertex2f(-0.791f, 0.714f);
    glEnd();

    glPushMatrix();
    glTranslated(0.15f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);
    glEnd();
    glPopMatrix();

    /**....................................... Hill 2  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.161, 0.4, 0.169);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.685f);
    glVertex2f(-0.94f, 0.633f);
    glVertex2f(-0.944f, 0.624f);
    glVertex2f(-0.928f, 0.624f);
    glVertex2f(-0.925f, 0.635f);
    glVertex2f(-0.895f, 0.571f);
    glVertex2f(-0.872f, 0.568f);
    glVertex2f(-0.854f, 0.555f);
    glVertex2f(-0.855f, 0.547f);
    glVertex2f(-0.804f, 0.491f);
    glVertex2f(-0.807f, 0.448f);
    glVertex2f(-0.786f, 0.458f);
    glVertex2f(-0.764f, 0.468f);
    glVertex2f(-0.758f, 0.443f);
    glVertex2f(-0.738f, 0.44f);
    glVertex2f(-0.719f, 0.379f);
    glVertex2f(-0.681f, 0.32f);
    glVertex2f(-0.641f, 0.286f);
    glVertex2f(-0.624f, 0.245f);
    glVertex2f(-0.583f,0.22f);
    glEnd();

    /**....................................... Hill 2 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.982f, 0.436f);
    glVertex2f(-0.979f, 0.470f);
    glVertex2f(-0.938f, 0.485f);
    glVertex2f(-0.928f, 0.5224f);
    //glVertex2f(-0.905f, 0.506f);
    glVertex2f(-0.941f, 0.471f);
    glVertex2f(-0.943f, 0.447f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);

    glEnd();

    /**....................................... Hill 3  ..........................................**/

    glPushMatrix();

    glTranslated(0.25f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.357, 0.02);

    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-0.903f, 0.468f);
    glVertex2f(-0.889f, 0.465f);
    glVertex2f(-0.835f, 0.555f);
    glVertex2f(-0.816f, 0.594f);
    glVertex2f(-0.759f, 0.547f);
    glVertex2f(-0.758f, 0.557f);
    glVertex2f(-0.724f, 0.521f);
    glVertex2f(-0.7f, 0.526f);
    glVertex2f(-0.697f, 0.503f);
    glVertex2f(-0.661f, 0.482f);
    glVertex2f(-0.66f, 0.475f);
    glVertex2f(-0.64f, 0.474f);
    glVertex2f(-0.559f, 0.354f);
    glVertex2f(-0.528f, 0.347f);
    glVertex2f(-0.462f, 0.218f);
    glEnd();
    glPopMatrix();

    /**....................................... Hill 3 Shadow  ..........................................**/

    glPushMatrix();
    glTranslated(0.1f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.692f, 0.326f);
    glVertex2f(-0.68f, 0.346f);
    glVertex2f(-0.696f, 0.362f);
    glVertex2f(-0.665f, 0.415f);
    glVertex2f(-0.68f, 0.448f);
    glVertex2f(-0.652f, 0.441f);
    glVertex2f(-0.629f, 0.432f);
    glVertex2f(-0.640f, 0.408f);
    glVertex2f(-0.665f, 0.376f);
    glVertex2f(-0.636f, 0.395f);
    glVertex2f(-0.617f, 0.339f);
    glVertex2f(-0.592f, 0.323f);
    glVertex2f(-0.597f, 0.274f);
    glVertex2f(-0.521f, 0.263f);
    glVertex2f(-0.544f, 0.227f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslated(0.2f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(-0.92f, 0.36f);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.74f, 0.44f);
    glVertex2f(-0.76f, 0.44f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.76f, 0.36f);
    glVertex2f(-0.74f, 0.34f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.9f, 0.26f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.46f,-0.1f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.967f, 0.514f);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.949f, 0.588f);
    glVertex2f(-0.929f, 0.601f);
    glVertex2f(-0.922f, 0.558f);
    glVertex2f(-0.933f, 0.522f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.56f,-0.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.952f, 0.546f);
    glVertex2f(-0.971f, 0.553f);
    glVertex2f(-0.972f, 0.5694f);
    glVertex2f(-0.990f, 0.581f);
    glVertex2f(-0.979f, 0.642f);
    glVertex2f(-0.96f, 0.632f);
    glVertex2f(-0.949f, 0.588f);

    glEnd();
    glPopMatrix();



    /**....................................... Hill 4  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.412, 0.102);
    glVertex2f(-1.0f, 0.22f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-0.903f, 0.468f);
    glVertex2f(-0.889f, 0.465f);
    glVertex2f(-0.835f, 0.555f);
    glVertex2f(-0.816f, 0.594f);
    glVertex2f(-0.759f, 0.547f);
    glVertex2f(-0.758f, 0.557f);
    glVertex2f(-0.724f, 0.521f);
    glVertex2f(-0.7f, 0.526f);
    glVertex2f(-0.697f, 0.503f);
    glVertex2f(-0.661f, 0.482f);
    glVertex2f(-0.66f, 0.475f);
    glVertex2f(-0.64f, 0.474f);
    glVertex2f(-0.559f, 0.354f);
    glVertex2f(-0.528f, 0.347f);
    glVertex2f(-0.462f, 0.218f);
    glEnd();

    /**....................................... Hill 4 Shadow  ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.98f, 0.26f);
    glVertex2f(-0.92f, 0.36f);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.74f, 0.44f);
    glVertex2f(-0.76f, 0.44f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.76f, 0.36f);
    glVertex2f(-0.74f, 0.34f);
    glVertex2f(-0.88f, 0.3f);
    glVertex2f(-0.9f, 0.26f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.835f, 0.52f);
    glVertex2f(-0.822f, 0.527f);
    glVertex2f(-0.821f, 0.545f);
    glVertex2f(-0.815f, 0.544f);
    glVertex2f(-0.792f, 0.554f);
    glVertex2f(-0.786f, 0.533f);
    glVertex2f(-0.803f, 0.528f);
    glVertex2f(-0.818f, 0.511f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.122, 0.714, 0.114);
    glVertex2f(-0.692f, 0.326f);
    glVertex2f(-0.68f, 0.346f);
    glVertex2f(-0.696f, 0.362f);
    glVertex2f(-0.665f, 0.415f);
    glVertex2f(-0.68f, 0.448f);
    glVertex2f(-0.652f, 0.441f);
    glVertex2f(-0.629f, 0.432f);
    glVertex2f(-0.640f, 0.408f);
    glVertex2f(-0.665f, 0.376f);
    glVertex2f(-0.636f, 0.395f);
    glVertex2f(-0.617f, 0.339f);
    glVertex2f(-0.592f, 0.323f);
    glVertex2f(-0.597f, 0.274f);
    glVertex2f(-0.521f, 0.263f);
    glVertex2f(-0.544f, 0.227f);
    glEnd();
}

void station()
{
    /**....................................... Station(Jahid) ..........................................**/
    glBegin(GL_QUADS);

    //Platform
    glColor3ub(105,105,105);
    glVertex2f(-0.34,0.3);
    glVertex2f(0.34,0.3);
    glVertex2f(0.54,0.2);
    glVertex2f(-0.54,0.2);

    glColor3ub(69,69,69);
    glVertex2f(0.54,0.2);
    glVertex2f(-0.54,0.2);
    glVertex2f(-0.54,0.17);
    glVertex2f(0.54,0.17);


    glColor3ub(160,82,45);
    //1st Floor Siling
    glVertex2f(-0.32,0.31);
    glVertex2f(0.32,0.31);
    glVertex2f(0.22,0.34);
    glVertex2f(-0.22,0.34);

    //1st floor
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(-0.3,0.25);
    glVertex2f(0.3,0.25);
    glVertex2f(0.3,0.31);
    glVertex2f(-0.3,0.31);

    //3rd floor siling
    glColor3ub(139,69,19);
    glVertex2f(0,0.50);
    glVertex2f(-0.14,0.44);
    glVertex2f(0,0.3);
    glVertex2f(0,0.3);

    glVertex2f(0,0.50);
    glVertex2f(0.14,0.44);
    glVertex2f(0,0.3);
    glVertex2f(0,0.3);

    //2nd floor
    glColor3f(0.25f, 0.0f, 0.0f);
    glVertex2f(-0.2,0.25);
    glVertex2f(0.2,0.25);
    glVertex2f(0.2,0.38);
    glVertex2f(-0.2,0.38);

    //2nd Floor Siling
    glColor3ub(160,82,45);
    glVertex2f(-0.12,0.41);
    glVertex2f(0.12,0.41);
    glVertex2f(0.22,0.38);
    glVertex2f(-0.22,0.38);

    //3rd floor
    glColor3f(0.3f, 0.0f, 0.0f);
    glVertex2f(-0.1,0.25);
    glVertex2f(0.1,0.25);
    glVertex2f(0.1,0.44);
    glVertex2f(-0.1,0.44);

    glEnd();

    //3rd floor upper
    glBegin(GL_TRIANGLES);
    glVertex2f(0,0.48);
    glVertex2f(0.1,0.44);
    glVertex2f(-0.1,0.44);

    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //3rd floor window
    for(float i=0.0; i<0.1; i+=0.05)
    {
        glVertex2f(-0.04+i,0.40);
        glVertex2f(-0.01+i,0.40);
        glVertex2f(-0.01+i,0.44);
        glVertex2f(-0.04+i,0.44);
    }

    //2nd floor window left
    for(float i=0.0; i<=0.04; i+=0.04)
    {
        glVertex2f(-0.18+i,0.36);
        glVertex2f(-0.15+i,0.36);
        glVertex2f(-0.15+i,0.32);
        glVertex2f(-0.18+i,0.32);
    }

    //2nd floor window right
    for(float i=0.0; i<=0.04; i+=0.04)
    {
        glVertex2f(0.11+i,0.36);
        glVertex2f(0.14+i,0.36);
        glVertex2f(0.14+i,0.32);
        glVertex2f(0.11+i,0.32);
    }

    //2nd floor window middle
    for(float i=0.0; i<=0.15; i+=0.05)
    {
        glVertex2f(-0.07+i,0.365);
        glVertex2f(-0.035+i,0.365);
        glVertex2f(-0.035+i,0.315);
        glVertex2f(-0.07+i,0.315);
    }

    //1sr floor window left back
    for(float i=0.0; i<=0.04; i+=0.04)
    {
        glVertex2f(-0.28+i,0.265);
        glVertex2f(-0.25+i,0.265);
        glVertex2f(-0.25+i,0.295);
        glVertex2f(-0.28+i,0.295);
    }

    //1sr floor window right back
    for(float i=0.0; i<=0.04; i+=0.04)
    {
        glVertex2f(0.21+i,0.265);
        glVertex2f(0.24+i,0.265);
        glVertex2f(0.24+i,0.295);
        glVertex2f(0.21+i,0.295);
    }

    //1st floor window left
    for(float i=0.0; i<=0.04; i+=0.04)
    {
        glVertex2f(-0.18+i,0.265);
        glVertex2f(-0.15+i,0.265);
        glVertex2f(-0.15+i,0.295);
        glVertex2f(-0.18+i,0.295);
    }

    //1st floor window right
    for(float i=0.0; i<=0.04; i+=0.04)
    {
        glVertex2f(0.11+i,0.265);
        glVertex2f(0.14+i,0.265);
        glVertex2f(0.14+i,0.295);
        glVertex2f(0.11+i,0.295);
    }

    //1st floor window middle
    for(float i=0.0; i<=0.1; i+=0.07)
    {
        glVertex2f(-0.06+i,0.26);
        glVertex2f(-0.02+i,0.26);
        glVertex2f(-0.02+i,0.30);
        glVertex2f(-0.06+i,0.30);
    }


    glEnd();

}

void rail_Line()
{
    /**....................................... Rail Line Stone(Jahid) ..........................................**/
    glBegin(GL_QUADS);
    ///    Upper
    glColor3f(0.537, 0.569, 0.592);
    glVertex2f(-1.0f, 0.03f);
    glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.09f);
    glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.09f);
    glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.03f);
    ///     lower
    glColor3f(0.537, 0.569, 0.592);
    glVertex2f(-1.0f, 0.11f);
    glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.17f);
    glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.17f);
    glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.11f);
    glEnd();

    /**....................................... Rail Line Soil ..........................................**/
    glBegin(GL_QUADS);
    ///      Middle
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(-1.0f, 0.09f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(-1.0f, 0.11f);
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(1.0f, 0.11f);
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(1.0f, 0.09f);
    ///    Lower
    glColor3f(0.855, 0.686, 0.4940);
    glVertex2f(-1.0f, 0.0f);
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(-1.0f, 0.03f);
    glColor3f(0.322, 0.22, 0.188);
    glVertex2f(1.0f, 0.03f);
    glColor3f(0.663, 0.447, 0.29);
    glVertex2f(1.0f, 0.00f);
    ///    Upper
    glColor3f(0.678, 0.467, 0.294);
    glVertex2f(-1,0.2);
    glVertex2f(-0.54,0.2);
    glVertex2f(-0.54,0.17);
    glVertex2f(-1,0.17);

    glVertex2f(1,0.2);
    glVertex2f(0.54,0.2);
    glVertex2f(0.54,0.17);
    glVertex2f(1,0.17);

    glVertex2f(-1,0.2);
    glVertex2f(-0.54,0.2);
    glVertex2f(-0.5,0.22);
    glVertex2f(-1,0.22);

    glVertex2f(1,0.2);
    glVertex2f(0.54,0.2);
    glVertex2f(0.5,0.22);
    glVertex2f(1,0.22);

    glEnd();



    /**....................................... Rail Line ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    ///     Lower Line
    glVertex2f(-1.0f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    glVertex2f(-1.0f, 0.08f);
    glVertex2f(1.0f, 0.08f);
    ///     Upper Line
    glVertex2f(-1.0f, 0.12f);
    glVertex2f(1.0f, 0.12f);
    glVertex2f(-1.0f, 0.16f);
    glVertex2f(1.0f, 0.16f);
    glEnd();

    /**....................................... Lower Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-1.01f, 0.04f);
    glVertex2f(-0.98f, 0.08f);

    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);

    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.04f);
    glVertex2f(-0.94f, 0.08f);
    glEnd();

    glPopMatrix();

    /**....................................... Upper Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-1.01f, 0.12f);
    glVertex2f(-0.98f, 0.16f);

    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();

    glPopMatrix();

}

void tree1()///small tree
{
    /**....................................... (Amrin) ..........................................**/
    /**....................................... Small Tree (right) ..........................................**/

    /**....................................... Small Tree (right) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (right) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    /**....................................... Small Tree (Left) ..........................................**/
    glPushMatrix();
    glTranslated(-1.1f,0.0f,0.0f);
    /**....................................... Small Tree (Left) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (Left) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    glPopMatrix();

}

void tree2()
{
    /**....................................... (Tamanna) ..........................................**/
    /**....................................... Big Tree (Right) ..........................................**/

    /**....................................... Big Tree (Right) Stem ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();




    /**....................................... Big Tree (Left) ..........................................**/



    /**....................................... Big Tree (Left) Stem ..........................................**/

    glPushMatrix();
    glTranslated(-1.7f,-0.02f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();
    glPopMatrix();



}

void tree_leaf1()
{
    /**....................................... (Amrin) ..........................................**/
    /**....................................... Big Tree (Right) Top Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.695,0.457,0.055);

    /**....................................... Big Tree (Right) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);


    /**....................................... Big Tree (Right) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);
    glPopMatrix();


}


void tree_leaf2()
{
    /**....................................... (Tamanna) ..........................................**/
    /**....................................... Big Tree (Left) Top Leaf ..........................................**/
    glPushMatrix();
    glTranslated(-1.7f,-0.02f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.695,0.457,0.055);

    /**....................................... Big Tree (Left) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);


    /**....................................... Big Tree (Left) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    circle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    circle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    circle(0.881,0.408,0.03);

    glPopMatrix();


    glPopMatrix();

}

void train1()
{
    /**....................................... Train(Jahid) ..........................................**/
    /**....................................... Train 1 ..........................................**/
    glPushMatrix();
    glTranslatef(position_train1x, 0.0f, 0.0f);
    ///Wheel of the train(Right Side);
    GLfloat x=0.12f;
    GLfloat  y=0.14f;
    GLfloat  radius =.022f;
    int triangleAmount = 100; ///# of lines used to draw circle
    GLfloat twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///Wheel of the train(Left Side);
    x=-0.01f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    /**....................................... Train 1 Cabin ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.227f, 0.4f, 0.259f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();
    ///Cabin(Front);
    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Head);
    x=-0.01f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Passenger_Head)
    x=0.11f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    glPushMatrix();
    glTranslated(-0.24f,0.0f,0.0f);
    x=0.12f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///Wheel of the train(Left Side);
    x=-0.01f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.227f, 0.4f, 0.259f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Head);
    x=-0.01f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Passenger_Head)
    x=0.11f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    glTranslated(-0.24f,0.0f,0.0f);
    x=0.12f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///Wheel of the train(Left Side);
    x=-0.01f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.227f, 0.4f, 0.259f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.114f, 0.251f, 0.141f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();
    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Head);
    x=-0.01f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Passenger_Head)
    x=0.11f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();
    /**....................................... Train 1 Engine ..........................................**/

    ///First wheel of left side;
    x=0.22f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Seocond wheel of Left side;
    x=0.27f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///First wheel of Right side;
    x=0.45f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///Second wheel of Right side;
    x=0.415f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.839f, 0.467f, 0.114f);
    glVertex2f(0.19f, 0.14f);
    glVertex2f(0.19f, 0.25f);
    glVertex2f(0.22f, 0.28f);
    glVertex2f(0.27f, 0.28f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.50f, 0.27f);
    glVertex2f(0.50f, 0.17f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.17f, 0.14f);
    glEnd();

    ///Back of the engine(Front);
    glBegin(GL_QUADS);
    glColor3f(0.839f, 0.294f, 0.114f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.25f, 0.15f);
    glEnd();

    ///Back of the engine(Front_Upper);
    glBegin(GL_QUADS);
    glColor3f(0.839f, 0.294f, 0.114f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.27f, 0.28f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.25f, 0.25f);
    glEnd();

    ///Front of the engine(Front);
    glBegin(GL_POLYGON);
    glColor3f(0.839f, 0.294f, 0.114f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.48f, 0.25f);
    glVertex2f(0.50f, 0.27f);
    glVertex2f(0.50f, 0.17f);
    glEnd();

    ///Front of the engine(Back_Step);
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.816f, 0.451f);
    glVertex2f(0.19f, 0.20f);
    glVertex2f(0.19f, 0.23f);
    glVertex2f(0.24f, 0.23f);
    glVertex2f(0.24f, 0.20f);
    glEnd();

    ///Front of the engine(Stape);
    glBegin(GL_QUADS);
    glColor3f(0.722f, 0.714f, 0.322f);
    glVertex2f(0.24f, 0.20f);
    glVertex2f(0.24f, 0.23f);
    glVertex2f(0.25f, 0.24f);
    glVertex2f(0.25f, 0.21f);
    glEnd();

    ///Front of the engine(Stape);
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.816f, 0.451f);
    glVertex2f(0.25f, 0.21f);
    glVertex2f(0.25f, 0.24f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.21f);
    glEnd();

    ///Front of the engine(Stape_Front);
    glBegin(GL_QUADS);
    glColor3f(0.722f, 0.714f, 0.322f);
    glVertex2f(0.48f, 0.21f);
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.50f, 0.25f);
    glVertex2f(0.50f, 0.23f);
    glEnd();

    ///Front of the engine(Side Black Side);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.14f);
    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.48f, 0.15f);
    glVertex2f(0.47f, 0.14f);
    glEnd();

    ///Front of the engine(Side Black Side(Upper));
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glVertex2f(0.46f, 0.24f);
    glVertex2f(0.46f, 0.19f);
    glEnd();

    ///Back of the Engine(Window)......................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.195f, 0.18f);
    glVertex2f(0.195f, 0.22f);
    glVertex2f(0.235f, 0.22f);
    glVertex2f(0.235f, 0.18f);
    glEnd();

    ///1st Engine Driver(Window)......................................................
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.195f, 0.18f);
    glVertex2f(0.195f, 0.19f);
    glVertex2f(0.205f, 0.19f);
    glVertex2f(0.215f, 0.18f);
    glVertex2f(0.195f, 0.18f);
    glEnd();

    ///1st Engine(Driver_Head);
    x=0.205f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    ///Front of the engine(Side Black Side(White line));
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glPushMatrix();
    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();

    glTranslated(0.01f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(0.38f, 0.19f);
    glVertex2f(0.38f, 0.24f);
    glEnd();


    glPopMatrix();
    glPopMatrix();
    ///End Of the train-1..................................................................
}

void train2()
{
    /**....................................... Train 2 (Jahid)..........................................**/
    glPushMatrix();
    glTranslatef(position_train2x, 0.0f, 0.0f);
    glPushMatrix();
    glTranslated(0.1f,-0.08f,0.0f);
    GLfloat x=0.12f;
    GLfloat y=0.14f;
    GLfloat  radius =.022f;
    int triangleAmount = 100; ///# of lines used to draw circle
    GLfloat twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///Wheel of the train(Left Side);

    x=-0.01f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.102f, 0.18f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Head);
    x=-0.01f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Passenger_Head)
    x=0.11f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    glTranslated(-0.24f,0.00f,0.0f);
    x=0.12f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Wheel of the train(Left Side);
    x=-0.01f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.102f, 0.18f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Head);
    x=-0.01f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Body)
    glBegin(GL_POLYGON);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(0.10f, 0.18f);
    glVertex2f(0.12f, 0.18f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.10f, 0.18f);
    glEnd();

    ///Right Window(Passenger_Passenger_Head)
    x=0.11f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    glTranslated(-0.24f,0.00f,0.0f);
    x=0.12f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Wheel of the train(Left Side);
    x=-0.01f;
    y=0.14f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.227f, 0.333f);
    glVertex2f(-0.05f, 0.14f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(-0.02f, 0.28f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glVertex2f(0.16f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.02f, 0.102f, 0.18f);
    glVertex2f(0.16f, 0.14f);
    glVertex2f(0.16f, 0.25f);
    glVertex2f(0.19f, 0.28f);
    glVertex2f(0.19f, 0.17f);
    glEnd();

    ///Left Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.22f);
    glVertex2f(0.02f, 0.22f);
    glVertex2f(0.02f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Body);
    glBegin(GL_QUADS);
    glColor3f(0.471f, 0.227f, 0.58f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.19f);
    glVertex2f(-0.01f, 0.19f);
    glVertex2f(0.0f, 0.18f);
    glEnd();

    ///Left Window(Passenger_Head);
    x=-0.01f;
    y=0.20f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    ///Right Window(Cabin);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.08f, 0.22f);
    glVertex2f(0.12f, 0.22f);
    glVertex2f(0.12f, 0.18f);
    glEnd();
    glPopMatrix();



    /**....................................... Train 2 Engine ..........................................**/

    ///Wheel of the 2nd engine(1st right side)
    x=-0.49f;
    y=0.06f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Wheel of the 2nd engine(2nd right side)
    x=-0.53f;
    y=0.06f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Wheel of the 2nd engine(1st left side)
    x=-0.66f;
    y=0.06f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Wheel of the 2nd engine(1st left side)
    x=-0.70f;
    y=0.06f;
    radius =.022f;
    triangleAmount = 100; ///# of lines used to draw circle
    twicePi =2.0f * PI;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Polygon of second engine.............................................
    glBegin(GL_POLYGON);
    glColor3f(0.671f, 0.369f, 0.259f);
    glVertex2f(-0.46f, 0.06f);
    glVertex2f(-0.46f, 0.17f);
    glVertex2f(-0.43f, 0.20f);
    glVertex2f(-0.50f, 0.20f);
    glVertex2f(-0.51f, 0.19f);
    glVertex2f(-0.70f, 0.19f);
    glVertex2f(-0.73f, 0.16f);
    glVertex2f(-0.73f, 0.07f);
    glVertex2f(-0.54f, 0.07f);
    glVertex2f(-0.53f, 0.06f);
    glVertex2f(-0.46f, 0.06f);
    glEnd();

    ///Back Of The Engine.......................................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.46f, 0.06f);
    glVertex2f(-0.46f, 0.17f);
    glVertex2f(-0.43f, 0.20f);
    glVertex2f(-0.43f, 0.10f);
    glEnd();

    ///Upper Rooftoof of the Engine...............................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.73f, 0.16f);
    glVertex2f(-0.70f, 0.19f);
    glVertex2f(-0.51f, 0.19f);
    glVertex2f(-0.54f, 0.16f);
    glEnd();

    ///2nd Train left side design...........................................
    glBegin(GL_QUADS);
    glColor3f(0.663f, 0.235f, 0.141f);
    glVertex2f(-0.55f, 0.07f);
    glVertex2f(-0.55f, 0.16f);
    glVertex2f(-0.53f, 0.17f);
    glVertex2f(-0.53f, 0.06f);
    glEnd();



    ///2nd Train engine front of the black...........................................
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.72f, 0.06f);
    glVertex2f(-0.73f, 0.07f);
    glVertex2f(-0.54f, 0.07f);
    glVertex2f(-0.53f, 0.06f);
    glEnd();

    ///Front engine yellow design........................................................
    glBegin(GL_QUADS);
    glColor3f(0.769f, 0.702f, 0.576f);
    glVertex2f(-0.73f, 0.12f);
    glVertex2f(-0.73f, 0.15f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.55f, 0.12f);
    glEnd();

    ///Front engine yellow design(Back side)........................................................
    glBegin(GL_QUADS);
    glColor3f(0.741f, 0.62f, 0.51f);
    glVertex2f(-0.55f, 0.12f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.53f, 0.14f);
    glVertex2f(-0.53f, 0.11f);
    glEnd();

    ///Back engine yellow design(Back Left side)................................
    glBegin(GL_QUADS);
    glColor3f(0.769f, 0.702f, 0.576f);
    glVertex2f(-0.53f, 0.11f);
    glVertex2f(-0.53f, 0.14f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.46f, 0.11f);
    glEnd();

    ///Back of the engine yellow design(Back side)........................................................
    glBegin(GL_QUADS);
    glColor3f(0.741f, 0.62f, 0.51f);
    glVertex2f(-0.46f, 0.11f);
    glVertex2f(-0.46f, 0.14f);
    glVertex2f(-0.43f, 0.16f);
    glVertex2f(-0.43f, 0.13f);
    glEnd();

    ///Back of the Engine(Window)......................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.52f, 0.10f);
    glVertex2f(-0.52f, 0.14f);
    glVertex2f(-0.48f, 0.14f);
    glVertex2f(-0.48f, 0.10f);
    glEnd();

    ///2nd Engine Driver
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.50f, 0.10f);
    glVertex2f(-0.49f, 0.11f);
    glVertex2f(-0.48f, 0.11f);
    glVertex2f(-0.48f, 0.10f);
    glVertex2f(-0.50f, 0.10f);
    glEnd();

    ///2ndEngine Window(Passenger_Head);
    x=-0.49f;
    y=0.12f;
    radius =.01f;
    triangleAmount = 100; ///# of lines used to draw circle

    twicePi =2.0f * PI;

    glColor3f(0.902f, 0.714f, 0.475f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 1.0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///Front of the engine side black design........................................................
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glVertex2f(-0.64f, 0.15f);
    glVertex2f(-0.64f, 0.10f);
    glEnd();

    ///Front of the engine side black design(Outside Line)........................................................
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();

    glTranslated(0.005f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.561f, 0.553f, 0.384f);
    glVertex2f(-0.71f, 0.10f);
    glVertex2f(-0.71f, 0.15f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}


void station_grass()
{
    /**....................................... Grass (Jahid)..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(-1.0f, 0.22f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(-1.0f, 0.55f);
    glColor3f(0.643, 0.753, 0.227);
    glVertex2f(1.0f, 0.3f);
    glColor3f(0.271, 0.463, 0.043);
    glVertex2f(1.0f, 0.22f);
    glEnd();
}

void road2()
{
    /**....................................... (Tamanna) ..........................................**/
    /**....................................... Station Road ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.301, 0.33, 0.35);
    glVertex2f(0.43f, 0.39f);

    glVertex2f(0.64f, 0.39f);

    glVertex2f(0.0f, 0.22f);
    glVertex2f(-0.1f, 0.22f);
    glEnd();
    /**....................................... Side Divider  ..........................................**/
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-0.1f, 0.22f);
    glVertex2f(0.42f, 0.383f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.0f, 0.22f);
    glVertex2f(0.51f, 0.36f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.902, 0.831, 0.235);
    glVertex2f(0.37f, 0.345f);
    glVertex2f(0.44f, 0.365f);
    glEnd();
}

void busStand()
{
    /**....................................... (Tamanna) ..........................................**/
    /**................................Bus stand.................................**/

    /**...............................Stand right.......................**/


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.341, 0.356, 0.375);
    glVertex2f(0.55f, 0.515f);
    glVertex2f(0.55f, 0.63f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.56f);
    glEnd();

    /**...............................Stand left.......................**/
    glPushMatrix();
    glTranslated(-0.2f, 0.0f, 0.0f);
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.341, 0.356, 0.375);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.63f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.55f, 0.52f);
    glVertex2f(0.55f, 0.56f);
    glEnd();
    glPopMatrix();

    /**...................................Shade..........................**/

    GLfloat x=0.363f;
    GLfloat  y=0.63f;
    GLfloat  radius =0.041f;
    int triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(0.600f, 0.616f, 0.651f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.443f;
    y=0.63f;
    radius =0.06f;
    twicePi =1.0f * PI;
    glColor3f(0.600f, 0.616f, 0.651f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.523f;
    y=0.63f;
    radius =0.041f;
    twicePi =1.0f * PI;
    glColor3f(0.600f, 0.616f, 0.651f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glColor3f(1.0,0.0,0.0);
    renderBitmapString(0.42f, 0.65f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, " Bus Stand ");


    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.32f, 0.63f);
    glVertex2f(0.58f, 0.63f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.35f, 0.59f);
    glVertex2f(0.55f, 0.59f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.35f, 0.575f);
    glVertex2f(0.55f, 0.575f);
    glEnd();

    /**.........................................Glass.................................................**/

    glBegin(GL_QUADS);
    glColor3f(0.784, 0.882, 0.961);
    glVertex2f(0.36f, 0.62f);
    glVertex2f(0.36f, 0.545f);
    glVertex2f(0.54f, 0.545f);
    glVertex2f(0.54f, 0.62f);
    glEnd();

    /**...................................................Glass Shade.............................................**/

    glBegin(GL_QUADS);
    glColor3f(0.749, 0.863, 0.969);
    glVertex2f(0.36f, 0.545f);
    glVertex2f(0.36f, 0.565f);
    glVertex2f(0.42f, 0.62f);
    glVertex2f(0.44f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.749, 0.863, 0.969);
    glVertex2f(0.4f, 0.545f);
    glVertex2f(0.42f, 0.545f);
    glVertex2f(0.5f, 0.62f);
    glVertex2f(0.48f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.749, 0.863, 0.969);
    glVertex2f(0.54f, 0.62f);
    glVertex2f(0.54f, 0.6f);
    glVertex2f(0.48f, 0.545f);
    glVertex2f(0.46f, 0.545f);
    glEnd();

    /**...........................................Bench...................................................**/

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.39f, 0.53f);
    glVertex2f(0.4f, 0.53f);
    glVertex2f(0.4f, 0.55f);
    glVertex2f(0.39f, 0.55f);
    glEnd();

    glPushMatrix();
    glTranslated(0.11f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.39f, 0.52f);
    glVertex2f(0.4f, 0.52f);
    glVertex2f(0.4f, 0.55f);
    glVertex2f(0.39f, 0.55f);
    glEnd();
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.39f, 0.55f);
    glVertex2f(0.39f, 0.59f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.43f, 0.55f);
    glVertex2f(0.43f, 0.59f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.47f, 0.55f);
    glVertex2f(0.47f, 0.59f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.51f, 0.55f);
    glVertex2f(0.51f, 0.59f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.375f, 0.55f);
    glVertex2f(0.525f, 0.55f);
    glVertex2f(0.525f, 0.555f);
    glVertex2f(0.375f, 0.555f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.38f, 0.558f);
    glVertex2f(0.52f, 0.558f);
    glVertex2f(0.52f, 0.568f);
    glVertex2f(0.38f, 0.568f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.38f, 0.571f);
    glVertex2f(0.52f, 0.571f);
    glVertex2f(0.52f, 0.581f);
    glVertex2f(0.38f, 0.581f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.871, 0.592, 0.184);
    glVertex2f(0.38f, 0.584f);
    glVertex2f(0.52f, 0.584f);
    glVertex2f(0.52f, 0.594f);
    glVertex2f(0.38f, 0.594f);
    glEnd();
}

void boat1()
{
    /**....................................... (Amrin) ..........................................**/
    /**.......................................Boat 1 ..........................................**/

    glPushMatrix();
    glTranslated(position_boat1x,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.463, 0.486, 0.502);
    glVertex2f(-0.38f, 0.76f);
    glVertex2f(-0.16f, 0.76f);
    glVertex2f(-0.19f, 0.747f);
    glVertex2f(-0.35f, 0.747f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.969, 0.49);
    glVertex2f(-0.26f, 0.83f);
    glVertex2f(-0.33f, 0.77f);
    glVertex2f(-0.26f, 0.77f);

    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3f(0.988f, 0.961f, 0.149f);
    glVertex2f(-0.26f, 0.86f);
    glVertex2f(-0.22f, 0.77f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.26f, 0.84f);
    glVertex2f(-0.26f, 0.76f);

    glEnd();
    glPopMatrix();


}


void boat2()
{
    /**....................................... (Amrin) ..........................................**/
    /**.......................................Boat 2 ..........................................**/

    glPushMatrix();
    glTranslated(position_boat2x,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.525, 0.286, 0.282);
    glVertex2f(0.6f, 0.71f);
    glVertex2f(0.36f, 0.71f);
    glVertex2f(0.39f, 0.69f);
    glVertex2f(0.57f, 0.69f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.58, 0.122);
    glVertex2f(0.48f, 0.78f);
    glVertex2f(0.56f, 0.72f);
    glVertex2f(0.48f, 0.72f);

    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.961, 0.58, 0.122);
    glVertex2f(0.48f, 0.82f);
    glVertex2f(0.44f, 0.72f);
    glVertex2f(0.48f, 0.71f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.48f, 0.79f);
    glVertex2f(0.48f, 0.71f);

    glEnd();
    glPopMatrix();
}


void information(void)
{
    /**....................................... (Jahid) ..........................................**/
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f);

    glColor3f(1.0,0.0,0.0);
    renderBitmapString(-0.1f,0.91f, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Railway Station Project");
    renderBitmapString(-0.14,0.86, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Computer Graphics Sessional");
    renderBitmapString(-0.88,0.82, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Group Member :");
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.88, 0.8);
    glVertex2f(0.88,0.8);
    glEnd();
    renderBitmapString(-0.78,0.75, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ID");
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.85, 0.74);
    glVertex2f(-0.67,0.74);
    glEnd();
    renderBitmapString(0.3,0.75, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Name");
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.11, 0.74);
    glVertex2f(0.59,0.74);
    glEnd();

    renderBitmapString(-0.84,0.7, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20104009");
    renderBitmapString(0.13, 0.7, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Amrin Nahar");

    renderBitmapString(-0.84, 0.65, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20104040");
    renderBitmapString(0.13, 0.65, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MD. Jahid Hasan");

    renderBitmapString(-0.84, 0.6, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20104055");
    renderBitmapString(0.13, 0.6, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Sadia Haq Tamanna");

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.88,0.55);
    glVertex2f(0.88, 0.55);
    glEnd();

    renderBitmapString(-0.1,0.5, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Supervised by :");
    renderBitmapString(-0.19,0.45, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mst. Irin Sultana, Lecturer");
    renderBitmapString(-0.19,0.4, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Md. Atikur Rahman, Lecturer");
    renderBitmapString(-0.34,0.35, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Department of Computer Science and Engineering");
    renderBitmapString(-0.45,0.3, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Bangladesh Army University of Engineering & Tecnology (BAUET)");
    glFlush();

}

void day()
{
    /**....................................... (Jahid) ..........................................**/
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    sea();
    beach();
    sky();
    sun();
    sun_shadow();
    cloud1();
    cloud2();
    cloud3();
    busStand();
    road();
    station_grass();
    road2();
    car();
    bus1();
    bus2();
    boat1();
    boat2();
    hills();
    station();
    rail_Line();
    tree1();
    tree_leaf1();
    tree_leaf2();
    tree2();
    train1();
    train2();




    i+=0.2f;


    glFlush(); /// Render now
}


void sea2()
{
    /**....................................... (Amrin) ..........................................**/
    /**.......................................Sea ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.633, 0.765, 0.831);
    glVertex2f(-1.0f, 0.66f);
    glColor3f(0.075, 0.18, 0.251);

    glVertex2f(-1.0f, 0.76f);
    glColor3f(0.075, 0.18, 0.251);
    glVertex2f(1.0f, 0.80f);

    glColor3f(0.633, 0.765, 0.831);
    glVertex2f(1.0f, 0.55f);
    glEnd();


    /**.......................................Sea Wave ..........................................**/
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();

    glPushMatrix();
    glTranslated(0.9f,-0.07f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f,0.05f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6f,0.06f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-.5f, 0.689f);
    glVertex2f(-0.36f, 0.687f);
    glVertex2f(-0.34f, 0.686f);
    glVertex2f(-0.56f, 0.687f);
    glVertex2f(-0.54f, 0.686f);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();

    glPushMatrix();
    glTranslated(0.7f,-0.03f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.4f,0.02f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.6f,-0.08f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.431, 0.769, 0.824);
    glVertex2f(-0.99f, 0.7f);
    glVertex2f(-0.85f, 0.71f);
    glVertex2f(-0.79f, 0.7f);
    glVertex2f(-0.87f, 0.71f);
    glVertex2f(-0.88f, 0.7f);
    glVertex2f(-0.93f, 0.7f);
    glVertex2f(-1.1f, 0.69f);
    glEnd();
    glPopMatrix();


}

void sky2()
{

/**....................................... (Amrin) ..........................................**/
    /**.......................................Sky ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.322, 0.494, 0.560);
    glVertex2f(-1.0f, 0.76f);

    glColor3f(0.086, 0.2, 0.31);
    glVertex2f(-1.0f, 1.0f);

    glColor3f(0.086, 0.2, 0.31);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.322, 0.494, 0.560);
    glVertex2f(1.0f, 0.76f);

    glColor3f(0.318, 0.490, 0.554);
    glVertex2f(1.0f, 0.762f);
    glEnd();

}

void night()
{
    /**....................................... (Jahid) ..........................................**/
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glColor3f(0.633, 0.765, 0.831);

    sea2();
    beach();
    sky2();
    sun();
    glColor3ub(158, 161, 163);
    glPushMatrix();
    glScalef(0.7,0.7,0.0);
    glTranslated(0.0f,0.55,0.0);

    glPopMatrix();

    road();
    busStand();
    station_grass();
    road2();
    car();
    bus1();
    bus2();
    boat1();
    boat2();
    hills();
    station();
    rail_Line();
    tree1();
    tree_leaf1();
    tree_leaf2();
    tree2();
    train1();
    train2();
    glPushMatrix();

    glTranslated(0.0f,1.0f,0.0f);

    glLoadIdentity();

    glPopMatrix();



    i+=0.2f;


    glFlush(); /// Render now
}

void myKeyboard(unsigned char key, int x, int y)
{
    /**....................................... (Jahid) ..........................................**/
    switch (key)
    {

    case 'h':

        glutDisplayFunc(information);
        glutPostRedisplay();

        break;

    case 'd':

        glutDisplayFunc(day);

        glutPostRedisplay();


        ///PlaySound("horn.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;

    case 'n':

        glutDisplayFunc(night);

        glutPostRedisplay();

        break;



    default:
        break;
    }

    if(key=='1')
    {
        sndPlaySound("train.wav", SND_ASYNC);
    }

    if(key=='2')
    {
        sndPlaySound("bus.wav", SND_ASYNC);

    }
}


void init (void)
{
    /// initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

/** Main function: GLUT runs as a console application starting at main() **/
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1520, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Railway Station. ");

    init ();

    glutDisplayFunc(information);/// Register display callback handler for window re-paint
    glutKeyboardFunc(myKeyboard);
    glutIdleFunc(Idle);
    glutSpecialFunc(SpecialInput);

    glutMainLoop();///Enter the event-processing loop
    return 0;
}



