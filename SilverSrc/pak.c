#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pak.h"

FILE *file;

int num_entries;
pakentry_t entries[MAX_PAK_ENTRIES];

void pak_load(char *file_name)
{
	
	fopen_s(&file, file_name, "r");

	pakheader_t header;
	fread(&header, sizeof(pakheader_t), 1, file);

	if (header.magic[0] != 'P' ||
		header.magic[1] != 'A' ||
		header.magic[2] != 'C' ||
		header.magic[3] != 'K')
		return;

	num_entries = header.size / sizeof(pakentry_t);

	fseek(file, header.offset, 0);

	fread((void *)entries, sizeof(pakentry_t), num_entries, file);
}

unsigned char *pak_data(char *file_name)
{
	int i;
	for (i = 0; i < num_entries; i++)
	{
		if (strcmp(entries[i].name, file_name) == 0)
		{
			printf("%s@%d[%d]\n", entries[i].name, entries[i].offset, entries[i].size);
			fseek(file, entries[i].offset, 0);
			unsigned char *data = malloc(entries[i].size);
			fread((char *)data, entries[i].size, 1, file);
			return data;
		}
			
	}

	return NULL;
}

pakpicture_t *pak_load_pic(char *file_name)
{
	unsigned char *data = pak_data(file_name);

	pakpicture_t *pic = malloc(sizeof(pakpicture_t));

	memcpy(&pic->width, data, sizeof(int));
	memcpy(&pic->height, data + 4, sizeof(int));
	pic->data = malloc(pic->width * pic->height);
	memcpy(pic->data, data + 8, pic->width * pic->height);

	return pic;
}