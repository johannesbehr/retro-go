/*
** Nofrendo (c) 1998-2000 Matthew Conte (matt@conte.com)
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of version 2 of the GNU Library General
** Public License as published by the Free Software Foundation.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Library General Public License for more details.  To obtain a
** copy of the GNU Library General Public License, write to the Free
** Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** Any permitted reproduction of these routines, in whole or in part,
** must bear this legend.
**
**
** nes_rom.h
**
** NES ROM loading/saving related defines / prototypes
** $Id: nes_rom.h,v 1.2 2001/04/27 14:37:11 neil Exp $
*/

#ifndef _NES_ROM_H_
#define _NES_ROM_H_

#define  ROM_INES_MAGIC       "NES\x1A"

#define  ROM_FLAG_FOURSCREEN  0x08
#define  ROM_FLAG_TRAINER     0x04
#define  ROM_FLAG_BATTERY     0x02
#define  ROM_FLAG_VERTICAL    0x01
#define  ROM_FLAG_VERSUS      0x100 // non-ines flags

#define  TRAINER_OFFSET    0x1000
#define  TRAINER_LENGTH    0x200

#define  ROM_BANK_LENGTH   0x4000
#define  VROM_BANK_LENGTH  0x2000
#define  SRAM_BANK_LENGTH  0x0400
#define  VRAM_BANK_LENGTH  0x2000

typedef struct
{
   uint8 ines_magic[4];
   uint8 rom_banks;
   uint8 vrom_banks;
   uint8 rom_type;
   uint8 mapper_hinybble;
   uint32 reserved1;
   uint32 reserved2;
} inesheader_t;

typedef struct
{
   inesheader_t header;

   /* pointers to ROM and VROM */
   uint8 *rom, *vrom;

   /* SRAM and vram are not iNES header-defined, always alloc them */
   uint8 vram[1 * 0x2000];
   uint8 sram[8 * 0x400];

   /* number of banks */
   int rom_banks, vrom_banks;
   int sram_banks, vram_banks;

   int mapper_number;

   uint16 flags;

   char filename[PATH_MAX + 1];
   uint32 checksum;
} rom_t;


extern rom_t *rom_load(const char *filename);
extern void rom_free(rom_t *rominfo);

#endif /* _NES_ROM_H_ */
