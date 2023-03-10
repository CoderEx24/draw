#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

void* draw_triangle()
{
    printf("I should draw a triangle\n");

    return NULL;
}

void* draw_circle()
{
    printf("I should draw a circle\n");

    return NULL;
}

int main(int argc, char *argv[])
{
    if (!glfwInit())
        exit(-1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 700, "draw - CSC221 Project", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }
    
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress))
    {
        glfwTerminate();
        exit(-1);
    }

    glViewport(0, 0, 800, 700);

    pthread_t triangle, circle;
    int s;

    s = pthread_create(&triangle, NULL, draw_triangle, NULL);

    if (s != 0)
        exit(1);

    s = pthread_create(&circle, NULL, draw_circle, NULL);

    if (s != 0)
        exit(2);

    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
                glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    pthread_join(triangle, NULL);
    pthread_join(circle, NULL);

    glfwTerminate();
    exit(0);
}

