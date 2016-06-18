// hdlccrc8.h

// This module provides 8-bit CRC used to check the integrity
// of messages passed over the HDLC/RS-485 bus.  The CRC is
// defined in the ISO HDLC document.

#if !defined( HDLCCRC8_H )
#define HDLCCRC8_H

typedef unsigned char	BYTE;
typedef unsigned int	WORD;
typedef unsigned long	DWORD;


// Call this routine before starting a CRC calculation
//
void HdlcCrc8Initialize(void);

// Call this routine to add a byte to the CRC calculation
//
void HdlcCrc8AddByte(BYTE newByte);

// Call this routien to retrieve the result of a CRC
// calculation.
//
BYTE HdlcCrc8Get(void);

// Call this routine to calculate a CRC on a block of memory.
//
BYTE HdlcCrc8(BYTE* inStart, WORD inSize);

#endif // HDLCCRC8_H

