#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f); // Start point
        glVertex2f(0.5f, 0.5f);   // End point
        glVertex2f(0.5f, 0.5f); // Start point
        glVertex2f(0.5f, -0.5f);   // End point
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple 2D Line");
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

