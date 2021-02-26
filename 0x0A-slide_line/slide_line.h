#ifndef SLIDELINE_H
#define SLIDELINE_H

#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void slide_right(int *line, size_t size);
void slide_left(int *line, size_t size);

#endif
