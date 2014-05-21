/* C helping function for debug 
 *
 * Copyright (C) 2014 Weihong,Xu <xuweihong.cn@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/* memory info dump */ 

# include "debug.h"

/* Memory info dump
 * @tag:	tag for printing info, set NULL to ignore
 * @ptr:	starting address of memory
 * @size:	size of memory
 */ 
void memdump(const char* tag, void* const ptr, size_t size)
{

	int i = 0;
	unsigned char buff[16 + 1];	//length of a line
	unsigned char *pc = (unsigned char*)ptr;

	if (tag)
		dprintf("%s\n", tag);

	while (i < size) {
		/* print offset at every line's head */
		if ((i % 16) == 0)
			dprintf("%04x: ", i);
		/* print hex */
		dprintf("%02x ", pc[i]);
		/* print hex as char */
		buff[i % 16] = ((pc[i] < 0x20) || (pc[i] > 0x7e)) ? \
			       '.' : pc[i];	
		buff[(i % 16) + 1] = '\0';
		i++;
		/* 
		 * print ascii string at every line's tail or
		 * reaching memory end
		 */
		if (i % 16 == 0)
			dprintf("  %s\n", buff); 
		else if (i == size) { 
			/* padding space for alignment */
			while ((i++ % 16)) dprintf("   ");
			dprintf("  %s\n", buff);
		}
	}
}
