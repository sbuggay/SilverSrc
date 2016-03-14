#pragma once

#include "mathlib.h"

#define MAX_PAK_ENTRIES 2048

void *pak;

typedef struct
{
	char	name[256];
	int		handle;
} pak_t;

typedef struct
{
	char	magic[4];
	int		offset;
	int		size;
} pakheader_t;

typedef struct
{
	char	name[0x38];
	int		offset;
	int		size;
} pakentry_t;

typedef struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} pakpalette_t[256];

typedef struct
{
	int width;
	int height;
	unsigned char *data;
} pakpicture_t;

typedef struct
{
	int		id;				// 0x4F504449 = "IDPO" for IDPOLYGON
	int		version;		// Version = 6
	vec3_t	scale;			// Model scale factors.
	vec3_t	origin;			// Model origin.
	float	radius;			// Model bounding radius.
	vec3_t	offsets;		// Eye position (useless?)
	int		numskins;		// the number of skin textures
	int		skinwidth;		// Width of skin texture
	int		skinheight;		// Height of skin texture
	int		numverts;		// Number of vertices
	int		numtris;		// Number of triangles surfaces
	int		numframes;		// Number of frames
	int		synctype;		// 0= synchron, 1= random
	int		flags;			// 0 (see Alias models)
	float	size;			// average size of triangles
} mdl_t;

void pak_load(char *file_name);
unsigned char *pak_data(char *file_name);
pakpicture_t *pak_load_pic(char *file_name);