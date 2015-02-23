#include <GL/glut.h>
#include <GL/glu.h>
#include "sceneViewRecord.h"

static void
renderMarker() {
    GLUquadric *quad = gluNewQuadric();
    if (quad != NULL) {
        gluSphere(quad, 0.1, 5, 5);
        gluDeleteQuadric(quad);
    }
}

#define STEP_COUNT 5

void
viewRecord_render(ViewRecord* record) {
    int i, j;
    double *dir;
    double step[3];
    if (record == NULL) return;
    
    // draw cam
    glPushMatrix();
    glTranslated(record->cam[0], record->cam[1], record->cam[2]);
    glColor3f(1.0, 0.0, 0.0);
    renderMarker();
    glPopMatrix();
    
    dir = record->points;
    for(i=0; i<2*record->pointCount; ++i, dir+=3) {
        glPushMatrix();
        glTranslated(record->cam[0], record->cam[1], record->cam[2]);
        
        // init pos and step
        for(j=0; j<3; ++j) {
            step[j] = dir[j] / STEP_COUNT;
        }
        
        // draw
        for(j=0; j<STEP_COUNT; ++j) {
            glBegin(GL_LINES);
            glColor3f(0.0f, 1.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(step[0], step[1], step[2]);
            glEnd();
            
            glTranslatef(step[0], step[1], step[2]);
            glColor3f(0.4f, 0.0f, 0.0f);
            renderMarker();
        }
      glPopMatrix(); 
    }   
}
