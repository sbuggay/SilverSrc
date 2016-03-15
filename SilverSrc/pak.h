#pragma once

#include <stdint.h>

#define MAX_PAK 32
#define MAX_PAK_ENTRIES 2048

typedef struct
{
	char magic[4];
	uint32_t offset;
	uint32_t size;
} pakheader_t;

typedef struct
{
	char name[0x38];
	uint32_t offset;
	uint32_t size;
} pakentry_t;

typedef struct
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} pakpalette_t[256];

typedef struct
{
	char name[256];
	uint32_t handle;
	uint32_t count;
	pakentry_t *data;
} pak_t;


//lmp

typedef struct
{
	uint32_t width;
	uint32_t height;
	uint8_t *data;
} pakpicture_t;

//bsp

typedef struct
{
	uint32_t offset;
	uint32_t size;
} pakbspentry_t;

typedef struct                 // The BSP file header
{
	long  version;               // Model version, must be 0x17 (23).
	pakbspentry_t entities;           // List of Entities.
	pakbspentry_t planes;             // Map Planes.
								 // numplanes = size/sizeof(plane_t)
	pakbspentry_t miptex;             // Wall Textures.
	pakbspentry_t vertices;           // Map Vertices.
								 // numvertices = size/sizeof(vertex_t)
	pakbspentry_t visilist;           // Leaves Visibility lists.
	pakbspentry_t nodes;              // BSP Nodes.
								 // numnodes = size/sizeof(node_t)
	pakbspentry_t texinfo;            // Texture Info for faces.
								 // numtexinfo = size/sizeof(texinfo_t)
	pakbspentry_t faces;              // Faces of each surface.
								 // numfaces = size/sizeof(face_t)
	pakbspentry_t lightmaps;          // Wall Light Maps.
	pakbspentry_t clipnodes;          // clip nodes, for Models.
								 // numclips = size/sizeof(clipnode_t)
	pakbspentry_t leaves;             // BSP Leaves.
								 // numlaves = size/sizeof(leaf_t)
	pakbspentry_t lface;              // List of Faces.
	pakbspentry_t edges;              // Edges of faces.
								 // numedges = Size/sizeof(edge_t)
	pakbspentry_t ledges;             // List of Edges.
	pakbspentry_t models;             // List of Models.
								 // nummodels = Size/sizeof(model_t)
} dheader_t;

//typedef struct
//{
//	int plane_id;
//	short front;
//	short back;
//	bboxshort_t box;
//	short face_id;
//	short face_num;
//} node_t;
//
//typedef struct
//{
//	vec3_t normal;
//	float dist;
//	int type;
//} plane_t;






//typedef struct
//{
//	int		id;				// 0x4F504449 = "IDPO" for IDPOLYGON
//	int		version;		// Version = 6
//	vec3_t	scale;			// Model scale factors.
//	vec3_t	origin;			// Model origin.
//	float	radius;			// Model bounding radius.
//	vec3_t	offsets;		// Eye position (useless?)
//	int		numskins;		// the number of skin textures
//	int		skinwidth;		// Width of skin texture
//	int		skinheight;		// Height of skin texture
//	int		numverts;		// Number of vertices
//	int		numtris;		// Number of triangles surfaces
//	int		numframes;		// Number of frames
//	int		synctype;		// 0= synchron, 1= random
//	int		flags;			// 0 (see Alias models)
//	float	size;			// average size of triangles
//} mdl_t;

int pak_load(char *file_name);
int pak_data(char *file_name, uint8_t **dst);
pakpicture_t *pak_load_pic(char *file_name);