// hdlccrc8.c

// CRC8 calculation

#include "hdlccrc8.h"

static BYTE hdlccrc8;

BYTE HdlcCrc8Get(void)
{
   return hdlccrc8;
}

void HdlcCrc8Initialize(void)
{
   hdlccrc8 = 0xFF;
}

void HdlcCrc8AddByte(BYTE crc8temp)
{
   crc8temp ^= hdlccrc8;
   hdlccrc8 = 0;
   if (crc8temp & 0x80)
   {
      hdlccrc8 ^= 0x80;
      crc8temp ^= 0x83;
   }
   if (crc8temp & 0x40)
   {
      hdlccrc8 ^= 0xC0;
      crc8temp ^= 0x41;
   }
   if (crc8temp & 0x20)
   {
      hdlccrc8 ^= 0xE0;
      crc8temp ^= 0x20;
   }
   if (crc8temp & 0x10)
   {
      hdlccrc8 ^= 0x70;
      crc8temp ^= 0x10;
   }
   if (crc8temp & 0x08)
   {
      hdlccrc8 ^= 0x38;
      crc8temp ^= 0x08;
   }
   if (crc8temp & 0x04)
   {
      hdlccrc8 ^= 0x1C;
      crc8temp ^= 0x04;
   }
   if (crc8temp & 0x02)
   {
      hdlccrc8 ^= 0x0E;
      crc8temp ^= 0x02;
   }
   if (crc8temp & 0x01)
      hdlccrc8 ^= 0x07;
}

// This routine just wraps the others up if all you want to do is
// CRC a block of memory.

BYTE HdlcCrc8(BYTE* inStart, WORD inSize)
{
   WORD i;

   HdlcCrc8Initialize();
   for (i = 0; i < inSize; ++i)
   {
      //lint -e{661,662}  out-of-bounds access
      HdlcCrc8AddByte(inStart[i]);
   }
   return hdlccrc8;
}

