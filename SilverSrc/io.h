#pragma once

#include <stdio.h>

int find_handle();
int file_length(FILE *file);
int file_open(char *path, int *handle);
void file_close(int handle);
void file_seek(int handle, int pos, int start);
int file_read(int handle, void *dst, int size);
