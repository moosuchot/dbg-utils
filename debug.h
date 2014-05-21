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

#include <stdio.h>

/* printf wrap */
#define dprintf(...) printf(__VA_ARGS__)

/* detail debug info printf */
#define ddprintf(...) { \
		dprintf("%s:%d in %s() ", __FILE__, __LINE__, __FUNCTION__); \
		dprintf(__VA_ARGS__);}

/* struct info dump */
#define structinfo(ptr, name) \
		dprintf("%s@%p (%lu bytes) = \n", #name, (ptr), sizeof(*(ptr)))

#define structdump1(ptr, field) { \
		dprintf(".%s (%lu bytes) = \n", #field, sizeof((ptr)->field)); \
		memdump(NULL, &((ptr)->field), sizeof((ptr)->field));}

#define structdump2(ptr, field, ...) { \
		structdump1((ptr), field); \
		structdump1((ptr), __VA_ARGS__);}

#define structdump3(ptr, field, ...) { \
		structdump1((ptr), field); \
		structdump2((ptr), __VA_ARGS__);}

#define structdump4(ptr, field, ...) { \
		structdump1((ptr), field); \
		structdump3((ptr), __VA_ARGS__);}

#define structdump5(ptr, field, ...) { \
		structdump1((ptr), field); \
		structdump4((ptr), __VA_ARGS__);}

#define structdump6(ptr, field, ...) { \
		structdump1((ptr), field); \
		structdump5((ptr), __VA_ARGS__);}
/* add more definition to support more fields */

/* Dump memory of sturct's fields
 * @ptr:	pointer to a structure's instance
 * @name:	structure's type name
 * @num:	number of fields
 * @...:	fields' names
 * 
 * Notes: number of fields is limited, you need to add more definition of 
 * structdump?(ptr, field, ...) to support large numbers
 */
#define structdump(ptr, name, num, ...) { \
		structinfo(ptr, name); \
		structdump##num(ptr, __VA_ARGS__);}

/* Memory info dump */ 
void memdump(const char*, void* const, size_t);
