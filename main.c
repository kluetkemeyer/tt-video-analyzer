/* 
 * File:   main.c
 * Author: Kilian Lütkemeyer <kilian@luetkemeyer.com>
 *
 * Created on 23. Februar 2015, 09:26
 */
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "scene.h"
#include "modelViewRecord.h"

#define KEY_ESCAPE 27

void
initSamples(void) {
    testRec = viewRecord_create3f(2, -4.5, 2.0, -2.0);

    viewRecord_setTestTargetf(testRec, 0, 0.0f, -1.0f, 0.0f);
    viewRecord_setTestTargetf(testRec, 1, 2.0f, -0.8f, 0.0f);
}

void keyboard(unsigned char key, int mousePositionX, int mousePositionY) {
    switch (key) {
        case KEY_ESCAPE:
            exit(0);
            break;

        default:
            break;
    }
}

void initialize(int width, int height) {
    // select projection matrix
    glMatrixMode(GL_PROJECTION);

    // set the viewport
    glViewport(0, 0, width, height);

    // set matrix mode
    glMatrixMode(GL_PROJECTION);

    // reset projection matrix
    glLoadIdentity();
    GLfloat aspect = (GLfloat) width / height;

    // set up a perspective projection matrix
    gluPerspective(45, aspect, 1.0f, 500.0f);

    // specify which matrix is the current matrix
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);

    // specify the clear value for the depth buffer
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // specify implementation-specific hints
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    GLfloat amb_light[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat diffuse[] = {0.6, 0.6, 0.6, 1};
    GLfloat specular[] = {0.7, 0.7, 0.3, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    
    initialize(w, h);
}

/*
 * 
 */
int main(int argc, char** argv) {


    // Init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Lighthouse3D- GLUT Tutorial");

    initSamples();
    initialize(320, 320);

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    // start process
    glutMainLoop();

    return 1;
}

