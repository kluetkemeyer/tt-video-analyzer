#include <GL/glut.h>
#include <math.h>

#include "scene.h"
#include "sceneViewRecord.h"
#include "global.h"

static
void renderQuadLine(int xSplines) {
    double stepX = 1.0 / xSplines;
    double x = -0.5;
    int i;

    glBegin(GL_TRIANGLE_STRIP);

    for (i = 0; i <= xSplines; ++i) {
        glVertex3f(x, 0.0, 0.0);
        glVertex3f(x, -1.0, 0.0);
        x += stepX;
    }

    glEnd();
}

static
void renderQuad(int xSplines, int ySplines) {
    int i;
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.0, 1.0/ySplines, 1.0);
    for(i=0; i<ySplines; ++i) {
        renderQuadLine(xSplines);
        glTranslatef(0.0, -1.0, 0.0);
    }
    glPopMatrix();
}

static
void renderCubeFront(int xSplines, int ySplines) {
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.5);
    renderQuad(xSplines, ySplines);
    glPopMatrix();
}

static
void renderCube(int xSplines, int ySplines, int zSplines) {
    glPushMatrix();
    
    // front
    renderCubeFront(xSplines, ySplines);
    
    // left side
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    renderCubeFront(zSplines, ySplines);
    
    // right side
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    renderCubeFront(xSplines, ySplines);
    
    // back side
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    renderCubeFront(zSplines, ySplines);
    
    // bottom
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    renderCubeFront(zSplines, xSplines);
    
    // top
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    renderCubeFront(zSplines, xSplines);
    
    
    glPopMatrix();
}

static
void renderTable(void) {

}

double angle = 0.0;
void renderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    //glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);
    
    

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(	20.0f*sin(angle), 2.0f, 20.0f*cos(angle),
                            0.0f, 1.0f,  0.0f,
                            0.0f, 1.0f,  0.0f);
    
    viewRecord_render(testRec);
    
    
    
    glColor3f(0.9, 0.9, 0.9);
    glRotatef(25.0, 1.0f, 0.0f, 0.0f);
    glScalef(2.0, 2.0, 2.0);
    renderCube(2, 3, 4);
    
    

    glutSwapBuffers();
    
    angle += 0.01;
    if (angle >= 2.0*M_PI) {
        angle -= 2.0*M_PI;
    }
}