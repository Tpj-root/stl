// hilbert_opengl2.cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>

void hilbert(int level, float x0, float y0, float xi, float xj, float yi, float yj,
             std::vector<float>& pts) {
    if (level <= 0) {
        float x = x0 + (xi + yi) / 2;
        float y = y0 + (xj + yj) / 2;
        pts.push_back(x);
        pts.push_back(y);
    } else {
        hilbert(level - 1, x0,               y0,             yi/2, yj/2, xi/2, xj/2, pts);
        hilbert(level - 1, x0 + xi/2,        y0 + xj/2,      xi/2, xj/2, yi/2, yj/2, pts);
        hilbert(level - 1, x0 + xi/2 + yi/2, y0 + xj/2 + yj/2, xi/2, xj/2, yi/2, yj/2, pts);
        hilbert(level - 1, x0 + xi/2 + yi,   y0 + xj/2 + yj, -yi/2,-yj/2,-xi/2,-xj/2, pts);
    }
}

int main(){
    glfwInit();
    GLFWwindow* w = glfwCreateWindow(600,600,"Hilbert",NULL,NULL);
    glfwMakeContextCurrent(w);
    glewInit();

    int level = 1;
    while (!glfwWindowShouldClose(w)) {
        glClear(GL_COLOR_BUFFER_BIT);
        if (glfwGetKey(w, GLFW_KEY_UP) == GLFW_PRESS && level < 10) level++;
        if (glfwGetKey(w, GLFW_KEY_DOWN) == GLFW_PRESS && level > 1) level--;

        std::vector<float> pts;
        hilbert(level, -1,-1, 2,0, 0,2, pts);
        glColor3f(1,0.5f,0);
        glBegin(GL_LINE_STRIP);
            for (int i = 0; i + 1 < pts.size(); i += 2)
                glVertex2f(pts[i], pts[i+1]);
        glEnd();

        glfwSwapBuffers(w);
        glfwPollEvents();
    }
    glfwTerminate();
}
