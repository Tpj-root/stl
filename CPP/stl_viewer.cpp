#include <GL/glut.h>
#include <fstream>
#include <vector>
#include <iostream>

struct Vec3 {
    float x, y, z;
};

struct Triangle {
    Vec3 normal;
    Vec3 vertex1;
    Vec3 vertex2;
    Vec3 vertex3;
};

std::vector<Triangle> triangles;

void loadSTL(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Cannot open file\n";
        return;
    }

    char header[80];
    file.read(header, 80);

    uint32_t numTriangles;
    file.read(reinterpret_cast<char*>(&numTriangles), 4);

    for (uint32_t i = 0; i < numTriangles; ++i) {
        Triangle tri;
        file.read(reinterpret_cast<char*>(&tri.normal), sizeof(Vec3));
        file.read(reinterpret_cast<char*>(&tri.vertex1), sizeof(Vec3));
        file.read(reinterpret_cast<char*>(&tri.vertex2), sizeof(Vec3));
        file.read(reinterpret_cast<char*>(&tri.vertex3), sizeof(Vec3));
        file.ignore(2); // attribute byte count
        triangles.push_back(tri);
    }

    file.close();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(50, 50, 100, 0, 0, 0, 0, 1, 0);

    glBegin(GL_TRIANGLES);
    for (const auto& tri : triangles) {
        glNormal3f(tri.normal.x, tri.normal.y, tri.normal.z);
        glVertex3f(tri.vertex1.x, tri.vertex1.y, tri.vertex1.z);
        glVertex3f(tri.vertex2.x, tri.vertex2.y, tri.vertex2.z);
        glVertex3f(tri.vertex3.x, tri.vertex3.y, tri.vertex3.z);
    }
    glEnd();

    glutSwapBuffers();
}

void initOpenGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    GLfloat light_pos[] = {50, 50, 100, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Add in initOpenGL()

}

int main(int argc, char** argv) {
    loadSTL("toy3mm.stl"); // Replace with your STL file path

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Binary STL Viewer");
    initOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
