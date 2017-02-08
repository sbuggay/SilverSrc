#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pak.h"
#include "io.h"

int pak_handle = 0;
pak_t paks[MAX_PAK];

int pak_load(char *file_name)  {

	unsigned int handle, size;
	if (size = file_open(file_name, &handle) == -1) {
		printf("no file %s\n", file_name);
		return -1;
	}
		
	pakheader_t header;
	file_read(handle, &header, sizeof(pakheader_t));

	// Verify PAK signiture
	if (header.magic[0] != 'P' ||
		header.magic[1] != 'A' ||
		header.magic[2] != 'C' ||
		header.magic[3] != 'K')
		return -1;

	int num_entries = header.size / sizeof(pakentry_t);

	file_seek(handle, header.offset, 0);

	strcpy_s(paks[pak_handle].name, 256, file_name);
	paks[pak_handle].handle = handle;
	paks[pak_handle].count = num_entries;
	paks[pak_handle].data = malloc(sizeof(pakentry_t) * num_entries);
	file_read(handle, paks[pak_handle].data, sizeof(pakentry_t) * num_entries);

	printf("Loaded pak %s@%d\n", paks[pak_handle].name, paks[pak_handle].handle);

	return pak_handle++;
}

int pak_data(char *file_name, uint8_t **dst) {
	// Start with the last loaded pak first
	// This could be done with a linked list
	int i, j;
	for (i = pak_handle - 1; i >= 0; i--) {
		for (j = 0; j < paks[i].count; j++) {
			pakentry_t *data = paks[i].data;
			printf("%s / ", data[j].name);
			if (strcmp(data[j].name, file_name) == 0) {
				printf("%s@%d %db\n", data[j].name, data[j].offset, data[j].size);
				file_seek(paks[i].handle, data[j].offset, 0);
				uint8_t *buffer = malloc(data[j].size);
				
				file_read(paks[i].handle, buffer, data[j].size);

				*dst = buffer;
				return data[j].size;
			}
		}
	}
	return 0;
}

pakpicture_t *pak_load_pic(char *file_name) {
	uint8_t *data = NULL;
	pak_data(file_name, &data);

	if (!data)
		return NULL;

	pakpicture_t *pic = malloc(sizeof(pakpicture_t));

	memcpy(&pic->width, data, sizeof(int));
	memcpy(&pic->height, data + 4, sizeof(int));
	pic->data = malloc(pic->width * pic->height);
	memcpy(pic->data, data + 8, pic->width * pic->height);

	return pic;
}