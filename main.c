#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

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
    pthread_t triangle, circle;
    int s;

    s = pthread_create(&triangle, NULL, draw_triangle, NULL);

    if (s != 0)
        exit(1);

    s = pthread_create(&circle, NULL, draw_circle, NULL);

    if (s != 0)
        exit(2);

    pthread_join(triangle, NULL);
    pthread_join(circle, NULL);

    exit(0);
}

