#include <stdint.h>
#include "draw.h"

void draw_character(int x, int y, int num)
{
	uint8_t *dest, *source;
	uint16_t *pusdest;
	int	drawline, row, col;

	num &= 255;

	if (y <= -8) return;

	row = num >> 4;
	col = num & 15;
	//source = draw_chars + (row << 10) + (col << 3);

	//if (y < 0)
	//{	// clipped
	//	drawline = 8 + y;
	//	source -= 128 * y;
	//	y = 0;
	//}
	//else
	//	drawline = 8;


	//if (r_pixbytes == 1)
	//{
	//	dest = vid.conbuffer + y*vid.conrowbytes + x;

	//	while (drawline--)
	//	{
	//		if (source[0])
	//			dest[0] = source[0];
	//		if (source[1])
	//			dest[1] = source[1];
	//		if (source[2])
	//			dest[2] = source[2];
	//		if (source[3])
	//			dest[3] = source[3];
	//		if (source[4])
	//			dest[4] = source[4];
	//		if (source[5])
	//			dest[5] = source[5];
	//		if (source[6])
	//			dest[6] = source[6];
	//		if (source[7])
	//			dest[7] = source[7];
	//		source += 128;
	//		dest += vid.conrowbytes;
	//	}
	//}
	//else
	//{
	//	// FIXME: pre-expand to native format?
	//	pusdest = (unsigned short *)
	//		((byte *)vid.conbuffer + y*vid.conrowbytes + (x << 1));

	//	while (drawline--)
	//	{
	//		if (source[0])
	//			pusdest[0] = d_8to16table[source[0]];
	//		if (source[1])
	//			pusdest[1] = d_8to16table[source[1]];
	//		if (source[2])
	//			pusdest[2] = d_8to16table[source[2]];
	//		if (source[3])
	//			pusdest[3] = d_8to16table[source[3]];
	//		if (source[4])
	//			pusdest[4] = d_8to16table[source[4]];
	//		if (source[5])
	//			pusdest[5] = d_8to16table[source[5]];
	//		if (source[6])
	//			pusdest[6] = d_8to16table[source[6]];
	//		if (source[7])
	//			pusdest[7] = d_8to16table[source[7]];

	//		source += 128;
	//		pusdest += (vid.conrowbytes >> 1);
	//	}
	//}
}