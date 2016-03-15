#include "io.h"

#define MAX_HANDLES 64

FILE *handles[MAX_HANDLES];

int find_handle()
{
	int i;
	for (i = 0; i < MAX_HANDLES; i++)
	{
		if (!handles[i])
			return i;
	}
	return -1;
}

int file_length(FILE *file)
{
	int pos;
	int end;

	pos = ftell(file);
	fseek(file, 0, SEEK_END);
	end = ftell(file);
	fseek(file, pos, SEEK_SET);

	return end;
}

int file_open(char *path, int *handle)
{
	FILE *file;
	int i, retval;

	i = find_handle();

	fopen_s(&file, path, "rb");

	if (!file)
	{
		*handle = -1;
		retval = -1;
	}
	else
	{
		handles[i] = file;
		*handle = i;
		retval = file_length(file);
	}

	return retval;
}

void file_close(int handle)
{
	fclose(handles[handle]);
	handles[handle] = NULL;
}

void file_seek(int handle, int pos, int start)
{
	fseek(handles[handle], pos, start);
}

int file_read(int handle, void *dst, int size)
{
	return fread(dst, 1, size, handles[handle]);
}